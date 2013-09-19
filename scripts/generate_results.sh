#!/bin/bash
echo "#!/usr/bin/gnuplot -p -"
echo "# This file is a valid gnuplot-file"
echo "# You can pipe the results from this file into gnuplot -p"
echo

COUNTER=0

FILELIST=`/usr/bin/find ${0/generate_results.sh/..\/results\/*\/*\/} -name log`


echo "set style fill solid 1.00 border 0"
echo "set style histogram errorbars gap 2 lw 1"

#echo "set boxwidth 1"
#echo "set style fill empty"
#echo "set style line 2"
echo "set yrange [0:0.8]"
echo "set xrange [-0.5:`echo ${FILELIST} | wc -w `]"
echo "set xtics rotate by -45"
echo

echo "plot '-' using 1:2:3:4:xtic(6) with boxerrorbars"
for LOG_FILE in ${FILELIST}
do
    if [ -z `echo ${LOG_FILE} | grep -v microarch` ]
    then
        continue
    fi
    F=`basename $(echo ${LOG_FILE} | sed -e 's/log$//')`
    AVG=`awk 'BEGIN {x=0; min=100000; max=0} $2 > 0 {sum+=$2; x+=1} $2 > max {max=$2} $2 < min {min=$2}  END {avg=sum/x; print avg - min, max - avg}' $LOG_FILE`
    MEDIAN=`awk '{print $2+0}' $LOG_FILE | sort -n -k1 | awk 'NR==25000 {print $1}'`
    echo ${COUNTER} ${MEDIAN}  ${AVG} -2 ${F}
    let COUNTER=COUNTER+1
done

echo "# file done"
