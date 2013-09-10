#!/bin/sh

echo "Date				| Voltage		| Current"
while [ true ]
do
    ./get_current_current.sh $1
    sleep .4
done
