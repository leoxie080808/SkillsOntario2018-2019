#define TURN_TASK_PRI					7
#define TURN_TASK_PERIOD			20	//10ms control period
#define GO_STRAIGHT_TASK_PRI  7
#define GO_STRAIGHT_PERIOD		20   //10ms control period
#define GYRO_RANGE 						7200
#define GYRO_SCALE						138  //138 need calibrate for each gyro
#define TURN_TASK_DEADZONE	  10	 //1 degree
#define TURN_POWER						60
#define TURN_TASK_MOMENTUM		30		//3 degree

//#define DRIVE_DEADZONE				0.00			// cm
#define RE_TURN_TH		2

float robotHeading = 0;
int targetAngle = 0;
int turnTaskStartFlag = 0;
float turnMaxPower = 127;
float turnMinPower = 30;
//float turnKp = 2.0;
//float turnKd = 0.0;
//float turnKi = 0.0;
float turnDeadZone = 10;  // one degree
float turnMomentum = 0;			//
int turnWheelFlag = 0;  // 0 - 2 wheels turn, 1 - left wheel turn 2 - right wheel turn
float slowTurnAngle = 100;

float driveStraightSpeed = 1.0;
float driveSetDistance = 0;
int goStraightStartFlag = 0;
int goStraightAngle = 0;
int startLeftEncoder = 0;
int startRightEncoder = 0;




float goKp = 1.5;


#define WHEEL_RADIUS 					(0.102/ 2)    //(0.102/ 2)		//cm			//need test
#define CIRCLE_COUNT					392  // (360.0 * 60 / 36)   // (60 / 12)
#define MAX_MOVE_SPEED		1.0
#define MIN_MOVE_SPEED1		0.2		// need test
#define MIN_MOVE_SPEED2		0.2		// need test
#define STOP_DISTANCE			0.5
#define GO_SLOWDOWN_RATIO		((float)(MAX_MOVE_SPEED - MIN_MOVE_SPEED2) / STOP_DISTANCE)		// which means the max speed to stop min speed in 0.5m 			// 127 - MIN_MOVE_SPEED
//#define GO_MOMENTUM				0.04
#define SLOW_DRIVE_DIS		0.0			//10cm
#define MIN_PWM     25
#define DEFAULT_PWM_RATIO		50

long velocity_last_time = 0;
float setLeftSpeed = 0;
float setRightSpeed = 0;
int leftPWM = 0;
int rightPWM = 0;
float velKp = 130;

float leftSpeed = 0;
float rightSpeed = 0;

void driveWheels(float leftCmd, float rightCmd)
{
	motor[leftOne] = (int)leftCmd;
	motor[leftTwo] = (int)leftCmd;
	motor[rightOne] = (int)rightCmd;
	motor[rightTwo] = (int)rightCmd;
}

task speedEstimateTask()
{
	long dt = 0;

	int lastLeftEncoder = SensorValue[I2C_2];
	int lastRightEncoder = SensorValue[I2C_1];

	long currentTime = nSysTime;
	int currentLeftEncoder = 0;
	int currentRightEncoder = 0;
	float lastleftVelocity = 0;
	float lastRightVelocity = 0;


	velocity_last_time = nSysTime;

	while(true)
	{
		currentTime = nSysTime;
		dt = currentTime - velocity_last_time;
		currentLeftEncoder = SensorValue[I2C_2];
		currentRightEncoder = SensorValue[I2C_1];

		if (dt > 10)
		{
			leftSpeed = ((float)( currentLeftEncoder - lastLeftEncoder)) / dt;
			leftSpeed = 0.25 * leftSpeed + 0.75 * lastleftVelocity;

			rightSpeed = -(float)(currentRightEncoder - lastRightEncoder) / dt;
			rightSpeed = 0.25 * rightSpeed + 0.75 * lastRightVelocity;
	//		writeDebugStreamLine("left = %f, right = %f" "dt = %f", leftSpeed, rightSpeed, dt);
		}
		lastLeftEncoder = currentLeftEncoder;
		lastRightEncoder = currentRightEncoder;
		velocity_last_time = currentTime;
		lastleftVelocity = leftSpeed;
		lastRightVelocity =  rightSpeed;

		wait1Msec(20);
	}

}


