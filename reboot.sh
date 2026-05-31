#!/bin/bash

echo "Routine Reboot Requested"
batt=`(/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/plib/battery.py)`
/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/utils/logMaintenance.py "Routine Reboot"
/home/ubuntu/.venv/gopigo3/bin/python3 /home/ubuntu/LyricalDave/utils/logMaintenance.py "'$batt'"
sudo reboot
