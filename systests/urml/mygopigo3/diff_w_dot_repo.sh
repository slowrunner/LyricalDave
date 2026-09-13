#!/bin/bash


echo "diff_w_dot_repo.sh"

echo "==== README.md =========="

diff README.md README.md.repo  

echo "===== gopigo3.manifest.yaml ========="

diff gopigo3.manifest.yaml gopigo3.manifest.yaml.repo  

echo "====== gopigo3_adapter.py ========"

diff gopigo3_adapter.py  gopigo3_adapter.py.repo  

echo "=== run_gopigo3.py ==========="

diff run_gopigo3.py  run_gopigo3.py.repo

echo "===== DONE ========="
