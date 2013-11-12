#!/bin/sh
DIR=$(dirname $(readlink -f $0))

INSTR=$1

echo Date,Run,mAmps,AmbientTemp,HeatsinkTemp,RoomLight

$DIR/results_summary.sh $INSTR | while read LINE
do
    TEMP_INDEX=$(echo $LINE | awk -F , '{print $1 "-" $2}' | sed 's|[0-9]\{2\}\([0-9]\{2\}\)\([0-9]\{2\}\)\([0-9]\{2\}\).*-run\(.*\)|\3\2\1-\4|' )
    TEMP_REC=$(grep $TEMP_INDEX templog | awk -F , '{print $2 "," $3 "," $5}')
    if [ -z $TEMP_REC ]
    then
        TEMP_INDEX=$(echo $TEMP_INDEX | awk -F - '{print $1 "-" $2+1}')
        TEMP_REC=$(grep $TEMP_INDEX templog | awk -F , '{print $2 "," $3 "," $5}')
    fi
    if [ -z $TEMP_REC ]
    then
        TEMP_INDEX=$(echo $TEMP_INDEX | awk -F - '{print $1 "-" $2-1}')
        TEMP_REC=$(grep $TEMP_INDEX templog | awk -F , '{print $2 "," $3 "," $5}')
    fi 
    if [ -z $TEMP_REC ]
    then
         TEMP_REC=",,"
     fi
    echo $LINE,$TEMP_REC
done
