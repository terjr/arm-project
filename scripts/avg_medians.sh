#!/bin/bash

DIR=$(dirname $(readlink -f $0))
RESULTS_DIR=$DIR/../old_results

if [ ! -z $1 ]
then
    RESULTS_DIR=$1
fi

N=0
cat $DIR/../.tests | while read LINE;
do
    INSTR=$(echo $LINE | sed 's|.*/\(.*\)|\1|')
    echo -n "$INSTR "
    $DIR/results_summary.sh $INSTR $RESULTS_DIR | awk '{print $3}' |
        perl -e 'use List::Util qw(max min sum);
    @a=();
    while(<>){
        $sqsum+=$_*$_;
        push(@a,$_)
    };
    $n=@a;
    $s=sum(@a);
    $a=$s/@a;
    $m=max(@a);
    $mm=min(@a);
    $std=sqrt($sqsum/$n-($s/$n)*($s/$n));
    $mid=int @a/2;
    @srtd=sort @a;
    if(@a%2){
        $med=$srtd[$mid];
    }else{
    $med=($srtd[$mid-1]+$srtd[$mid])/2;
};
print "$a $std\n";'
done
