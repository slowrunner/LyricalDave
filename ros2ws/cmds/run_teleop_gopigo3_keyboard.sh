#!/bin/bash

# FILE: run_teleop_gopigo3_keyboard.sh
# PURPOSE: Start GoPiGo3 robot version of teleop_twist_keyboard

echo -e "\n\n******** STARTING TELEOP GOPIGO3 KEYBOARD ********"

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash

echo -e "\n*** Start teleop_gopigo3_keyboard node"
echo "*** ros2 run teleop_gopigo3_keyboard teleop_gopigo3_keyboard"
ros2 run teleop_gopigo3_keyboard teleop_gopigo3_keyboard

