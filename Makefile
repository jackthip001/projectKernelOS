obj-m += history_dfs.o

KDIR = /usr/src/kernels/3.10.0-229.el7.x86_64

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order
