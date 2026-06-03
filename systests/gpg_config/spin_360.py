#!/usr/bin/env python3
#

# import the time library for the sleep function
import time

import sys
sys.path.insert(0,"/home/ubuntu/LyricalDave/plib")

# import the GoPiGo3 drivers
from noinit_easygopigo3 import EasyGoPiGo3


# Create an instance of the GoPiGo3 class.
# egpg will be the GoPiGo3 object.
egpg = EasyGoPiGo3(use_mutex=True,noinit=True)
egpg.set_speed(150)
print("About to spin 360 degrees CW...")
time.sleep(5)

print("Spinning 360 degrees CW")
egpg.turn_degrees(360, True)


print("About to spin 360 degrees CCW...")
time.sleep(5)
print("Spinning 360 degrees CCW")
time.sleep(5)
egpg.turn_degrees(-360, True)
time.sleep(1)

print("Done!")
