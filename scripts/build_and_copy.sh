#!/bin/bash

MEMSTICK=$1

if [ -e ${MEMSTICK} ];
then
    echo "Please provide memory stick id as arg1."
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

# To be sure
umount /mnt/sd

# Mount boot
mount /dev/disk/by-id/${MEMSTICK}-part1 /mnt/sd
cp -f linux-odroid-3.8.y-rt/arch/arm/boot/zImage /mnt/sd/zImage
sync
umount /mnt/sd

# Mount /
mount /dev/disk/by-id/${MEMSTICK}-part2 /mnt/sd
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

rsync -r rfs/ /mnt/sd/
sync
umount /mnt/sd

echo "Done!"

