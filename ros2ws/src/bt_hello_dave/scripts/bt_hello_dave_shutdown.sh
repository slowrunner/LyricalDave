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

echo "Killing launch process group..."
pkill -f bt_hello_dave.launch.yaml

echo "Done."
