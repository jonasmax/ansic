.PHONY: run clean

CC= gcc
CFLAGS= -g -ansi -pedantic -Wall -std=c99
PROG= a16

$(PROG): $(PROG).o list.o
	$(CC) $(CFLAGS) $(PROG).o list.o -o $(PROG)

$(PROG).o: $(PROG).c list.h
	$(CC) -c $(CFLAGS) $(PROG).c -o $(PROG).o

list.o: list.c list.h
	$(CC) -c $(CFLAGS) list.c -o list.o

run: $(PROG)
	./$(PROG)
	

clean:
	rm *.o $(PROG)
	
