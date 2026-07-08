#!/usr/bin/env python3

# FILE: readDistOnce.py

# PURPOSE:  Read Distance Sensor Once to check I2C bus operation

import sys
sys.path.insert(1,"/home/ubuntu/LyricalDave/plib/")

# import will use plib/di_i2c.py which sets smbus for i2c
import easygopigo3

def main():
	# Using plib version of easygopigo3 to get noinit feature
	egpg = easygopigo3.EasyGoPiGo3(use_mutex=True)
	# egpg.tp = tiltpan.TiltPan(egpg)
	# egpg.ds = egpg.init_distance_sensor("RPI_1")  # HW I2C
	egpg.ds = egpg.init_distance_sensor()  # HW I2C
	dist = egpg.ds.read_mm()
	print(f"Distance Sensor Returned: {dist} mm")


if __name__ == '__main__': main()
