#!/bin/sh

#
# This scripts sets up the Agilent 3441xA to meassure as fast as it can as many samples as there
# is space for, and then print them out.
#
# For the Agilent 34410A, this means 50,000 samples @ 10,000samples/second over 5 seconds
#

IP_AGILENT=$1
if [ -z ${IP_AGILENT} ]
then
    echo "Please provide IP to Agilent as arg 1"
    exit 1
fi

#set 'SAMPLE:TIMER 0.0001428571'; to sample 7000 samples/second
#set 'SAMPLE:TIMER MIN'; to sample 10000 samples/second

(
echo '*RST';
echo 'CONFIGURE:VOLT:DC';
echo 'VOLTAGE:DC:RANGE:AUTO OFF';
echo 'VOLTAGE:DC:RANGE 100 mV';
echo 'TRIGGER:SOURCE IMM';
echo 'VOLTAGE:DC:APER MIN';
echo 'VOLTAGE:DC:APER:ENABLED 1';
echo 'VOLTAGE:DC:NPLC MIN'
echo 'VOLTAGE:DC:ZERO:AUTO OFF'
echo 'SAMPLE:COUNT MAX';
echo 'SAMPLE:TIMER MIN';
echo 'SAMPLE:SOURCE TIMER';
echo 'TRIGGER:DELAY MIN';
echo 'READ?';
sleep 6;
echo ''
) | nc -T  ${IP_AGILENT} 5024 |
sed -e 's/,/\n/g' -e 's///g'| awk '$1 !=  "3441xA>" && $1 != "Welcome" { print $1 "V", ($1*1000)/12 "A" }'
