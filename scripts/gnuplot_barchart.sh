#!/bin/sh
options='f:x:y:o:g:r:'
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


echo "set style fill solid 0.50 border 0"
echo "set xtics rotate by -90"
echo "set key left top Left"
echo "set xtics font \"Arial, 9\""
echo 'set palette model RGB defined (0 "#228B22", 1 "#00008B")'
echo "set cbrange [1:3]"
echo "set ylabel \"Ampere {/Symbol \\327} cycles\" font \"Arial, 12\" offset 2,0"
echo "set xlabel \"Instruction\" font \"Arial, 12\" offset 0,2"


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
