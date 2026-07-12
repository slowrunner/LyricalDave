#!/bin/bash

gdb --args install/bt_hello_dave/lib/bt_hello_dave/hello_dave_lifecycle_node \
  --ros-args \
  -p grammar_yaml:=/home/ubuntu/LyricalDave/ros2ws/params/bt_hello_dave_grammar.yaml \
  -p bt_xml:=/home/ubuntu/LyricalDave/ros2ws/params/bt_hello_dave_tree.xml
