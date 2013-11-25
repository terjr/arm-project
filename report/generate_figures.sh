#!/bin/bash
if [ -z $1 ]
then
    echo "Uage: $0 {int}+{_group}+"
    echo "\twhere int is cycles (1,2 or 3) and _group is members, eg. 23_mult_add will give"
    echo "\tall multiply and add instructions using 2 or 3 cycles"
    exit
fi

BASE=$(dirname $(readlink -f $0))
GNUPLOT=$BASE/../scripts/gnuplot_barchart.sh
RESULTS_CSV=$BASE/../processed_results/unsorted/cycle_timings.csv

GROSS_FILTER=$(echo $1 | tr '_' '\n')
CYCLES=$(echo $GROSS_FILTER | cut -d' ' -f1)
FILTER=""
for (( i=0; i<${#CYCLES}; i++ ))
do
    FILTER=$(echo $FILTER "|| \$2=="${CYCLES:$i:1})
done
FILTER="("${FILTER:2}" ) && ( "
for group in $(echo $GROSS_FILTER | sed 's|[^ ]* \(.*\)|\1|')
do
    FILTER=$(echo $FILTER "\$5==\""$group"\" || ")
done
FILTER=$(echo ${FILTER:0:-3} ")")

$GNUPLOT -f <( awk -F , "$FILTER {print \$1, \$4, \$2}" $RESULTS_CSV | sort -n -k 2 ) -o eps > figures/graph_$1.eps
