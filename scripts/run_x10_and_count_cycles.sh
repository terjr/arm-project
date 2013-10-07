#!/bin/sh

DIRNAME=$(dirname $(readlink -f $0))

for i in $(seq 1 10)
do
    echo "Iteration $i"
    $DIRNAME/test_instructions.sh
done
ssh root@129.241.111.182 dmesg | sed 's|[.*]||' | awk '$1 == "Testing" {INSTR=$2} $1 == "part1" {P1=$3} $1 == "part2" {P2=$3} $1 == "runtest()" && INSTR != "" {print INSTR ", " P1 ", " P2 }' | sort
