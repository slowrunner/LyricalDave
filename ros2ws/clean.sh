#!/bin/bash

if [ "$0" = "./clean.sh" ] || [ "$0" = "clean.sh" ]; then
    echo "ERROR: Must run as: . clean.sh"
    exit 1
fi

cd ~/LyricalDave/ros2ws

echo "Cleaning ros2ws build/install/log"
rm -rf log
rm -rf install
rm -rf build

unset CMAKE_PREFIX_PATH
unset AMENT_PREFIX_PATH

echo "Clean Complete"
