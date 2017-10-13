all: main

CFLAGS=-g -O3

main: btree.o
	cc -o $@ $^ -lm

btree.o: btree.c btree.h
	cc -c $(CFLAGS) btree.c

clean:
	rm -f *.o btree main

demo: btree
	./btree

