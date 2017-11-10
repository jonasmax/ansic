CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

all: a2

a2: a2.o
	$(CC) $(CFLAGS) a2.o -o a2
	
a2.o: a2.c
	$(CC) -c $(CFLAGS) a2.c -o a2.o

clean:
	-/bin/rm *.o a2
