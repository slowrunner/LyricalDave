#!/bin/bash

# basedir=LyricalDave
# echo -e "\n*** Switching to ~/${basedir}/ros2ws"
# cd ~/$basedir/ros2ws

# echo -e "\n*** Sourcing /opt/ros/lyrical/setup.bash"
# . /opt/ros/lyrical/setup.bash

# echo -e "\n*** Sourcing install/setup.bash"
# . ~/$basedir/ros2ws/install/setup.bash

trap '[[ $BASH_COMMAND != echo* ]] && echo $BASH_COMMAND' DEBUG

echo -e "\n*** STARTING kill_stt.sh ***"
# ps -ef | grep vosk
echo " "
pkill -ef vosk
echo -e  "\n*** DONE KILLING STT PROCESSES ***\n"
