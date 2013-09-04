#!/bin/bash
echo "#!/usr/bin/gnuplot -p"
echo "# This file is a valid gnuplot-file"
echo "# You can pipe the results from this file into gnuplot -p"
echo

COUNTER=0
echo "set boxwidth 0.5"
echo "set style fill solid"
echo

echo "plot '-' using 1:3:xtic(2) with boxes"
for LOG_FILE in ${0/generate_results.sh/..\/results\/*\/log}
do
    F=`basename ${LOG_FILE/\/log/}`
    AVG=`awk 'BEGIN {x=0} $8 > 0 {sum+=$8; x+=1} END {print sum/x}' $LOG_FILE`
    echo ${COUNTER} ${F} "	" ${AVG}
    let COUNTER=COUNTER+1
done

echo "# file done"
