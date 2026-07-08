# Distance Sensor on Lyrical-Dave (Ubuntu 26.04)

The new GoPiGo3 Trixie install uses i2c module from python3-periphery in
 
/home/ubuntu/.venv/gopigo3/lib/python3.14/site-packages/periphery/i2c.py
 
BUT for some reason the EasyGoPiGo3.init_distance_sensor() returns
buffer overflow.

changing to smbus for i2c in di_i2c.py and putting it in Dave's plib folder
(and inserting it in the path) fixes the problem.

Easy workaround, it turns out:

1) copy the official di_i2c.py from the site-packages to my local python utils folder “…/plib”
- /home/ubuntu/.venv/gopigo3/lib/python3.14/site-packages/di_i2c.py  ~/LyricalDave/plib

2) Edit to use smbus instead of periphery
```
# https://www.dexterindustries.com
#
# Copyright (c) 2019 Dexter Industries
# Released under the MIT license (http://choosealicense.com/licenses/mit/).
# For more information see https://github.com/DexterInd/DI_Sensors/blob/master/LICENSE.md
#
# Python I2C drivers

import time
import threading
import di_mutex

print("Using local di_i2c.py")

__version__ = "1.3.2"

# Enabling one of the communication libraries
# This is not meant to change on a regular basis
# If Periphery doesn't work for you, uncomment either pigpio or smbus
#RPI_1_Module = "pigpio"
RPI_1_Module = "smbus"                     # Make this the default I2C bus, comment out periphery
# RPI_1_Module = "periphery"
...

3) Put my plib/ at the front of the python path
(simplistic example - no error handling)

```
import sys
sys.path.insert(1,"/home/ubuntu/LyricalDave/plib/")
import easygopigo3

egpg = easygopigo3.EasyGoPiGo3(use_mutex=True)
egpg.ds = egpg.init_distance_sensor()  # HW I2C
reading = egpg.ds.read_mm()
print(f"initDistanceSensor: reading: {reading}")

```


