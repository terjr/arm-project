#!/bin/bash
if [ -z $1 ]
then
    echo "Usage: $0 {int}+{_group}+{-int{c{int}}?}?"
    echo "  where int is cycles (1,2 or 3) and _group is members."
    echo "  Example: 23_mult_add will give you all multiply and add instructions using 2 or 3 cycles"
    echo ""
    echo "  Append -2 at the end of the string to set aspect ratio to 2x1, or -0c5 to set 1x2."
    echo "  The use of the 'c' character in place of '.' is because LaTeX thinks it means file"
    echo "  extension... "
    echo ""
    echo "  Full example 13_data_logic-0c7"
    echo "  - gives graph of all data and logic instructions using 1 or 3 cycles, aspect ratio 0.7x1"
    exit
fi

if [ ! -z $2 ]
then
    echo "Adjusting fontsize for $2 scaling"
    FONTSIZE=$(echo 12.0/$2 | bc)
else
    FONTSIZE=12
fi
echo "Fontsize is $FONTSIZE"

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

GROUP_FILTER=$(echo $GROSS_FILTER | sed 's|[^ ]* \([^-]*\).*|\1|;tx;d;:x')
ASPECT_RATIO=$(echo $GROSS_FILTER | sed 's|[^-]*-\(.*\)|-r \1|;tx;d;:x' | tr 'c' '.')

echo Aspect ratio is $ASPECT_RATIO
#echo $GROSS_FILTER
echo Included groups are $GROUP_FILTER

if [ -z "$GROUP_FILTER" ]
then
    FILTER=${FILTER:2}
else
    FILTER="("${FILTER:2}" ) && ( "
    for group in $GROUP_FILTER
    do
        FILTER=$(echo $FILTER "\$5==\""$group"\" || ")
    done
    FILTER=$(echo ${FILTER:0:-3} ")")
fi
echo Saving EPS figure to figures/graph_$1.eps
$GNUPLOT -f <( awk -F , "$FILTER {print \$1, \$4, \$2}" $RESULTS_CSV | sort -n -k 2 ) $ASPECT_RATIO -o eps -g xy -y '0:*' -t $FONTSIZE > figures/graph_$1.eps
