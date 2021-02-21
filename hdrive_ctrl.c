#define STRAFE_TASK_PRI				7
#define STRAFE_TASK_PERIOD    10  //10ms control period
#define CIRCLE_COUNT_TWO			360

int strafeStraightSpeed = 100;
float strafeDistance = 0;
float strafeSetDistance = 0;
int strafeStartFlag = 0;
int strafeAngle = 0;
int lastTopEncoder = 0;
int lastBackEncoder = 0;
float strafeKp = 0;
float strafeKi = 0;
float strafeKd =0;
float strafeSonarDis = 10;
int sensorUse = 0;

float sonarReading = 0;

Pid pidStrafeCtrl;


void strafeWheels(float topCmd, float backCmd)
{
	motor[center] = (int)topCmd; //this here need testing
	motor[centerTwo] = (int)backCmd;//not sure which wheel is forward
}

task strafeGyroControlTask()
{
	int topCmd = 0; //need to test and see which wheel is which
	int backCmd = 0;
	int deltaTop = 0;
	int deltaBack = 0;
	newPid(pidStrafeCtrl, strafeKp, strafeKi, strafeKd, strafeAngle);
	strafeDistance = 0;
	while(strafeStartFlag ==1){
		update(pidStrafeCtrl, gyroAngle);
		topCmd = strafeStraightSpeed - pidStrafeCtrl.controlVariable;
		backCmd = strafeStraightSpeed + pidStrafeCtrl.controlVariable;

		//writeDebugStreamLine("angle = %d  pid ctrl = %f",gyroAngle, pidStrafeCtrl.controlVariable);

		deltaTop = abs(SensorValue[dgtl5]-lastTopEncoder);
		deltaBack = abs(SensorValue[dgtl9]-lastBackEncoder);

		strafeDistance = ((float)(deltaTop + deltaBack)) * PI * WHEEL_RADIUS / CIRCLE_COUNT_TWO;
		if (strafeDistance < strafeSetDistance){
			//keep strafe
			strafeWheels(topCmd, backCmd);
		}
		else{
			//stop motors and task
			strafeWheels(0,0);
			strafeStartFlag = 0;
			writeDebugStreamLine("drive straight done, stop angle = %d dis = %f", gyroAngle, strafeDistance);
		}
		wait1Msec(STRAFE_TASK_PERIOD);
	}
}

void strafeStraight(float distance, float setAngle, int power, float kp){
	strafeSetDistance = distance;
	strafeStraightSpeed = power;
	lastTopEncoder = SensorValue[dgtl5];
	lastBackEncoder = SensorValue[dgtl9];
	strafeKp = kp;
	strafeKi = 0;//ki;
	strafeKd = 0;//kd;
	strafeAngle = setAngle;
	strafeStartFlag = 1;

//	writeDebugStreamLine("go straight forward %d  ", strafeSetDistance);
	startTask(strafeGyroControlTask, STRAFE_TASK_PRI);
	while(strafeStartFlag == 1){

	}
	strafeWheels(0,0);
	strafeStartFlag = 0;
}

task strafeToBlackTask()
{
	int topCmd = 0; //need to test and see which wheel is which
	int backCmd = 0;
	strafeKp = 0.2;
	while(strafeStartFlag)
	{
		if (SensorValue[sensorUse] < BLACK_TH)
		{
			topCmd = strafeStraightSpeed - strafeKp * (strafeAngle - gyroAngle);

			backCmd = strafeStraightSpeed + strafeKp * (strafeAngle - gyroAngle);
			strafeWheels(topCmd, backCmd);
		}
		else
		{
			strafeWheels(0,0);
			strafeStartFlag = 0;
			break;
		}
		wait1Msec(20);
	}
}
void strafeToBlack(float power, float angle, float kp, int sensorIndex)
{
	strafeStraightSpeed = power;
	strafeKp = kp;
	strafeKp = 0.2;
	strafeAngle = angle;
	sensorUse = sensorIndex;
	strafeStartFlag = 1;
	startTask(strafeToBlackTask);
	while(strafeStartFlag == 1){}

}

task strafeToDisTask()
{
	int topCmd = 0; //need to test and see which wheel is which
	int backCmd = 0;
	float disLM = strafeSonarDis - 10;
	if (disLM < 0) disLM = 5;
	while(strafeStartFlag)
	{
		if (strafeStraightSpeed < 0)		// to left side
		{
			if ((SensorValue[leftUltra] < strafeSonarDis) && (SensorValue[leftUltra] > disLM))
			{
				break;
			}
		}
		else
		{
			if ( (SensorValue[rightUltra] < strafeSonarDis) && (SensorValue[rightUltra] > disLM))
			{
				break;
			}
		}

		topCmd = strafeStraightSpeed - strafeKp * (strafeAngle - gyroAngle);

		backCmd = strafeStraightSpeed + strafeKp * (strafeAngle - gyroAngle);
		strafeWheels(topCmd, backCmd);

		wait1Msec(20);
	}
	strafeWheels(0,0);
	strafeStartFlag = 0;
//	writeDebugStreamLine("stop at left = %d right = %d", SensorValue[leftUltra],SensorValue[rightUltra]);
}

void strafeToDis(float power, float angle, float kp, float dis)
{
	strafeSonarDis = dis;
	strafeStraightSpeed = power;
	strafeKp = 0.6; //kp;
	strafeAngle = angle;

	strafeStartFlag = 1;
	startTask(strafeToDisTask);
	while(strafeStartFlag == 1){}
}
