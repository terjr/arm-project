#!/bin/sh
for i in /sys/devices/system/cpu/cpu*/online; 
do
echo 1 > $i
done
