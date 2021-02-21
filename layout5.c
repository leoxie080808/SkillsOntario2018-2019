
void layout5()
{
	//  to first yellow block
  /////////////////////////////////////////////////////////////////////////////////
			robotHeading = 0;
			// move back
			driveStraight(0.12, robotHeading, -0.2,0.005,0.03);		// dis, angle, speed, kp, momentum


			wait1Msec(20);

			strafeStraight(0.5,robotHeading,50,0.6);
			robotHeading = -455;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);

			liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);

			strafeToBlack(35,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();


			/*liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);
			robotHeading = -485;
			turnGyro(robotHeading, 0.4, 0.1,100, 10,40,0);
			driveStraight(0.55, robotHeading, 0.2, 0.005, 0.03);

			wait10Msec(21);
			strafeToBlack(38,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
			*/

			driveStraight(0.6, robotHeading, -0.15, 0.005, 0.03);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.3, 0.1, 100, 10, 40, 0);
			wait1MSec(50);
			strafeStraight(0.75,robotHeading,40,0.6);



			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.75) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.75) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,-42,0.7);
		  }
		  //driveStraight(0.03, robotHeading, 0.2, 0.005, 0);


		  driveStraight(0.35, robotheading, 0.2, 0.005, 0.03);
		  dropOffBlock();
		  //going to get second blue
		  wait1MSec(50);
		  driveStraight(0.32, robotHeading, -0.2, 0.005, 0.03);
		  robotHeading = -3160;
		  turnGyro(robotHeading, 0.3, 0.1, 100, 10, 40, 0);
		  driveStraight(0.4, robotHeading, 0.2, 0.005, 0.03);
		  wait1Msec(50);
		  strafeToBlack(-38,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			wait1Msec(100);
			driveStraight(0.3, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.35, 0.1, 100, 10, 40, 0);
			driveStraight(0.1, robotHeading, 0.15, 0.005, 0.03);

			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.75) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.75) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,-42,0.7);
		  }

		  driveStraight(0.44, robotHeading, 0.15, 0.005, 0.03);
		  dropOffBlock();
		  //delivered the 2nd blue, now for red

		  driveStraight(0.2, robotHeading, -0.16, 0.005, 0.03);
		  robotHeading = -2700;
		  turnGyro(robotHeading, 0.35, 0.1, 100, 10, 40, 0);
		  driveStraight(0.4, robotHeading, 0.2, 0.005, 0.03);

			strafeToBlack(-35,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			//got the first red cube, now moving
			driveStraight(0.2, robotHeading, -0.15, 0.005, 0.03);
			strafeStraight(0.45,robotHeading,50,0.6);
		  driveStraight(1.2, robotHeading, -0.15, 0.005, 0.03);


			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.75) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.75) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.75),robotHeading,-42,0.7);
		  }
			strafeStraight(0.32,robotHeading,-50,0.6);

			dropOffBlock();
			//delivered first red, now getting secdon

			driveStraight(0.1, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.3,robotHeading,-33,0.6);
			robotHeading = -900;
			turnGyro(robotHeading, 0.37, 0.1, 100, 10, 40, 0);
			driveStraight(0.1, robotHeading, 0.2, 0.005,0.03);

			strafeToBlack(-35,robotHeading,0.1, LIGHT_LEFT);
			followLinePickUpBlock();

			//second red cube in claw

			driveStraight(0.16, robotHeading, -0.15, 0.005, 0.03);
			robotHeading = -2700;
			turnGyro(robotHeading, 0.37, 0.1, 100, 10, 40, 0);
			driveStraight(0.26, robotHeading, 0.18, 0.005, 0.03);
			strafeStraight(0.05, robotHeading, -32, 0.6);

			dropOffBlock();

			//second red done
			driveStraight(0.24, robotHeading, -0.2, 0.005, 0.3);
			robotHeading = -1800;
			turnGyro(robotHeading, 0.37, 0.1, 100, 10, 40, 0);
			driveStraight(0.47, robotHeading, 0.15, 0.005, 0.03);

			robotHeading = -1340;
			turnGyro(robotHeading, 0.37, 0.1, 100, 10, 40, 0);
			strafeToBlack(35,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
			//yellow cuve in claw
			driveStraight(0.25, robotHeading, -0.15, 0.005, 0.03);

			robotHeading = -2700;
			turnGyro(robotHeading, 0.37, 0.1, 100, 10, 40, 0);

			// go to the wall
		  wait10Msec(50);
		  driveWheels(-33,-33);
		  wait10Msec(350);		// 3 second
		  driveWheels(0,0);
		  wait10Msec(200);		// 2 second
		  angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800

			robotHeading = -2700 + angleOffset;



			driveStraight(0.4, robotHeading, 0.2, 0.005, 0.03);





			sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.55) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.55),robotHeading,-42,0.7);
		  }
		  else if ((sonarReading - 0.55) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.55),robotHeading,42,0.7);
		  }
		  driveStraight(0.42, robotHeading, 0.18, 0.005, 0.03);
			dropOffBlock();
			//yellow cube in square, now get the final eone

			driveStraight(0.16, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.3,robotHeading,-35,0.6);

			driveStraight(0.97, robotHeading, 0.2, 0.005, 0.03);
			robotHeading = -2250 + angleOffset;
			turnGyro(robotHeading, 0.31, 0.1, 100, 10, 40, 0);
			strafeToBlack(35,robotHeading,0.1, LIGHT_RIGHT);
			followLinePickUpBlock();

			driveStraight(0.3, robotHeading, -0.15, 0.005, 0.03);

			robotHeading = -900 + angleOffset;
			turnGyro(robotHeading, 0.31, 0.1, 100, 10, 40, 0);

			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.5) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.5),robotHeading,42,0.7);
		  }
		  else if ((sonarReading - 0.42) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.5),robotHeading,-42,0.7);
		  }
			driveStraight(0.45, robotHeading, 0.2, 0.005, 0.03);
			dropOffBlock();

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);




}
