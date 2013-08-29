#!/bin/bash

IP_ADDR=$1

if [ -e ${IP_ADDR} ];
then
    echo "Please provide IP address as arg1."
    exit 1
fi

pushd .

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm
which arm-linux-gnueabihf-gcc
if [ ! -z $? ];
then
    echo "Adding toolchain to path"
    export PATH=/usr/local/arm/toolchain/bin:$PATH
fi

cd linux-odroid-3.8.y-rt/
make -j5 zImage
make -j5 modules
cd ..

scp linux-odroid-3.8.y-rt/arch/arm/boot/zImage root@${IP_ADDR}:/boot/zImage

cd linux-odroid-3.8.y-rt
mkdir -p ../rfs
export INSTALL_MOD_PATH=$PWD/../rfs
make -j5 modules_install
cd ../rfs
# remove symlinks that point to files we do not need in root file system
find . -name source | xargs rm
find . -name build | xargs rm
# Compress
#sudo tar -cvzf ../modules.tgz .
cd ../
popd

scp -r rfs/* root@${IP_ADDR}:/

echo "Done!"

