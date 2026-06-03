#!/bin/bash 

ws="LyricalDave/ros2ws"
username=ubuntu

if [ -f /opt/ros/lyrical/setup.bash ]; then
    source /opt/ros/lyrical/setup.bash
    echo -e "sourced /opt/ros/lyrical setup.bash"
else
    echo -e "/opt/ros/lyrical/setup.bash not found"

fi

if [ -f /home/$username/$ws/install/setup.bash ]; then
    source /home/$username/$ws/install/setup.bash
    echo -e "sourced $user/$ws/install/setup.bash"
fi

if [[ -n "$VIRTUAL_ENV" ]]; then
    VENV_SITE="$("$VIRTUAL_ENV/bin/python3" -c 'import site; print(site.getsitepackages()[0])')"
    if [[ ":$PYTHONPATH:" != *":$VENV_SITE:"* ]]; then
        export PYTHONPATH="$VENV_SITE:$PYTHONPATH"
        echo -e "added $VENV_SITE to PYTHONPATH"
    fi
fi

echo -e "Done\n"