void speedCtrl(float leftVel, float rightVel)
{
	setLeftSpeed = leftVel;
	setRightSpeed = rightVel;
	if (setLeftSpeed != 0)
		{
			leftPWM = sgn(setLeftSpeed) * (MIN_PWM +  DEFAULT_PWM_RATIO * abs(setLeftSpeed)) + velKp * (setLeftSpeed - leftSpeed);
		}
		else
		{
			leftPWM = 0;
		}
		if (setRightSpeed != 0)
		{
			rightPWM = sgn(setRightSpeed) * (MIN_PWM + DEFAULT_PWM_RATIO * abs(setRightSpeed))+ velKp * (setRightSpeed - rightSpeed);
		}
		else
		{
			rightPWM = 0;
		}
		// control here
		driveWheels(leftPWM, rightPWM);
//		writeDebugStreamLine("left Speed = %f, right Speed = %f" "PWM = %d / %d", leftSpeed, rightSpeed, leftPWM, rightPWM);
}




task turnGyroControlTask()
{
	float ctrlValue = 0;
	float error = targetAngle - gyroAngle;
	float slowRatio = 0;
	if (abs(error) > slowTurnAngle)
	{
		slowRatio = (turnMaxPower - turnMinPower) / (abs(error) - slowTurnAngle);
	}

	while(turnTaskStartFlag == 1)
	{
		if (	abs(gyroAngle - targetAngle) < turnDeadZone)
		{
			// finish turn
			//writeDebugStreamLine("current angle = %d targetAngle = %d", SensorValue[gyroSensor1], targetAngle);
			driveWheels(0,0);
			turnTaskStartFlag = 0;
		}
		else{
			error = targetAngle - gyroAngle;
			/*
			//2 wheels turn here
			ctrlValue = turnKp * (targetAngle - SensorValue[gyroSensor1 ] );

			ctrlValue = (abs(ctrlValue) > turnMaxPower? sgn(ctrlValue) * turnMaxPower:ctrlValue);
			ctrlValue = (abs(ctrlValue) < turnMinPower? sgn(ctrlValue) * turnMinPower:ctrlValtargetAtargetAngle
			*/
			if (abs(error) <= slowTurnAngle)
			{
				ctrlValue = sgn(error) * turnMinPower;
			}
			else
			{

				ctrlValue = sgn(error) * (turnMinPower + ( abs(error) - slowTurnAngle) * slowRatio);
			}

			if (turnWheelFlag == 0)
			{
				// 2 wheel turns
				//driveWheels(-ctrlValue,  ctrlValue);
				speedCtrl(-ctrlValue, ctrlValue);

			}
			else if(turnWheelFlag == 1)
			{
				// left wheel turns
				//driveWheels(-ctrlValue, 0);
				speedCtrl(-ctrlValue, 0);
			}
			else if(turnWheelFlag == 2)
			{
				// right wheel turns
				//driveWheels(0, ctrlValue);
				speedCtrl(0, ctrlValue);
			}
		//	writeDebugStreamLine("current angle = %d, ctrlValue = %f",gyroAngle, ctrlValue);
		}
		wait1Msec(TURN_TASK_PERIOD);

	}


}
void turnGyro(float setpoint, float maxPower, float minPower, float slowTurnRange,
					float deadZone, float momentum,int wheelFlag, int timeOut = 18000)
{
	//turnGyro(450, 0.5, 0.1,100, 10,20,0);
	int delayCnt = 0;
	if (setpoint >= gyroAngle)
	{

		targetAngle = setpoint - momentum;

	}else
	{

		targetAngle = setpoint + momentum;
	}

	turnMaxPower = maxPower;
	turnMinPower = minPower;

	turnDeadZone = deadZone;
	turnMomentum = momentum;
	turnWheelFlag = wheelFlag;
	slowTurnAngle = slowTurnRange;

	turnTaskStartFlag = 1;

	startTask(turnGyroControlTask, TURN_TASK_PRI);
	while(turnTaskStartFlag == 1)
	{
		delayCnt ++;
		if (delayCnt > timeOut / 20)
		{

			turnTaskStartFlag = 0;
			break;
		}
		wait1Msec(10);
	}

	stopTask(turnGyroControlTask);
	driveWheels(0,0);
	wait1Msec(300);
	writeDebugStreamLine("end of turn angle = %d", gyroAngle);
}


