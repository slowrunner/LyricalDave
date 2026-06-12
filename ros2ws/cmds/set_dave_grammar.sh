#!/bin/bash

NS='/stt'
JSON='[ 
      "hey dave", 
      "hello dave", 
      "hi dave", 
      "shalom dave", 
      "bokair tov dave", 
      "good morning dave", 
      "good afternoon dave", 
      "good evening dave", 
      "good night dave", 
      "lie lah tov dave", 
      "[unk]" 
      ]'

# Strip newlines and collapse extra spaces
JSON_FLAT=$(echo "$JSON" | tr -d '\n' | tr -s ' ')

echo '{list:'"$JSON_FLAT"'}'

[ -n "$NS" ] || exit 0

echo "calling service set_grammar"
# echo "ros2 service call ${NS}/set_grammar voskros/srv/SetGrammar '{list:${JSON_FLAT}}'"
ros2 service call ${NS}/set_grammar voskros/srv/SetGrammar '{list:'"$JSON_FLAT"'}'
