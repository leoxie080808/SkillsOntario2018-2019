
void layout4()
{
	//  to first yellow block
  /////////////////////////////////////////////////////////////////////////////////
			robotHeading = 0;

			strafeStraight(0.1,robotHeading,32,0.6);
			// move back
		/*	driveStraight(0.12, robotHeading, -0.2,0.005,0.03);		// dis, angle, speed, kp, momentum


			wait1Msec(20);

			strafeStraight(0.5,robotHeading,50,0.6);
			robotHeading = -455;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			*/
			liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);

			driveStraight(0.73, robotHeading, 0.21, 0.005, 0.03);



			strafeToBlack(-32,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			driveStraight(0.14, robotHeading, -0.12, 0.005, 0.03);
			strafeStraight(0.8, robotHeading, -35, 0.5);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);



			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.07) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.07),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.07) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.07),robotHeading,-42,0.7);
		  }

			driveStraight(0.55, robotHeading, 0.18, 0.005, 0.03);
		  dropOffBlock();
		  driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
		  //droped off first yellow, getting the secodn
		  strafeStraight(0.3, robotHeading, -35, 0.5);
		  driveStraight(1.15, robotHeading, 0.21, 0.005, 0.03);
		  strafeStraight(0.45, robotHeading, -35, 0.5);

		  wait1Msec(50);

			strafeToBlack(-32,robotHeading,0.1, LIGHT_LEFT);
			wait1Msec(50);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.18, 0.005, 0.03);
			strafeStraight(0.6, robotHeading, 37, 0.5);

			robotHeading = 0;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

				sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.08) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.08),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.08) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.08),robotHeading,42,0.7);
		  }
			driveStraight(0.51, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
			//droped the secodn one, now get another colour cube

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(1.6, robotHeading, 0.23, 0.005, 0.03);

			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			wait1MSec(50);
			followLinePickUpBlock();

			//first red in calw
			driveStraight(1.32, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			//need another 5- to 60 cm

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
			driveStraight(0.32, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			wait1Msec(50);
			//dropped the first red, getting the blue now
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(1.1, robotHeading, 0.21, 0.005, 0.03);

			strafeStraight(0.3, robotHeading, -35, 0.5);
			wait1Msec(50);
			strafeToBlack(-35, robotHeading, 0.1, LIGHT_LEFT);
			wait1MSec(50);
			followLinePickUpBlock();

			//blue cube in claw
			driveStraight(0.3, robotHeading, -0.2, 0.005, 0.03);
			//robotHeading = 450;
			//turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			//driveStraight(1.2,robotHeading, 0.2, 0.005, 0.03);
		/*			sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.62) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.62),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.62) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.62),robotHeading,42,0.7);
		  }
		//	driveStraight(0.51, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
		*/


		robotHeading = 900;
		turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
		strafeStraight(0.9, robotHeading, 35, 0.4);
		driveStraight(1.25, robotHeading, 0.22, 0.005, 0.03);

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
			driveStraight(0.15, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
			//dropped the blue

			driveStraight(0.23, robotHeading, -0.18, 0.005, 0.03);
			robotHeading = 1800;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			 wait10Msec(50);
		  driveWheels(-33,-33);
		  wait10Msec(350);		// 3 second
		  driveWheels(0,0);
		  wait10Msec(200);		// 2 second
		  angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800

			robotHeading = 1800 + angleOffset;
			driveStraight(0.25, robotHeading, 0.22, 0.005, 0.03);

			robotHeading = 2700+angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.7, robotHeading, 0.23, 0.005, 0.03);

					sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.35) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.35),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.35) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.35),robotHeading,42,0.7);
		  }
			driveStraight(0.35, robotHeading, 0.2, 0.005, 0.03);
			strafeStraight(0.32, robotHeading, 35, 0.5);
			wait1Msec(50);
				strafeToBlack(33, robotHeading, 0.1, LIGHT_RIGHT);
			wait1MSec(50);
			followLinePickUpBlock();

			//should have gotten the second blue now

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 900+angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.25, robotHeading, 38, 0.5);

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
			driveStraight(1, robotHeading, 0.18, 0.005, 0.03);

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
		  driveStraight(0.31, robotHeading, 0.17, 0.005, 0.03);
		  dropOffBlock();

		  //should go for the last red now

		  driveStraight(0.23, robotHeading, -0.23, 0.005, 0.03);
		  strafeStraight(0.3, robotHeading, -38, 0.4);

		 robotHeading = 2700 + angleOffset;
		 turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

		 driveStraight(0.95, robotHeading, 0.23, 0.005, 0.03);
		 wait1Msec(50);
				strafeToBlack(-33, robotHeading, 0.1, LIGHT_LEFT);
			wait1MSec(50);
			followLinePickUpBlock();

			driveStraight(0.6, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(1.6, robotHeading, 40, 0.5);

			robotHeading = 900+angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);


						sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.2),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,42,0.7);
		  }

			driveStraight(0.9, robotHeading, 0.23, 0.005, 0.03);
			dropOffBlock();

			driveStraight(0.3, robotHeading, -0.3, 0.005, 0.03);





			//160




			/*


			driveStraight(0.2, robotHeading, -0.15, 0.005, 0.03);
			robotHeading = -900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveStraight(1.15, robotHeading, 0.2, 0.005, 0.03);
			strafeStraight(0.3, robotHeading, 35, 0.5);
				wait1Msec(50);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			wait1MSec(50);
			followLinePickUpBlock();
			//should have gotten the second blue by now
			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 900;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.25, robotHeading, 38, 0.5);

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
			driveStraight(1, robotHeading, 0.18, 0.005, 0.03);

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
		  driveStraight(0.31, robotHeading, 0.17, 0.005, 0.03);
		  dropOffBlock();

		  //need to get final red now

		  driveStraight(0.9, robotHeading, -0.25, 0.005, 0.03);
		  robotHeading = 1800;
		  turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

		  wait10Msec(50);
		  driveWheels(-33,-33);
		  wait10Msec(350);		// 3 second
		  driveWheels(0,0);
		  wait10Msec(200);		// 2 second
		  angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800

			robotHeading = 1800 - angleOffset;

			driveStraight(0.25, robotHeading, 0.2, 0.005, 0.03);

			robotHeading = 2700- angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.37, robotHeading, 0.2, 0.005, 0.03);

				wait1Msec(50);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			wait1MSec(50);
			followLinePickUpBlock();

			driveStraight(0.5, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 900-angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveStraight(0.5, robotHeading, 0.2, 0.005, 0.03);

			*/














}
