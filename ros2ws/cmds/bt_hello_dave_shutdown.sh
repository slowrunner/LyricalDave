#!/bin/bash
# bt_hello_dave_shutdown.sh
#
# Cleanly transitions the hello_dave_bt lifecycle node down through
# deactivate -> cleanup -> shutdown, then kills the launch process
# group started by bt_hello_dave.launch.yaml.

NODE=/hello_dave_bt

echo "Deactivating ${NODE}..."
ros2 lifecycle set ${NODE} deactivate 2>/dev/null

echo "Cleaning up ${NODE}..."
ros2 lifecycle set ${NODE} cleanup 2>/dev/null

echo "Shutting down ${NODE}..."
ros2 lifecycle set ${NODE} shutdown 2>/dev/null

echo "Sending SIGINT to the launch process (graceful shutdown of all launched nodes)..."
pkill -INT -f bt_hello_dave.launch.yaml

sleep 3

echo "Checking for leftover processes..."
pkill -f bt_hello_dave.launch.yaml 2>/dev/null
pkill -f "voskros/lib/voskros/vosk" 2>/dev/null
pkill -f hello_dave_lifecycle_node 2>/dev/null
pkill -f say_node 2>/dev/null
pkill -f battery_state_node 2>/dev/null

echo "Done."
