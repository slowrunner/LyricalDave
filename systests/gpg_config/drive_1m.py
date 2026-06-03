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
egpg = EasyGoPiGo3(noinit=True,use_mutex=True)
egpg.set_speed(150)
print("About to drive 1 meter...")
time.sleep(5)

print("Driving 1 meter")
egpg.drive_cm(100, True)


# time.sleep(5)
# print("Stop!")
# gpg.stop()


print("Done!")
