
void layout2()
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

			driveStraight(1.3, robotheading, -0.25, 0.005, 0.03);

				liftCtrl(-60);// will lift up claw
			wait10Msec(100);
			clawTarget = CLAW_RESET;
			startTask(clawCtrlTask);
			liftCtrl(60);// will lift up claw
			wait10Msec(100);
			//just added the above part, you will need to test it to see

			strafeToBlack(33, robotHeading, 0.1, LIGHT_RIGHT);
			followLinePickUpBlock();

			wait1Msec(10);

			driveStraight(0.24, robotHeading, -0.23, 0.005, 0.03);
			robotHeading = 2250;

			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.25, robotHeading, 35, 0.4);

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
			driveStraight(0.17, robotHeading, 0.17, 0.005, 0.03);//doesnt go back enough, was 0.14, consider changing it
			dropOffBlock();
			//has now delivered the first yellow block

			driveStraight(0.18, robotHeading, -0.2,0.005, 0.03);//as of 9:37, after the turn it would hit the cube, since frward fucntion increased, might not need to change, waws 0.18

			robotHeading = 450;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(1, robotHeading, 37, 0.4);
		//	driveStraight(0.2, robotHeading, 0.18, 0.005, 0.03);
			wait1Msec(50);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			wait1Msec(50);
			followLinePickUpBlock();
			//should have the first blue cube now
			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);

			robotHeading = 2250;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);
			strafeStraight(0.3, robotHeading, -36, 0.4);

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
			driveStraight(0.2, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
			//should have delivered the second cube now, off to get another

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 450;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(0.58, robotHeading, -36, 0.4);
			wait1Msec(50);
			strafeToBlack(-32, robotHeading, 0.1, LIGHT_LEFT);
			//wait1Msec(50);
			followLinePickUpBlock();
			//should have the red cube now
			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.55, robotHeading, 37, 0.4);
			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,37,0.5);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-37,0.5);
		  }
			driveStraight(0.9, robotHeading, 0.22, 0.005, 0.03);

				sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.25) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.25),robotHeading,40,0.7);
		  }
		  else if ((sonarReading - 0.25) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.25),robotHeading,-40,0.7);
		  }
			driveStraight(0.26, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();

			//should have delivered the red cube now


				driveStraight(0.16, robotHeading, -0.2, 0.005, 0.03);

			robotHeading = 1350;
			turnGyro(robotHeading, 0.4, 0.1, 100,10, 40, 0);
			driveWheels(-33, -33);
			wait10Msec(250);
			driveWheels(0,0);
			wait10Msec(200);


			angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800
			robotHeading = 1350 + angleOffset;

			driveStraight(1.25, robotHeading, 0.2, 0.005, 0.03);
			robotHeading = 2250 + angleOffset;
			turnGyro(robotHeading,0.4, 0.1, 100, 10, 40, 0);
			driveStraight(0.07, robotHeading, -0.13, 0.005, 0.03);
			strafeToBlack(33, robotHeading, 0.1, LIGHT_RIGHT);
			wait1Msec(50);
			followLinePickUpBlock();
			//should have the second red cube now

				driveStraight(0.18, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 450 + angleOffset;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(1.1, robotHeading, 37, 0.4);

			sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.23) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.23),robotHeading,37,0.7);
		  }
		  else if ((sonarReading - 0.23) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.23),robotHeading,-37,0.7);
		  }
		  driveStraight(0.1, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
			//should have delivered the secodn red cube now
			driveStraight(0.08, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.7, robotHeading, -35, 0.4);//here need testing
			driveStraight(0.3, robotHeading, 0.2, 0.005, 0.03);
			robotHeading = 2250+angleOffset;
			turnGyro(robotHeading, 0.3, 0.1, 100, 10, 40, 0);
			driveStraight(0.1, robotHeading, 0.13, 0.005, 0.03);//was 0.07
				strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
				wait1Msec(50);
			followLinePickUpBlock();
			//should have the blue cube right now


			driveStraight(0.18, robotHeading, -0.18, 0.005, 0.03);



			strafeStraight(0.64, robotHeading, -33, 0.4);//was 0.58, consider changing to be more

			sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-35,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,35,0.7);
		  }


			driveStraight(0.8, robotHeading, 0.2, 0.005, 0.03);

					sonarReading = SensorValue[leftUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[leftUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-38,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,38,0.7);
		  }
			driveStraight(0.22, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();

			driveStraight(1.06, robotHeading, -0.2, 0.005, 0.03);


			//should be going for the last yellow block now
			strafeStraight(0.23, robotHeading, 35, 0.4);
			wait1Msec(50);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			wait1Msec(50);
			followLinePickUpBlock();

			driveStraight(0.2, robotHeading, -0.2, 0.005, 0.03);
			strafeStraight(0.9, robotHeading, 36, 0.4);

				sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
		  sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,38,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-38,0.7);
		  }

			driveStraight(1, robotHeading, 0.17, 0.005, 0.03);


					sonarReading = SensorValue[rightUltra];
		  wait10Msec(50);
			sonarReading = (sonarReading + SensorValue[rightUltra]) /200; // to meter unit and average
			if ((sonarReading - 0.22) > 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,37,0.7);
		  }
		  else if ((sonarReading - 0.22) < 0)
		  {
		  	strafeStraight(abs(sonarReading - 0.22),robotHeading,-37,0.7);
		  }
		 // driveStraight(0.1, robotHeading, 0.15, 0.005, 0.03); // you may need this according to the field
			dropOffBlock();

			driveStraight(0.27, robotHeading, -0.2, 0.005, 0.03); //was 0.22, change it to be more?




			/*


			driveStraight(0.16, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 2250;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(1.08, robotHeading, 38, 0.4);
			wait1Msec(50);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
			//should have the other red cube now

			driveStraight(0.18, robotHeading, -0.2, 0.005, 0.03);
			robotHeading = 450;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			strafeStraight(1.1, robotHeading, 37, 0.4);

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
		  driveStraight(0.13, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();
			//should have delivered the second red cuge now
			//may considering oging for a reset

			driveStraight(0.1, robotHeading, -0.18, 0.005, 0.03);
			strafeStraight(0.62, robotHeading, -40, 0.4);
			driveStraight(0.2, robotHeading, 0.2, 0.005, 0.03);
			robotHeading = 2250;
			turnGyro(robotHeading, 0.4, 0.1, 100, 10, 40, 0);

			driveWheels(-33, -33);
			wait10Msec(400);
			driveWheels(0,0);
			wait10Msec(200);


			angleOffset = gyroAngle - robotHeading;  // robotHeading should be -1800
			robotHeading = 2250 + angleOffset;

			driveStraight(0.45, robotHeading, 0.2, 0.005, 0.03);
			strafeToBlack(35, robotHeading, 0.1, LIGHT_RIGHT);
			followLinePickUpBlock();
			//should have the second blue block

			driveStraight(0.15, robotHeading, -0.2, 0.005, 0.03);

			strafeStraight(0.5, robotHeading, -36, 0.4);

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
			driveStraight(0.92, robotHeading, 0.17, 0.005, 0.03);
			dropOffBlock();

			*/







}
