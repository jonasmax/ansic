.PHONY: run clean

CC= gcc
CFLAGS= -g -ansi -pedantic -Wall
PROG=a15

$(PROG): $(PROG).o list.o
	$(CC) $(CFLAGS) $(PROG).0 list.o -o $(PROG)

$(PROG).o: $(PROG).c list.h
	$(CC) $(CFLAGS) $(PROG).c -o $(PROG).o

list.o: list.c list.h
	$(CC) $(CFLAGS) list.c -o list.o

run: $(PROG)
	./$(PROG)
	

clean:
	rm *.o $(PROG)
	
