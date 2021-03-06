
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                   VEX Cortex UART Test
//
// Simple program to test user control over the VEX Cortex UART ports.
//
// 1. The two ports are looped back-to-back.
//
// 2. One port simply outputs characters with hex values 0, 1, 2, ... 255, 0, 1, 2, ...
//
// 3. The "UARTReceive" task grabs the characters from the receive UART and verifies that they are
//    in the above sequence.
//
// Various peg counts are used to accumulate total characters transmitted, received and "out of
// sequence" counts. These can be viewed in the ROBOTC debugger.
//
// NOTE: Internally the firmware uses interrupt handlers to buffer the characters transmitted and
//       received. The buffers are about 25 characters in length. If user program does not extract
//       the characters fast enough the older characters are simply discarded.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task UARTReceive();

int  nRcvIndex = 0;
long nTotalXmitChars = 0;
long nTotalRcvChars = 0;
long nTotalRcvOutOfSequence = 0;

int rcvChar;
unsigned char rcvChars[23];  // Keep buffer of last 23 characters received.
float gyroAngle = 0;
int comCnt = 0;
void initUart()
{
  // Setup the two UART ports

  //configureSerialPort(uartOne, uartUserControl);
  //configureSerialPort(uartTwo, uartUserControl);
  setBaudRate(UART1, baudRate115200);


  startTask(UARTReceive);
/*
  while (true)
  {
   writeDebugStreamLine("gyro angle = %d", gyroAngle);
   wait1Msec(10);
  }*/
}


task UARTReceive()
{
	nRcvIndex = 0;
	comCnt = 0;
  while (true)
  {
    // Loop forever getting characters from the "receive" UART. Validate that they arrive in the expected
    // sequence.

    static int nLastRcvChar = 0;

    rcvChar = getChar(UART1);
    if (rcvChar == -1)
    {
      // No character available

      wait1Msec(2); // Don't want to consume too much CPU time. Waiting eliminates CPU consumption for this task.
      continue;
    }
    else
    {
	    if (rcvChar == 0xd)
	    {
	    	// receive whole number
	    	rcvChars[nRcvIndex] = 0x0;
	    	gyroAngle = -(float)(atoi(rcvChars)) * 10 / 365 * 360;
	    	nRcvIndex = 0;
	    	comCnt ++;
	    	if (comCnt > 1000){
	    		comCnt = 0;
	    	}

	    }

	    rcvChars[nRcvIndex] = rcvChar;
	    ++nRcvIndex;
	    if (nRcvIndex > 20) nRcvIndex = 0;
	   }
	 }
}
