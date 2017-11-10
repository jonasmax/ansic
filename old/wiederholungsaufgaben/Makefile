CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

all: a2 a3 a1

a1: a1.o
	$(CC) $(CFLAGS) a1.o -o a1
	
a1.o: a1.c
	$(CC) -c $(CFLAGS) a1.c -o a1.o

a2: a2.o
	$(CC) $(CFLAGS) a2.o -o a2
	
a2.o: a2.c
	$(CC) -c $(CFLAGS) a2.c -o a2.o
	
a3: a3.o
	$(CC) $(CFLAGS) a3.o -o a3
	
a3.o: a3.c
	$(CC) -c $(CFLAGS) a3.c -o a3.o

clean:
	-/bin/rm *.o a1 a2 a3
