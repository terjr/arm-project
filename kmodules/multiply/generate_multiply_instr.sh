#!/bin/bash

for instr in mul muls mla mlas \
    {s,u}mull {s,u}mulls {s,u}mlal {s,u}mlals umaal \
    smul{b,t}{b,t} \
    smulw{b,t} \
    smla{b,t} \
    smlaw{b,t} \
    smlal{b,t}{b,t} \
    sm{u,l}ad{x,} \
    smlald{x,} \
    sm{u,l}sd{x,} \
    smlsld{x,} \
    smm{ul,la,ls}{r,}
do
    cp template.c $instr.c
    sed -i "s/template/$instr/" $instr.c
done
