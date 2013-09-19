#!/bin/bash

DIRNAME=$(dirname $(readlink -f $0))

echo "#!/usr/bin/gnuplot -p -"
echo "# This file is a valid gnuplot-file"
echo "# You can pipe the results from this file into gnuplot -p"
echo

echo set boxwidth 0.5
echo set style fill solid
echo set yrange [0:20000]
echo set xrange [-.5:]

FILELIST=$(find $DIRNAME/../results -name 'cycles')


echo "plot '-' using 1:2:xtic(3) with boxes"
I=0
for FILE in $FILELIST
do
    echo $I $(cat $FILE) $(basename $(dirname $FILE))
    ((I++))
done
