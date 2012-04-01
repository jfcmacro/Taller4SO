CFLAGS=-D_LINUX_

all: libParBegin.so Main Solucion1

Main: Main.o
	gcc -o $@ $< -lParBegin -lpthread -L.

Solucion1: Solucion1.o
	gcc -o $@ $< -lParBegin -lpthread -L.

libParBegin.so: ParBeginThread.o
	gcc -o $@ -shared $<