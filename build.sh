#!/bin/sh -x
aarch64-linux-gnu-gcc -I /usr/include/libdrm \
	 *.c -ldrm -Wall -o kmsgrab
# hf : -m32
