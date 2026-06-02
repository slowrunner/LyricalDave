#!/bin/bash

ros2 run demo_nodes_cpp listener &
ros2 run demo_nodes_py talker &
sleep 6
pkill -f talker
pkill -f listener
