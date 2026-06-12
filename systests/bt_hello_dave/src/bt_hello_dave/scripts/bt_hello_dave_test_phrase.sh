#!/bin/bash
# bt_hello_dave_test_phrase.sh
#
# Publishes a simulated /stt/result message (or two, for split-phrase
# testing) to exercise the Hello Dave BT without needing voskros to
# actually recognize speech.
#
# Usage:
#   bt_hello_dave_test_phrase.sh "hello dave"
#   bt_hello_dave_test_phrase.sh "good morning" "dave"
#   bt_hello_dave_test_phrase.sh "battery state dave"
#   bt_hello_dave_test_phrase.sh "go to sleep dave"
#   bt_hello_dave_test_phrase.sh "wake up dave"

if [ -z "$1" ]; then
  echo "Usage: $0 \"<phrase>\" [\"<second part>\"]"
  exit 1
fi

ros2 run bt_hello_dave stt_test_publisher "$1" "$2"
