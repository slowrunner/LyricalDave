#!/bin/bash

# FILE: echo_dock_status.sh

# PURPOSE:  display  /dock_status topic from dave.docking_node

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash

echo -e "\nros2 topic echo --once /dock_status"
ros2 topic echo --once /dock_status
