
void layout1()
{
	//  to first yellow block
  /////////////////////////////////////////////////////////////////////////////////
			robotHeading = 0;


			liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);

			//driveStraight(0.43, robotHeading, 0.21, 0.005, 0.03);


			robotHeading = 450;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveStraight(0.1, robotHeading, -0.19, 0.005, 0.03);

			strafeStraight(0.3, robotheading, -35, 0.4);
			wait1Msec(10);
			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1Msec(10);
			followLinePickUpBlock();
			//shoul dhave the yelow block
			wait1Msec(10);

			driveStraight(0.24, robotHeading, -0.23, 0.005, 0.03);

			strafeStraight(0.4, robotHeading, -35, 0.4);

				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			//driveStraight(0.2, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();


			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 1350;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveStraight(0.13, robotHeading, -0.2, 0.005, 0.03);
			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1Msec(10);
			followLinePickUpBlock();
			//should have the blue blcok now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.4, robotHeading, -35, 0.4);

				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			driveStraight(0.1, robotHeading, -0.17, 0.005, 0.03);
			dropOffBlock();

			//should be going for the first red one now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			robotHeading = 2250;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.1, robotHeading, -0.18, 0.005, 0.03);

			strafeStraight(0.15, robotHeading, -38, 0.4);
			wait1Msec(50);
			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1Msec(10);
			followLinePickUpBlock();

			//should have the red block in claw

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.35, robotHeading, -37, 0.4);
			wait1Msec(50);



					sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			driveStraight(0.1, robotHeading, -0.18, 0.005, 0.03);
			dropOffBlock();

			//should go for the second blue one now
			driveStraight(0.4, robotHeading, -0.2, 0.005, 0.03);

			robotHeading = 1350;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveWheels(-33, -33);
			wait10Msec(320);
			driveWheels(0,0);
			wait10Msec(200);

			angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800
			robotHeading = 1350 + angleOffset;

			driveStraight(0.52, robotHeading, 0.2, 0.005, 0.03);

				strafeToBlack(34, robotHeading, 0.1, LIGHT_RIGHT);

			wait1Msec(50);

		/*	strafeStraight(0.2, robotHeading, 38, 0.4);
			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1MSec(50);*/
			followLinePickUpBlock();
			//shoul dhave the second blue in the claw now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.5, robotHeading, -42, 0.4);
			driveStraight(0.85, robotHeading, 0.2, 0.005, 0.03);

					sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			driveStraight(0.2, robotHeading, 0.18, 0.005, 0.03); //this was 0.17, consider changing it
			dropOffBlock();
			//shoul dhave delivered the second blue, now go for the yellow

			driveStraight(0.18, robotHeading, -0.18, 0.005, 0.03);//this was 0.15, consider changingi it

			robotHeading = 150 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.32, robotHeading, 0.18, 0.005, 0.03);

			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1Msec(50);
			followLinePickUpBlock();
			//shoudl have the second yellow now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			//going to yellow now
			robotHeading = 450 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.35, robotHeading, -36, 0.4);

			driveStraight(0.9, robotHeading, 0.2, 0.005, 0.03);



					sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			driveStraight(0.1, robotHeading, 0.18, 0.005, 0.03);
			dropOffBlock();
			//should have dropped it off
			driveStraight(0.17, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.3, robotHeading, 37, 0.4);


			robotHeading = 2550 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeToBlack(-32, robotHeading, 0.1, LIGHT_LEFT);
			//wait1Msec(50);
			followLinePickUpBlock();
			//should have the red cube now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 2250 + angleOffset;
			turnGYro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.95, robotHeading, -38, 0.4);

			driveStraight(0.75, robotHeading, 0.2, 0.005,0.03);

						sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.24) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.24) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.24),robotHeading,42,0.7);
		  }
			driveStraight(0.25, robotHeading, 0.18, 0.005, 0.03);//once was 0.12, now changed
			dropOffBlock();



			//should be done right noq
			driveStraight(0.3, robotHeading, -0.3, 0.005, 0.03);






}
