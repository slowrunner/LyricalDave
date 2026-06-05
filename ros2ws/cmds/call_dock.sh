#!/bin/bash

# FILE: call_dock.sh

# PURPOSE:  call the docking_node  /dock service

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash

echo -e "\n*** Calling docking_node /dock service"
echo -e "ros2 service call /dock dave_interfaces/srv/Dock"
ros2 service call /dock dave_interfaces/srv/Dock
