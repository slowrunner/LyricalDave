#!/bin/bash
# bt_hello_dave_activate.sh
#
# Brings the hello_dave_bt lifecycle node from unconfigured -> active.
# Run this after launching bt_hello_dave.launch.yaml.

set -e

NODE=/hello_dave_bt

echo "Configuring ${NODE}..."
ros2 lifecycle set ${NODE} configure

echo "Activating ${NODE}..."
ros2 lifecycle set ${NODE} activate

echo "Done. Current state:"
ros2 lifecycle get ${NODE}
