MODULENAME := hideproc
obj-m += $(MODULENAME).o
$(MODULENAME)-y += main.o

KERNELDIR ?= /lib/modules/`uname -r`/build
PWD       := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

test_proc:
	gcc -o $@ $@.c

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	$(RM) test_proc
