# Simple example of shared library.

all: exec

exec: myprog libmy.so.1
	LD_LIBRARY_PATH=`pwd` ./myprog 7

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -g -Wall -fPIC -c $< -o $@

myprog: myprog.o libmy.so
	gcc -L. myprog.o -lmy -o $@

libmy.so.1.0: a.o b.o
	gcc -shared -Wl,-soname,libmy.so.1 a.o b.o -lc -o $@

libmy.so.1: libmy.so.1.0
	ln -sf $< $@

libmy.so: libmy.so.1.0
	ln -sf $< $@

clean:
	rm -f myprog libmy* *.o
