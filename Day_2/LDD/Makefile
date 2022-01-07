
PWD := $(shell pwd)
obj-m += timer_in.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)

clean:
	make -C /lib/modules/$(shell uname -r)/build/ m=$(PWD) clean
