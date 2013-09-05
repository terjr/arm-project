obj-m += jmp.o mul.o asr.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

mul.asm: mul.shasm
	./mul.shasm > mul.asm


