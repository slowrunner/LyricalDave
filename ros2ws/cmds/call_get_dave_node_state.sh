#!/bin/bash

# FILE: call_get_dave_state.sh

# PURPOSE:  call the dave_node  /get_dave_state service

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash

echo -e "\n*** Calling dave_node /get_state service"
echo -e "ros2 service call /get_dave_state dave_interfaces/srv/State"
ros2 service call /get_dave_state  dave_interfaces/srv/State
