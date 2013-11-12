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
echo "set xtics rotate by -45"
echo "set key left top Left"

if [ ! -z $XRANGE ]
then
    echo "set xrange [$XRANGE]"
fi
if [ ! -z $YRANGE ]
then
    echo "set yrange [$YRANGE]"
fi

echo "plot '$FILE' using 2:xtic(1) with boxes title 'Energy' linecolor rgb \"\#768ede\""

) | gnuplot -p
