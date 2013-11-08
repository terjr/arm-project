#!/bin/bash

DIR=$(dirname $(readlink -f $0))
RESULTS_DIR=$DIR/../old_results

if [ ! -z $1 ]
then
    RESULTS_DIR=$1
fi

N=0
cat $DIR/../.tests | while read LINE;
do
    INSTR=$(echo $LINE | sed 's|.*/\(.*\)|\1|')
    echo -n "$INSTR "
    $DIR/results_summary.sh $INSTR $RESULTS_DIR \
        | sed 's|,| |' \
        | awk '{sum += $2; count += 1} END {print sum/count}'
done
