export PATH := /home/alex4cable/Documents/coursera/gcc-arm-10.2-2020.11/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/:$(PATH)


CC = $(CROSS_COMPILE)gcc


all: writer

writer: writer.o

clean:
	@echo "Cleaning up.."
	-rm -rf *.o                 # - prefix for ignoring errors and continue execution
	-rm writer