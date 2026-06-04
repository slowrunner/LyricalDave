#!/bin/bash

# FILE:  count_lines.sh

repo="LyricalDave"

today=$(date +%F)
echo "count_lines.sh will count lines in the repo"
echo "  - excludes build/ install/ log/ .git/ and __pycache__/ "
echo "  - counts *.py, *.cpp *.sh *.md *.txt *.yaml"
echo -e "\n=== Code and Documentation Lines in $HOME/$repo on $today ==="
pushd $HOME/$repo > /dev/null

py_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.py" -exec cat {} + | wc -l)
echo "*.py: $py_cnt"

cpp_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.cpp" -exec cat {} + | wc -l)
echo "*.cpp: $cpp_cnt"

sh_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.sh" -exec cat {} + | wc -l)
echo "*.sh: $sh_cnt"

md_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.md" -exec cat {} + | wc -l)
echo "*.md: $md_cnt"

txt_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.txt" -exec cat {} + | wc -l)
echo "*.txt: $txt_cnt"

yaml_cnt=$(find . -type d \( -name ".git" -o -name "build" -o -name "install" -o -name "log" -o -name "old" -o -name "__pycache__" -o -name "old_ina219" \) -prune -o -type f -name "*.yaml" -exec cat {} + | wc -l)
echo "*.yaml: $yaml_cnt"

total=$(echo "$py_cnt + $cpp_cnt + $sh_cnt + $md_cnt + $txt_cnt + $yaml_cnt" | bc)
echo "Total Lines: $total"

