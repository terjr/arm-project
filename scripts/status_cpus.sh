#!/bin/bash
for i in /sys/devices/system/cpu/cpu*/online; do
    CPU_NUM=$(echo $i | sed 's/.*\([0-9]\+\).*/\1/')
    echo -n "cpu${CPU_NUM}: "
    if [ $(cat $i) -eq 1 ]; then
        echo -e "\033[32monline\033[0m"
    else
        echo -e "\033[31moffline\033[0m"
    fi
done
