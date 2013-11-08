#!/bin/bash

DIRNAME=$(dirname $(readlink -f $0))
RESULTS_HOME=$DIRNAME/..

# Clean current results
rm -r $DIRNAME/../results

while true;
do
    RUN_NO=$(date +%H%M%S)
    $DIRNAME/test_instructions.sh
    NEWDIR=$RESULTS_HOME/old_results/$(date +%Y%m%d)
    mkdir -p $NEWDIR
    mv $RESULTS_HOME/results $NEWDIR/results.run$RUN_NO
    ssh root@129.241.111.182 dmesg -Tc > $NEWDIR/results.run$RUN_NO/dmesg
done
