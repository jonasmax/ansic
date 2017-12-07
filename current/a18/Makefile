.PHONY: run clean

CC= gcc
CFLAGS= -ansi -pedantic -Wall -g -std=c89
PROG= a18

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) -DNL -DSIZE=3 $(PROG).c -o $(PROG)

run: $(PROG)
	./$(PROG)
	

clean:
	rm *.o $(PROG)
	
