#!/bin/bash

ME=$(readlink ${0} -f)
BASE=`basename ${0}`
GIT_ROOT=$(git rev-parse --show-toplevel)
MODDIR=${GIT_ROOT}/kmodules/

if [ ! -e ${GIT_ROOT}/.tests ]
then
    echo "Please provide .tests"
    exit 1
fi

for file in $(cat ${GIT_ROOT}/.tests | grep -v ^#)
#for file in $(find ${MODDIR}  -maxdepth 2 -mindepth 2  \
#  -path '*microarch-experiments*' -prune -or \
#! -name "jmp.c" ! -name '*.mod.c' -name '*.c' -print |
# sed -e 's@.*kmodules/\(.*\).c@\1@g' )
do
    echo "`date`: Testing ${file}"
    ${ME/${BASE}/test_kmod.sh} 129.241.111.182 129.241.110.134 ${file}
done

${ME/${BASE}/}generate_results.sh | gnuplot -p
