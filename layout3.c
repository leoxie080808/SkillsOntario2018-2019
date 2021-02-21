
void layout3()
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

			driveStraight(0.43, robotHeading, 0.21, 0.005, 0.03);


			robotHeading = -150;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeToBlack(-35, robotHeading, 0.1, LIGHT_LEFT);
			followLinePickUpBlock();


			//should ahve the first cube now
			driveStraight(0.26, robotHeading, -0.16, 0.005, 0.03);

			robotHeading = 0;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(0.95, robotHeading, 37, 0.4);

			//going to wall now
			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-42,0.7);
		  }
			driveStraight(1.25, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();

			//now dropped the first cube, can go get another one now, maybe anther blue

			driveStraight(0.12, robotHeading, -0.23, 0.005, 0.03);
			robotHeading = 900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.5, robotHeading, 0.23, 0.005, 0.03);

			robotHeading = 1700;

			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeToBlack(30, robotHeading, 0.1, LIGHT_RIGHT);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.12, 0.005, 0.03);

			robotHeading = 0;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.5, robotHeading, 38, 0.4);

			//checking the wall again
				sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-42,0.7);
		  }

			dropOffBlock();
			//got the two blue now, get another

			driveStraight(0.75, robotHeading, -0.25, 0.005, 0.03);
			robotHeading = 900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.25, robotHeading, 0.23, 0.005, 0.03);

			strafeToBlack(30, robotHeading, 0.1, LIGHT_RIGHT);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.17, 0.005, 0.03);


		//has yellow now, going to wall

			strafeStraight(0.3, robotHeading, 36, 0.4);
			driveStraight(0.12, robotHeading, 0.2, 0.005, 0.03);

				sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.09) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.09),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.09) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.09),robotHeading,-42,0.7);
		  }

			driveStraight(0.19, robotHeading, 0.18, 0.005, 0.03);//was 0.24
			dropOffBlock();


			driveStraight(0.15, robotHeading, -0.23, 0.005, 0.03);//was0.2

			//going to get the top red cube

					sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.48) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.48),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.48) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.48),robotHeading,-42,0.7);
		  }
			driveStraight(0.8, robotHeading, 0.2, 0.005, 0.03);




			robotHeading = 1960;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.18, 0.005, 0.03);

			robotHeading = 0;
			turnGyro(robotHeading, 0.4, 0.1,100, 10, 40, 0);
			strafeStraight(0.6, robotHeading, -33, 0.4);
			wait1Msec(50);
			//should have the red cube now
				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,42,0.7);
		  }

			driveStraight(0.2, robotHeading, 0.2, 0.005, 0.03);//was 0.1
			dropOffBlock();
			//has delivered the red cube, now get another


			driveStraight(0.83, robotHeading, -0.24, 0.005, 0.03);//was 0.73
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			//PUT A RESET IN HERE

		//	driveStraight(0.23, robotHeading, -0.19, 0.005, 0.03);
			robotHeading = -900;
			wait10Msec(50);
			driveWheels(-33, -33);
			wait10Msec(320);
			driveWheels(0,0);
			wait10Msec(200);


			angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800


			robotHeading = -900 + angleOffset;
			driveStraight(0.47, robotHeading, 0.2, 0.005, 0.03);

			strafeToBlack(-32, robotHeading, 0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.5, robotHeading, -35, 0.4);
			driveStraight(0.2, robotHeading, 0.2, 0.005, 0.03);

				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.1) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.1),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.1) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.1),robotHeading,42,0.7);
		  }

			driveStraight(0.16, robotHeading, 0.2, 0.005, 0.03);
			dropOffBlock();
			//go for the last red one

			/*
			driveStraight(0.22, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.35, robotHeading,33, 0.4);

			driveStraight(
			*/

			driveStraight(0.21, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(1.5, robotHeading, 37, 0.3);

			driveStraight(0.8 ,robotHeading, 0.2, 0.005, 0.03);

			robotHeading = 150;

			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeToBlack(-35, robotHeading, 0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			//last red cube in claw
			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 0 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(1.03, robotHeading, -37, 0.4);


				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.2),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.2),robotHeading,42,0.7);
		  }

		  driveStraight(0.9, robotHeading, 0.2, 0.005, 0.03);

			sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.25) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.25),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.25) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.25),robotHeading,42,0.7);
		  }
		  driveStraight(0.25, robotHeading, 0.15, 0.005, 0.03);
		  dropOffBlock();

		  driveStraight(0.3, robotHeading, -0.23, 0.005, 0.03);










}
