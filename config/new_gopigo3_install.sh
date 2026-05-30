#!/bin/bash

# New GoPiGo3 Software Install Option A
# Ref: https://github.com/DexterInd/GoPiGo3/blob/main/Installation_FAQ.md

sudo apt install gcc

sudo apt install -y python3-spidev
sudo apt install -y python3-rpi.gpio
sudo apt install -y python3.14-venv
cd ~
python3 -m venv --system-site-packages ~/.venv/gopigo3
source ~/.venv/gopigo3/bin/activate

pip install mr-gopigo3

source ~/.venv/gopigo3/lib/python3.*/site-packages/gopigo3/scripts/install_trixie.sh

echo -e "must execute: sudo reboot now  --- to launch gopigo3_power.py"

