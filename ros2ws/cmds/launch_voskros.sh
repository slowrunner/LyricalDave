#!/bin/bash

cd /home/ubuntu/LyricalDave/ros2ws
source ss.sh

echo -e "launching voskros node"
ros2 launch voskros voskros.launch.yaml &
sleep 10
echo -e "setting hello_dave grammar"
cmds/set_dave_grammar.sh
