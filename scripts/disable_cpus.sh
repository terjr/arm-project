#!/bin/sh
for i in /sys/devices/system/cpu/cpu*/online; 
do
echo 0 > $i
done
