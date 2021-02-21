
void layout6()
{
	//  to first yellow block
  /////////////////////////////////////////////////////////////////////////////////
			robotHeading = 0;
			// move back
			driveStraight(0.36, robotHeading, -0.2,0.005,0.03);		// dis, angle, speed, kp, momentum

			liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);
			// h drive to left
			strafeStraight(0.3,robotHeading,-50,0.6);
			// h drive to black line
			wait10Msec(20);
			strafeToBlack(-40,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();

		  //move back
		  driveStraight(1.70, robotHeading, -0.25,0.007,0.03);		// dis, angle, speed, kp, momentum
		  wait10Msec(50);
		  // using the left sonar sensor to make sure the distance is right
		  sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
		  // 0.58 need test
		  strafeStraight(0.36 + 0.58 - sonarReading,robotHeading,50,1);
		  wait10Msec(50);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			dropOffBlock();
	////////////////////////////////////////////////////////////////////////////////////////////
			//go to first red block
			wait10Msec(50);
			driveStraight(0.2, robotHeading, -0.25,0.007,0.03);
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(0.72, robotHeading, 0.25,0.007,0.03);
			strafeToBlack(-40,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();
		  //move back
		  driveStraight(0.40, robotHeading, -0.25,0.01,0.03);		// dis, angle, speed, kp, momentum
		  wait10Msec(50);

			robotHeading = -1800;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(0.44, robotHeading, 0.25,0.007,0.03);

			dropOffBlock();
/////////////////////////////////////////////////////////////////////////////////////////
			// go to second yellow
			driveStraight(0.8, robotHeading, -0.25,0.007,0.03);
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,30,0);
			driveStraight(0.11, robotHeading, -0.25,0.007,0.03);

			// h drive to left 0.2
			strafeStraight(0.20,robotHeading,-50,0.8);

			wait10Msec(20);
			strafeToBlack(-40,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();
		  //move back
		  driveStraight(0.63, robotHeading, -0.25,0.006,0.03);		// dis, angle, speed, kp, momentum
		  wait10Msec(50);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(1.04, robotHeading, 0.25,0.006,0.03);
			dropOffBlock();
/////////////////////////////////////////////////////////////////////////////////////////
			// go to first blue
			driveStraight(1.40, robotHeading, -0.25,0.007,0.03);
			robotHeading = 0;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);

			strafeStraight(0.35,robotHeading,40,0.5);
			// h drive to black line
			wait10Msec(20);
			strafeToBlack(40,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
		  driveStraight(0.15, robotHeading, -0.25, 0.005, 0);
		  strafeStraight(0.85,robotHeading,-40,0.6);
		  strafeToBlack(-40,robotHeading,0.7, LIGHT_LEFT);

		  robotHeading = -1800;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(1.45, robotHeading, 0.25, 0.005, 0);
			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200;
		  if ((sonarReading - 0.56) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.56),robotHeading,40,0.7);
		  }
		  else if ((sonarReading - 0.56) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.56),robotHeading,-40,0.7);
		  }
		  // go to the wall
		  wait10Msec(50);
		  driveWheels(40,40);
		  wait10Msec(200);		// 2 second
		  driveWheels(0,0);
		  wait10Msec(200);		// 2 second
		  angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800

			robotHeading = -1800 + angleOffset;
			driveStraight(0.18, robotHeading, -0.2, 0, 0);

			// lower the claw
			dropOffBlock();
//////////////////////////////////////////////////////////////////////////////////////
			//got to second blue
			driveStraight(0.2, robotHeading, -0.2, 0.005, 0);

			robotHeading = -2700 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(0.15, robotHeading, 0.2, 0.005, 0);
			strafeToBlack(40,robotHeading,0.1, LIGHT_RIGHT);

			followLinePickUpBlock();
		  //move back
		  driveStraight(0.40, robotHeading, -0.25,0.006,0.03);		// dis, angle, speed, kp, momentum
		  wait10Msec(50);
		  robotHeading = -1800 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(0.32, robotHeading, 0.25, 0.005, 0);
			dropOffBlock();
/////////////////////////////////////////////////////////////////////////////////////////
			//go to second red
			driveStraight(0.92, robotHeading, -0.2, 0.005, 0);
			strafeStraight(0.03,robotHeading,-50,0.8);
			robotHeading = -2700 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			strafeToBlack(40,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
			driveStraight(1.0, robotHeading, -0.25, 0.005, 0);
		  robotHeading = -1800 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(1.0, robotHeading, 0.25, 0.005, 0);
			sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.60) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.60),robotHeading,-40,0.7);
		  }
		  else if ((sonarReading - 0.60) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.60),robotHeading,40,0.7);
		  }
		  driveStraight(0.03, robotHeading, 0.2, 0.005, 0);

			dropOffBlock();
			driveStraight(0.3, robotHeading, -0.25, 0.0, 0);

}
