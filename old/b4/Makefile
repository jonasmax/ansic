CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

all: a2

a1: a1.o ring.o
	$(CC) $(CFLAGS) a1.o ring.o -o a1
	
a1.o: a1.c ring.h
	$(CC) -c $(CFLAGS) a1.c -o a1.o
	
ring.o: ring.c ring.h
	$(CC) -c $(CFLAGS) ring.c -o ring.o
	
a2: a2.o list.o
	$(CC) $(CFLAGS) a2.o list.o -o a2
	
a2.o: a2.c list.h
	$(CC) -c $(CFLAGS) a2.c -o a2.o
	
list.o: list.c list.h
	$(CC) -c $(CFLAGS) list.c -o list.o

clean:
	-/bin/rm *.o a1 a2
