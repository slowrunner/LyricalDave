#!/bin/bash

<< ////
    FILE:  /home/ubuntu/LyricalDave/ros2ws/start_LyricalDave.sh

This file starts the needed 9 LyricalDave nodes (8 python processes in status.sh):
- ros2_gopigo3_node     GoPiGo3 ROS2 publishes odom, offers /cmd_vel etc
- battery_node          publishes /batter_state
- docking_node          publishes /dock_status, offers /dock and /undock services
- dave_node             calls /dock when vBatt<10v, and calls /undock when charge current < -175mA
- odometer              records ROS all /cmd_vel movement (does not record dock/undock movement)
- joy_node              handles wireless F710 or SNES joy controller to publish /cmd_vel
- say_node              TTS speech server offers /say {"phrase" volume anytime} service
- robot_state_publisher
  joint_state_publisher both started by ros2_dave_state_and_joint.launch.py

////


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

if [[ -n "$VIRTUAL_ENV" ]]; then
    VENV_SITE="$("$VIRTUAL_ENV/bin/python3" -c 'import site; print(site.getsitepackages()[0])')"
    if [[ ":$PYTHONPATH:" != *":$VENV_SITE:"* ]]; then
        export PYTHONPATH="$VENV_SITE:$PYTHONPATH"
        echo -e "added $VENV_SITE to PYTHONPATH"
    fi
fi


echo -e "\n*** Start ROS2 GoPiGo3 node"
echo "*** ros2 run ros2_gopigo3_node gopigo3_node &"
ros2 run ros2_gopigo3_node gopigo3_node &

sleep 5

echo -e "\n*** Starting Robot_State and Joint_State Publishers"
echo "*** with URDF file: ros2_gopigo3_node/kilteddave2.urdf"
ros2 launch ros2_gopigo3_node ros2_dave_state_and_joint.launch.py &

sleep 5

echo -e "\n*** Start Docking Node"
echo -e "*** ros2 run dave docking_node & "
ros2 run dave docking_node &

sleep 5 

echo -e "\n*** Starting Odometer Node to log movements"
echo "*** ros2 run ros2_gopigo3_node odometer"
ros2 run ros2_gopigo3_node odometer &

sleep 5

# echo -e "\n*** Start dave.say_node"
echo '*** ros2 run dave say_node & '
ros2 run dave say_node &

sleep 5

echo -e "\n*** Start SNES gamepad node"
echo '*** ros2 launch teleop_twist_joy teleop-launch.py joy_config:="snes_slow" & '
ros2 launch teleop_twist_joy teleop-launch.py joy_config:="snes_slow"  &

echo -e "\n*** SLEEPING 30 before starting battery node"
sleep 30

echo -e "\n*** Starting Battery Node"
echo -e "*** ros2 run dave battery_node &"
ros2 run dave battery_node &

sleep 5

pgrep_lines="$(ps -ef | grep battery_node | wc -l)"

if [ $pgrep_lines -eq 1 ]; then
    echo -e "\n*** Trying a second time to start Battery Node" ;
    echo -e "\n*** SLEEPING 30 before 2nd attempt to start battery node"
    sleep 30
    echo -e "*** ros2 run dave battery_node &" ;
    ros2 run dave battery_node & 
    sleep 5
    ps -ef | grep battery_node
fi


echo -e "\n*** Start Dave Node"
echo -e "*** ros2 run dave dave_node & "
ros2 run dave dave_node  &

sleep 5

/home/ubuntu/LyricalDave/ros2ws/status.sh

echo -e "\n*** start_LyricalDave.sh COMPLETE"
