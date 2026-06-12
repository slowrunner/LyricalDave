#!/bin/bash


ros2 run voskros prompter --ros-args     -r input:=/stt/result     -r __ns:=/stt     -p yaml:="/home/ubuntu/LyricalDave/ros2ws/params/hello_dave_prompter.yaml"

