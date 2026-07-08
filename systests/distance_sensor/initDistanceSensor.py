#!/usr/bin/env python3

# FILE: initDistanceSensor.py

# PURPOSE:  Check distance sensor initialization on GoPiGo3

import sys
sys.path.insert(1,"/home/ubuntu/LyricalDave/plib/")

import easygopigo3

def main():
    egpg = easygopigo3.EasyGoPiGo3(use_mutex=True)
    egpg.ds = egpg.init_distance_sensor()  # HW I2C
    if egpg.ds == None:
        try:
            from di_sensors import easy_line_follower, easy_distance_sensor, easy_light_color_sensor, easy_inertial_measurement_unit
            di_sensors_available = True
        except ImportError as err:
            di_sensors_available = False
            print(f"Importing di_sensors error: {err}")
        except Exception as err:
            di_sensors_available = False
            print(f"Importing di_sensors error: {err}")



        port="I2C"
        print("Distance Sensor not initialized")
        if not di_sensors_available:
            raise ImportError("di_sensors library not available")

        try:
            d = easy_distance_sensor.EasyDistanceSensor(port=port, use_mutex=True)
        except Exception as e:
            print(e)
        if d == None:
            print(f"Failed to init EasyDistanceSensor(port={port}, use_mutex=True)")
    else:
       print("initDistanceSensor: Success distance sensor initialized")
       reading = egpg.ds.read_mm()
       print(f"initDistanceSensor: reading: {reading}")
if __name__ == '__main__': main()
