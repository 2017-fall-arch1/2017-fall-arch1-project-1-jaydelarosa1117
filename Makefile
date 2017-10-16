all: main

CFLAGS=-g -O3

main: btree.o main.o
	cc -o $@ $^ -lm

btree.o: btree.c btree.h
	cc -c $(CFLAGS) btree.c

main.o: main.c btree.h
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o main

demo: btree
	./main

