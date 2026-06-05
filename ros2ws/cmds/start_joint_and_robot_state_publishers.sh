#!/bin/bash

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash


echo -e "\n*** Starting Robot_State and Joint_State Publishers"
echo "*** with URDF file: ros2_gopigo3_node/urdf/lyricaldave2.urdf"
ros2 launch ros2_gopigo3_node ros2_dave_state_and_joint.launch.py &


