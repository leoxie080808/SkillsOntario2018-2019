#define CLAW_RESET  2710
#define CLAW_OPEN  1870
#define CLAW_HOLD  2710

float clawKp = 0.001;
float clawKi = 0;
float clawKd = 0;
Pid pidClawCtrl;


int clawCmd = 0;
int clawTarget = 0;
int clawFlag = 0;		// 0 means close,

task clawCtrlTask(){
	newPid(pidClawCtrl, clawKp, clawKi,clawKd, clawTarget);

	while(1){
		update(pidClawCtrl, SensorValue[clawPos]);
		clawCmd = -pidClawCtrl.controlVariable;

//		writeDebugStreamLine(" sensorVlaue = %d, contorl cmd = %d", SensorValue[clawPos], clawCmd);
		motor[claw]= clawCmd;
		wait1Msec(10);
	}
}

void clawOpen()
{
	setKp(pidClawCtrl, 0.5);
	setSetpoint(pidClawCtrl, CLAW_OPEN);

}

void clawHold()
{
	setKp(pidClawCtrl, 0.001);
	setSetpoint(pidClawCtrl,CLAW_HOLD);
}

void clawClose()
{
	setKp(pidClawCtrl, 0.001);
	setSetpoint(pidClawCtrl, CLAW_RESET);
}


void liftCtrl( int power)
{
	motor[liftOne] = power;
	motor[liftTwo] = power;
	int delayCnt = 0;
	if (power > 0)
	{

		while(SensorValue[elevatorTop] == 0){}
	}
	else
	{
		while(SensorValue[elevatorDown] == 0){
			//here in case sth block the lift down
			delayCnt ++;
			if (delayCnt > 20)		//20 * 10 * 10 = 2 second
			{
				delayCnt = 0;
				break;
			}
			wait10Msec(10);
		}
	}
	motor[liftOne] = 0;
	motor[liftTwo] = 0;
}
