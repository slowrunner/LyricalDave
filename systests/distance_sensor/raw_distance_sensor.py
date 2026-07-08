#!/usr/bin/env python3


import sys
sys.path.insert(1,"/home/ubuntu/LyricalDave/plib/")

# import will use plib/di_i2c.py which sets smbus for i2c
from di_sensors import distance_sensor

ds = distance_sensor.DistanceSensor()
print(ds.read_range_single())
