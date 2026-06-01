#!/usr/bin/env python3

import time
from mpu9250_jmdev import MPU9250

# Initialize the sensor
imu = MPU9250()

# Print the whoami result in hexadecimal format
print("Device ID (whoami): " + hex(imu.whoami))

