#!/bin/bash
DIR=$(dirname $(readlink -f $0))
RESULTS_DIR=$DIR/../old_results

function FIND_STATS()
{
  awk '{print $2+0}' $1 |
  perl -e 'use List::Util qw(max min sum);
  @a=();
  while(<>){
      $sqsum+=$_*$_;
      push(@a,$_)
  };
  $n=@a;
  $a=$s/@a;
  $mid=int @a/2;
  @srtd=sort @a;
  if(@a%2){
      $med=$srtd[$mid];
  }else{
  $med=($srtd[$mid-1]+$srtd[$mid])/2;
      };
      print "$med";'
  }

  function FIND_MEDIAN()
  {

      TEST_NAME=$(echo $1 | sed 's|.*/\([^/]*\)/.*\.\([^/]*\)/.*|\1 \2|')
      MIDDLE=$(($(cat $1 | wc -l) / 2))
      echo $(cat $1 | tr -d 'A' | sort -n -k 2 | awk "NR == $MIDDLE {print \"$TEST_NAME\" \" \" \$2}")
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
      #TEST_NAME=$(echo $F | sed 's|.*/\([^/]*\)/.*\.\([^/]*\)/.*|\1,\2|')
      FIND_MEDIAN $(readlink -f $F)
      #    echo $MEDIAN $SD
  done
