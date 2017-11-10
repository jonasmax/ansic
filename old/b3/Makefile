CC=gcc
CFLAGS= -Wall -g -std=c99 -Wvla

all: a3 a4 a5

a3: a3.o
	$(CC) $(CFLAGS) a3.o -o a3
	
a3.o: a3.c
	$(CC) -c $(CFLAGS) a3.c -o a3.o

a4: a4.o
	$(CC) $(CFLAGS) a4.o -o a4
	
a4.o: a4.c
	$(CC) -c $(CFLAGS) a4.c -o a4.o

a5: a5.o
	$(CC) $(CFLAGS) a5.o -o a5
	
a5.o: a5.c
	$(CC) -c $(CFLAGS) a5.c -o a5.o

clean:
	-/bin/rm *.o a3 a4 a5
