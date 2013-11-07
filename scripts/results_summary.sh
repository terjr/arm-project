#!/bin/bash
DIR=$(dirname $(readlink -f $0))
RESULTS_DIR=$DIR/../old_results

function FIND_MEDIAN()
{

  TEST_NAME=$(echo $1 | sed 's|.*\.\([^/]*\)/.*|\1|')
  MIDDLE=$(($(cat $1 | wc -l) / 2))
  cat $1 | tr -d 'A' | sort -n -k 2 | awk "NR == $MIDDLE {print \"$TEST_NAME\" \",\" \$2}"
}


INSTR=$1
if [ -z $INSTR ]
then
    echo "Please provide instruction as argument"
fi

if [ ! -z $2 ]
then
    RESULTS_DIR=$2
fi


FILES=$(find $RESULTS_DIR -path "*/$INSTR/log")

for F in $FILES
do
    FIND_MEDIAN $F
done
