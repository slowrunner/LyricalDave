#!/bin/bash

cd ~/LyricalDave/ros2ws

colcon build --packages-select bt_hello_dave --cmake-args -DCMAKE_BUILD_TYPE=Debug


