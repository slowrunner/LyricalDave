#!/bin/bash

d=`(date +"%Y-%m-%d")`
homedir="/home/ubuntu"
repo="/LyricalDave"
saved="$homedir$repo/saved"
# echo -e "saved: $saved"


echo -e "$homedir$repo/utils/totallife.sh > $saved/${d}_totallife.txt"
$homedir$repo/utils/totallife.sh > $saved/${d}_totallife.txt
cat $saved/${d}_totallife.txt
