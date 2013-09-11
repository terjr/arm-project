#!/bin/bash
IP_ODROID=$1
IP_AGILENT=$2
KMOD=$3

GIT_ROOT=$(git rev-parse --show-toplevel)

ssh ${IP_ODROID} -l root /root/arm-project/scripts/disable_cpus.sh
ssh ${IP_ODROID} -l root testmod /root/arm-project/kmodules/${KMOD}.ko &
SSH_PID=$!

sleep 1

mkdir -p ${GIT_ROOT}/results/${KMOD}
${GIT_ROOT}/agilent/agilent ${IP_AGILENT} > ${GIT_ROOT}/results/${KMOD}/log &
PID=$!
sleep 10
kill ${PID}
wait ${SSH_PID}
