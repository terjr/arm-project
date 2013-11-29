#!/bin/sh

#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:Running smlawt r0, r1, r4, r5 and smlawt r2, r3, r6, r7 for 0xfb iterations
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:Instr: e12054c1
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:cycle_count 3604
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:main_ex 3518
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:second_ex 3265
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:pred_branch 251
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:mispred_branch 2
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:issue_no_dispatch 83
#Oct 31 15:52:50 odroid-wheezy kernel: [   96.015000] tdt4501:issue_empty 83

if [ -z $1 ]
then
    echo "Please give messages-file as input"
fi

cat $1 |
awk '$9=="done."            {print INSTR "&" CYCLE "&" MAIN "&" SECOND "&" PRED "&" MISPRED "&" NODISP "&" EMPTY "\\\\"} \
     $8=="tdt4501:Running"  {INSTR=$9} \
     $8=="tdt4501:cycle_count" {CYCLE=$9} \
     $8=="tdt4501:main_ex" {MAIN=$9} \
     $8=="tdt4501:second_ex" {SECOND=$9} \
     $8=="tdt4501:pred_branch" {PRED=$9} \
     $8=="tdt4501:mispred_branch" {MISPRED=$9} \
     $8=="tdt4501:issue_no_dispatch" {NODISP=$9} \
     $8=="tdt4501:issue_empty" {EMPTY=$9}'
