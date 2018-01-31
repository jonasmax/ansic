.PHONY: run clean

CC= gcc
CFLAGS= -g -ansi -pedantic -Wall -std=c89
PROG= a19

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) $(PROG).c -o $(PROG)

run: $(PROG)
	./$(PROG)

clean:
	rm *.o $(PROG)
