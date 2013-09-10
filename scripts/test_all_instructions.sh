#!/bin/bash
ME=$(readlink ${0} -f)
BASE=`basename ${0}`
MODDIR=${ME/${BASE}/..}/kmodules/
for file in $(find ${MODDIR}  -maxdepth 2 -mindepth 2  \
  -path '*microarch-experiments*' -prune -or \
! -name "jmp.c" ! -name '*.mod.c' -name '*.c' -print |
 sed -e 's@.*kmodules/\(.*\).c@\1@g' )
do
    echo "`date`: Testing ${file}"
    ${ME/${BASE}/test_kmod.sh} 129.241.111.182 129.241.110.134 ${file}
done

${ME/${BASE}/}generate_results.sh | gnuplot -p
