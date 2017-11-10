CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

all: a2 a3 a5

a2: a2.o
	$(CC) $(CFLAGS) a2.o -o a2

a2.o: a2.c
	$(CC) -c $(CFLAGS) a2.c -o a2.o

a3: a3.o
	$(CC) $(CFLAGS) a3.o -o a3

a3.o: a3.c
	$(CC) -c $(CFLAGS) a3.c -o a3.o

a5: a5.o
	$(CC) $(CFLAGS) a5.o -o a5

a5.o: a5.c
	$(CC) -c $(CFLAGS) a5.c -o a5.o

clean:
	-/bin/rm *.o a2 a3 a5
