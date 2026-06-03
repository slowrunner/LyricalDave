#!/bin/bash

d=`(date +"%Y-%m-%d")`
homedir="/home/ubuntu"
repo="/LyricalDave"
saved="$homedir$repo/saved"
logs="$homedir$repo/logs"
# echo -e "logs: $logs"
# echo -e "saved: $saved"
echo "Cleaning life.log"

$homedir$repo/plib/cleanlifelog.py

echo -e "Saving $logs files with date: $d"

# echo -e "cp $logs/life.log     $saved/${d}_life.log"

cp $logs/life.log     $saved/${d}_life.log
cp $logs/odometer.log $saved/${d}_odometer.log
cp $logs/wheel.log    $saved/${d}_wheel.log
cp $logs/speak.log    $saved/${d}_speak.log
cp $logs/run.log      $saved/${d}_run.log

echo -e "Saving $homedir$repo/daveData.json with date: $d"
# echo -e "cp $homedir$repo/daveData.json $saved/${d}_daveData.json"
cp $homedir$repo/daveData.json $saved/${d}_daveData.json

echo -e "Saving $homedir/.gpg3_config.json with date: $d"
# echo -e "cp $homedir/.gpg3_config.json $saved/${d}_dot_gpg3_config.json"
cp $homedir/.gpg3_config.json $saved/${d}_dot_gpg3_config.json
