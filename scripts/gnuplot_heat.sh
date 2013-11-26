#!/bin/bash
options='x:y:o:g:r:t:'
while getopts $options option
do
    case $option in
        f   )
            FILE=$OPTARG
            ;;
        x   )
            XRANGE=$OPTARG
            ;;
        y   )
            YRANGE=$OPTARG
            ;;
        o   )
            OUTPUT=$OPTARG
            ;;
        r   )
            ASPECT_RATIO=$OPTARG
            ;;
        g   )
            GRID=$OPTARG
            ;;
        t   )
            FONTSIZE=$OPTARG
            ;;
        *   )
            error
            ;;
    esac
done

DIR=$(dirname $(readlink -f $0))

# Gnuplot script
(

echo "#!/usr/bin/gnuplot -p -"
case $OUTPUT in
    eps )
        echo "set terminal postscript eps enhanced color"
        ;;
    * )
        ;;
esac

if [ ! -z "$ASPECT_RATIO" ]
then
    echo "set size 1, $ASPECT_RATIO"
fi

case $GRID in
    x   )
        echo 'set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"'
        ;;
    y   )
        echo 'set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"'
        ;;
    xy  )
        echo 'set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"'
        echo 'set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"'
        ;;
    yx  )
        echo 'set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"'
        echo 'set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"'
        ;;
    *   )
        error
        ;;
esac


echo "set style fill solid 1 border 0"
echo "set xtics rotate by -270"
echo "set key outside top right horizontal nobox"
echo 'set style line 1 lt 1 lw 3 pt 2 linecolor rgb "red"'
echo 'set style line 2 lt 1 lw 3 pt 2 linecolor rgb "#4444DB"'
echo 'set style line 3 lt 1 lw 3 pt 2 linecolor rgb "#22CC22"'
#echo 'set palette model RGB defined (0 "#ff0000", 0.33 "#22CC22", 1 "#0000AB")'
echo 'set palette model RGB defined (0 "#ff0000", 0.33 "#66CC66", 1 "#4444DB")'
if [ -z $FONTSIZE ]
then
    FONTSIZE=12
fi
echo "set xtics font \"Arial, $FONTSIZE\""
echo "set xlabel \"Run no.\" font \"Arial, $FONTSIZE\" offset 0,-1"


if [ ! -z $XRANGE ]
then
    echo "set xrange [$XRANGE]"
fi
if [ ! -z $YRANGE ]
then
    echo "set yrange [$YRANGE]"
fi

FILE=$(mktemp)
rm -f $FILE
for n in 5 6 7
do
    if [ $n == 5 ]
    then
        DESC="Ampere X 100"
    elif [ $n == 6 ]
    then
        DESC="Heatsink temp. (C)"
    elif [ $n == 7 ]
    then
        DESC="Ambient temp. (C)"
    fi
    awk -F, "BEGIN {print \"\n\n\\\"$DESC\\\"\"} NR>1 && \$7!=\"\" {print NR-1,\$2,\$$n,$n}" $DIR/../processed_results/heat-correlation.csv >> $FILE
done

echo "plot for [IDX=0:2] '$FILE' i IDX using 1:3:xtic(1) w lines ls IDX+1 title columnheader(1)"

) | gnuplot -p
