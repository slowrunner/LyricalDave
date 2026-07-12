#!/bin/bash

# Dump key blackboard state
ros2 service call /hello_dave_bt/get_blackboard_debug std_srvs/srv/Trigger {}
