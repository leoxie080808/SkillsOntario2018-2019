#!/usr/bin/env python
#
# https://www.dexterindustries.com/BrickPi/
# https://github.com/DexterInd/BrickPi3
#
# Copyright (c) 2016 Dexter Industries
# Released under the MIT license (http://choosealicense.com/licenses/mit/).
# For more information, see https://github.com/DexterInd/BrickPi3/blob/master/LICENSE.md
#
# This code is an example for reading an EV3 gyro sensor connected to PORT_1 of the BrickPi3
# 
# Hardware: Connect an EV3 gyro sensor to BrickPi3 sensor port 1.
# 
# Results:  When you run this program, the gyro's absolute rotation and rate of rotation will be printed.

from __future__ import print_function # use python 3 syntax but make it compatible with python 2
from __future__ import division       #                           ''

import time     # import the time library for the sleep function
import brickpi3 # import the BrickPi3 drivers
import serial

serPort = serial.Serial("/dev/ttyUSB0", baudrate = 115200, timeout= 3.0)

                        
BP = brickpi3.BrickPi3() # Create an instance of the BrickPi3 class. BP will be the BrickPi3 object.

gyroAngle = 0
sampleCnt = 0
# we need filter to get rid off the jumping value '0'


# Configure for an EV3 color sensor.
# BP.set_sensor_type configures the BrickPi3 for a specific sensor.
# BP.PORT_1 specifies that the sensor will be on sensor port 1.
# BP.Sensor_TYPE.EV3_GYRO_ABS_DPS specifies that the sensor will be an EV3 gyro sensor.
BP.set_sensor_type(BP.PORT_1, BP.SENSOR_TYPE.EV3_GYRO_ABS)  #SENSOR_TYPE.EV3_GYRO_ABS_DPS
BP.set_sensor_type(BP.PORT_2, BP.SENSOR_TYPE.TOUCH)
try:
    while True:
        sampleCnt += 1
        if sampleCnt > 3:
            value = BP.get_sensor(BP.PORT_2)
            if value:
                time.sleep(1.0)
                print(value)
                BP.set_sensor_type(BP.PORT_1, BP.SENSOR_TYPE.NONE)
                time.sleep(1.0)
                BP.set_sensor_type(BP.PORT_1, BP.SENSOR_TYPE.EV3_GYRO_ABS)
                time.sleep(3.0)

        
        # BP.get_sensor retrieves a sensor value.
        # BP.PORT_1 specifies that we are looking for the value of sensor port 1.
        # BP.get_sensor returns the sensor value (what we want to display).
        try:
           gyroAngle = BP.get_sensor(BP.PORT_1);
           #if (gyroAngle > 0):
           #print(gyroAngle)   # print the gyro sensor values
           recStr = str(gyroAngle).encode('utf-8') + '\r'
           print(recStr)
           serPort.write(recStr.encode())
        except brickpi3.SensorError as error:
            print(error)
        
        time.sleep(0.01)  # delay for 0.02 seconds (20ms) to reduce the Raspberry Pi CPU load.

except KeyboardInterrupt: # except the program gets interrupted by Ctrl+C on the keyboard.
    BP.reset_all()        # Unconfigure the sensors, disable the motors, and restore the LED to the control of the BrickPi3 firmware.
