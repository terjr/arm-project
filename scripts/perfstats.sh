#!/bin/sh
DIRNAME=$(readlink -f $(dirname $0))

echo instruction,iterations,cycles,main_ex,second_ex,pred_branch,mispred_branch,issue_no_dispatch,issue_empty
ssh root@129.241.111.182 dmesg | sed 's|.*] \(.*\)|\1|' |
awk '$1 == "Running" \
    { \
        $1=""; \
        COUNT=$(NF-1); \
        $(NF-2)=""; \
        $(NF-1)=""; \
        $(NF)=""; \
        INSTR="\""gensub("(^ +| +$)","","g", $0)"\""
     }
     $1 == "cycle_count" {CYCLES=$2}
     $1 == "main_ex" {MAIN_EX=$2}
     $1 == "second_ex" {SECOND_EX=$2}
     $1 == "pred_branch" {PRED_BRANCH=$2}
     $1 == "mispred_branch" {MISPRED_BRANCH=$2}
     $1 == "issue_no_dispatch" {ISSUE_NO_DISPATCH=$2}
     $1 == "issue_empty" {ISSUE_EMPTY=$2;
     print INSTR "," COUNT "," CYCLES "," MAIN_EX "," SECOND_EX "," PRED_BRANCH "," MISPRED_BRANCH "," ISSUE_NO_DISPATCH "," ISSUE_EMPTY  }
     '
