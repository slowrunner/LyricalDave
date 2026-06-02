#!/usr/bin/env python3

# SETUP:  pip3 install pi-ina219

import ina219
from ina219 import DeviceRangeError
import time

SHUNT_OHMS = 0.1

ina = ina219.INA219(SHUNT_OHMS,busnum=1)
ina.configure()

try:
    while True:
        tnow = time.strftime("%Y-%m-%d %H:%M:%S")
        print("{} Reading: {:.2f} V  {:.3f} A  {:.2f} W".format(tnow,ina.voltage(), ina.current()/1000.0, ina.power()/1000.0))
        ina.sleep()
        print("Sleeping for 120s\n")
        time.sleep(120)
        ina.wake()
except DeviceRangeError as e:
    print(e)
except KeyboardInterrupt:
    print("\nWaking ina219 and Exiting")
    ina.wake()
    exit(0)
finally:
    ina.wake()
