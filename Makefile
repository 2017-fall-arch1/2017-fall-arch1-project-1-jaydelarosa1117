all: main

CFLAGS=-g -O3
# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

main: btree.o main.o
	cc -o $@ $^

btree.o: btree.c btree.h
	cc -c $(CFLAGS) btree.c

main.o: main.c btree.h
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o main

demo: main
	./main 

