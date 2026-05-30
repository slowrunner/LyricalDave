#!/bin/bash

echo "Routine Reboot Requested"
batt=`(/home/ubuntu/LyricalDave/plib/battery.py)`
/home/ubuntu/LyricalDave/utils/logMaintenance.py "Routine Reboot"
/home/ubuntu/LyricalDave/utils/logMaintenance.py "'$batt'"
sudo reboot
