DIR=/root/arm-project/kmodules/
FILES=$(shell /usr/bin/find ${DIR} -maxdepth 2 -mindepth 2  ! -name '*.mod.c' -name '*.c' | sed -e 's@\(.*\).c@\1.o@g' -e 's@${DIR}@@g')
#FILES=add/add.o add/addne.o add/addeq.o add/adc.o misc/nop.o multiply/mul.o multiply/muls.o misc/cpsid.o misc/endian.o
#FILES=multiply/mul.o
#ccflags-y += -E
#ccflags-y+= -marm -mthumb-interwork -mfpu=vfpv3-d16
obj-m += $(FILES)
#obj-m += cof/jmp.o arith/mul.o arith/asr.o float/fmul.o

all:
	@echo "FILES:"
	@echo ${FILES}
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

