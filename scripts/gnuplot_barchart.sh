#!/bin/sh
options='f:x:y:o:'
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
        *   )
            error
            ;;
    esac
done

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
echo "set style fill solid 0.50 border 0"
echo "set xtics rotate by -90"
echo "set key left top Left"
echo "set xtics font \"Arial, 9\""
echo "set palette model RGB defined (0 \"green\", 1 \"blue\")"

if [ ! -z $XRANGE ]
then
    echo "set xrange [$XRANGE]"
fi
if [ ! -z $YRANGE ]
then
    echo "set yrange [$YRANGE]"
fi

echo "unset colorbox"

echo "plot '$FILE' using (\$0):2:3:xtic(1) with boxes palette notitle"

) | gnuplot -p
