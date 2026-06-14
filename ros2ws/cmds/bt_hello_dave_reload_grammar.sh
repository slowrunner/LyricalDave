#!/bin/bash
# bt_hello_dave_reload_grammar.sh
#
# Hot-reloads the grammar YAML (fixed responses, random pool, grammar
# list) without restarting the BT system. Also re-pushes the grammar
# list to /stt/set_grammar.

ros2 service call /hello_dave_bt/reload_grammar std_srvs/srv/Trigger {}
