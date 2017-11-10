CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

a4: a4.o
	$(CC) $(CFLAGS) a4.o -o a4

a4.o: a4.c
	$(CC) -c $(CFLAGS) a4.c -o a4.o

clean:
	-/bin/rm *.o a4
