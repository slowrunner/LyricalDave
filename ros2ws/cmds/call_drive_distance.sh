#!/bin/bash

# FILE: call_drive_distance.sh

# PURPOSE:  call the drive_node  /drive_distance  service

basedir=LyricalDave
echo -e "\n*** Switching to ~/${basedir}/ros2ws"
cd ~/$basedir/ros2ws

echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
. /opt/ros/lyrical/setup.bash

echo -e "\n*** Sourcing install/setup.bash"
. ~/$basedir/ros2ws/install/setup.bash

echo -e "\n*** Calling drive_node /drive_distance service"
echo -e "ros2 service call /drive_distance dave_interfaces/srv/DriveDistance '{distance: 0.017, speed: 0.05}'"


ros2 service call /drive_distance dave_interfaces/srv/DriveDistance "{distance: 0.017, speed: 0.05}"
