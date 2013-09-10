#!/bin/sh
IP_AGILENT=$1
if [ -z ${IP_AGILENT} ]
then
    echo "Please provide IP to Agilent as arg 1"
    exit 1
fi

VOLTAGE=`
( echo 'MEAS:VOLT:DC?'; sleep 0.1; echo '' ) |
nc -T  ${IP_AGILENT} 5024 |
sed -e 's// /g' |
awk 'FNR==2 {print $2}'
`

AMPS=`echo ${VOLTAGE} | awk '{print ($1*1000)/12}'`

echo "`date`	| ${VOLTAGE} V	| ${AMPS} A"
