#!/bin/bash

# Force-clear stuck mute
ros2 service call /hello_dave_bt/force_unmute std_srvs/srv/Trigger {}


