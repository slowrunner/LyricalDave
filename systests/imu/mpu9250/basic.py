#!/usr/bin/env python3

"""
  PREREQ:  pip3 install imusensor
           pip3 install smbus

  2026 Output:

The name is wrong [113]
roll: 179.5240509919115 ; pitch : -4.204397495575813 ; yaw : 95.8233859168819
roll: 179.2195657465436 ; pitch : -4.158256038577004 ; yaw : 94.13181615557843

"""

import os
import sys
import time
import smbus

from imusensor.MPU9250 import MPU9250

address = 0x68
bus = smbus.SMBus(1)
imu = MPU9250.MPU9250(bus, address)

imu.begin()
# imu.caliberateGyro()
# imu.caliberateAccelerometer()
# or load your own caliberation file
#imu.loadCalibDataFromFile("/home/pi/calib_real_bolder.json")

while True:
	imu.readSensor()
	imu.computeOrientation()

	print ("roll: {0} ; pitch : {1} ; yaw : {2}".format(imu.roll, imu.pitch, imu.yaw))
	time.sleep(0.1)
