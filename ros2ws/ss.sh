#!/bin/bash 

ws="LyricalDave/ros2ws"
username=ubuntu

if [ -f /opt/ros/lyrical/setup.bash ]; then
    source /opt/ros/lyrical/setup.bash
    echo -e "sourced /opt/ros/lyrical setup.bash"
else
    echo -e "/opt/ros/lyrical/setup.bash not found"

fi

if [ -f /home/$username/$ws/install/setup.bash ]; then
    source /home/$username/$ws/install/setup.bash
    echo -e "sourced $user/$ws/install/setup.bash"
fi

echo -e "Done\n"

