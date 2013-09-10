#!/bin/bash
for i in /sys/devices/system/cpu/cpu*/online; do
    CPU_NUM=$(echo $i | sed 's/.*\([0-9]\+\).*/\1/')
    if [ $(cat $i) -eq 1 ]; then
        echo -en "\033[32m${CPU_NUM}\033[0m"
    else
        echo -en "\033[31m${CPU_NUM}\033[0m"
    fi
done
