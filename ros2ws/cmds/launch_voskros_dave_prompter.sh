#!/bin/bash



echo -e "launching voskros node"
ros2 launch voskros voskros.launch.yaml &
sleep 10
echo -e "setting hello_dave_prompter grammar"
ros2 run voskros set_grammar.sh ~/LyricalDave/ros2ws/params/hello_dave_prompter.yaml /stt
sleep 10
echo -e "launching prompter"
ros2 run voskros prompter --ros-args     -r input:=/stt/result     -r __ns:=/stt     -p yaml:="/home/ubuntu/LyricalDave/ros2ws/params/hello_dave_prompter.yaml"&
