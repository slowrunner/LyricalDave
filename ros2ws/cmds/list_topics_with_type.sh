#!/bin/bash

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash


echo "List active ROS2 topics - With topic TYPE"
set -v
ros2 topic list -t