void turnWithReTry(float setpoint, float maxPower, float minPower, float slowTurnRange,
					float deadZone, float momentum,int wheelFlag, int timeOut, int reTryTime = 2)
{
	int reTryCnt = 0;
	turnGyro(setpoint, maxPower, minPower, slowTurnRange,deadZone,momentum, wheelFlag,timeOut);
	while (abs(setpoint - gyroAngle) >= deadZone)
	{
		reTryCnt ++;
		if (reTryCnt > reTryTime) break;
		turnGyro(setpoint, maxPower, 0.02, 100,deadZone,0, wheelFlag,timeOut);
	}
	writeDebugStreamLine("retry Cnt = %d", reTryCnt);
}

task goStraightGyroControlTask()
{

	int deltaLeft = 0;
	int deltaRight = 0;

	float driveDistance = 0;
	float goSpeed = driveStraightSpeed;

	float leftCmd = 0;
	float rightCmd = 0;
	float GO_SLOWDOWN_DIS = (float)(abs(driveStraightSpeed) - MIN_MOVE_SPEED2) / GO_SLOWDOWN_RATIO;

	float remainDis = 0 ;
	float dynamicKp = goKp;
	float ctrlValue = 0;
	while(goStraightStartFlag == 1){
			remainDis = abs(driveSetDistance - driveDistance);
			if(driveDistance > (driveSetDistance - GO_SLOWDOWN_DIS))
			{

				//start to slow down
			 if (remainDis <= SLOW_DRIVE_DIS)
			 {
			   goSpeed = sgn(goSpeed) * MIN_MOVE_SPEED2;
			 }
			 else
			 {

			 		goSpeed = sgn(driveStraightSpeed) * MIN_MOVE_SPEED2 + sgn(driveStraightSpeed) * (remainDis - SLOW_DRIVE_DIS)  * GO_SLOWDOWN_RATIO;

				 if (abs(goSpeed) < MIN_MOVE_SPEED2)
				 {
				   		goSpeed = sgn(goSpeed) * MIN_MOVE_SPEED2;
				 }
				}

			}
			else
			{
				goSpeed = driveStraightSpeed;
			}
		dynamicKp = abs(goSpeed) * goKp; //(0.1 + 0.9 * abs(goSpeed)) * goKp;
		ctrlValue = dynamicKp * (goStraightAngle - gyroAngle);

		leftCmd = goSpeed - ctrlValue ;
		rightCmd = goSpeed + ctrlValue ;

		//writeDebugStreamLine("current angle = %d current distance = %f, left speed = %f  right speed = %f", gyroAngle, driveDistance, leftCmd, rightCmd);
		deltaLeft = abs(SensorValue[I2C_2] - startLeftEncoder);
		deltaRight = abs(SensorValue[I2C_1] - startRightEncoder);

		driveDistance =  ((float)(deltaLeft + deltaRight) ) * PI * WHEEL_RADIUS / CIRCLE_COUNT;


		if(driveDistance < driveSetDistance){
			//keep drive
			speedCtrl(leftCmd, rightCmd);
		}else{
			//stop motor and the task

			driveWheels(0,0);
			goStraightStartFlag = 0;
		//	writeDebugStreamLine("drive straight done");
		}

		wait1Msec(GO_STRAIGHT_PERIOD);
	}
}


void driveStraight( float distance, float setAngle, float power, float kp, float momentum, int timeOut= 8000)
{
	int delayCnt = 0;
	driveSetDistance = distance;

	if (distance >= momentum)
		driveSetDistance = distance - momentum;			// 1m
	else
		driveSetDistance = distance;


	driveStraightSpeed = power;		//power
	startLeftEncoder = SensorValue[I2C_2];
	startRightEncoder = SensorValue[I2C_1];
	goStraightAngle = setAngle;
	goStraightStartFlag = 1;
	goKp = kp;

	//writeDebugStreamLine("go straight forward %d  ", driveSetDistance);
	startTask(goStraightGyroControlTask, GO_STRAIGHT_TASK_PRI);
	while(goStraightStartFlag == 1)
	{
		delayCnt ++;
		if (delayCnt > timeOut/ 20){


			goStraightStartFlag = 0;
			break;
		}
		wait1Msec(20);
	}
	stopTask(goStraightGyroControlTask);
	driveWheels(0,0);
	wait1Msec(300);
}
