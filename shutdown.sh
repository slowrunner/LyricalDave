#!/bin/bash

echo "Routine Shutdown Requested"
batt=`(/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/plib/battery.py)`
/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/utils/logMaintenance.py "Routine Shutdown"
/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/utils/logMaintenance.py "'$batt'"
sudo shutdown -h +2
