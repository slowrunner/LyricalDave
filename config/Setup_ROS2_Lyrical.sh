#!/bin/bash

# SETUP ROS2 Lyrical Luth Base -  On Ubuntu 26.04 64-bit Server (Resolute Raccoon)

# REF:  https://docs.ros.org/en/lyrical/Installation/Ubuntu-Install-Debs.html

# === Make sure system is up to date before continuing
sudo apt update
sudo apt upgrade -y

# === Set locale
# locale  # check for UTF-8

sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

locale  # verify settings


# == Enable required repositories
sudo apt install -y software-properties-common
sudo add-apt-repository universe


sudo apt update && sudo apt install curl -y
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F'"' '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo ${UBUNTU_CODENAME:-${VERSION_CODENAME}})_all.deb"
sudo dpkg -i /tmp/ros2-apt-source.deb


# == Install dvelopment tools 
sudo apt update && sudo apt install ros-dev-tools



# === Install ROS2 
sudo apt update && sudo apt upgrade -y

sudo apt install -y ros-lyrical-ros-base

# === Source setup script
source /opt/ros/lyrical/setup.bash

# === Setup colcon build tool
sudo apt install -y python3-colcon-common-extensions

# === Setup ROS2 in user's .bashrc file
echo "source /opt/ros/lyrical/setup.bash" >> ~/.bashrc

# === Tell ROS2 to inhabit "Domain 0" 
echo "export ROS_DOMAIN_ID=0" >> ~/.bashrc

# === Setup ROSDEP tool
sudo apt install -y python3-rosdep2

# ==== Create a ROS2 Workspace with source folder


# === Setup colcon_cd in .bashrc
# echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc


echo -e "execute ./run_demo.sh to verify installation"
