.PHONY: run clean

CC= gcc
CFLAGS= -g -ansi -pedantic -Wall
PROG=a13

$(PROG): $(PROG).o
	$(CC) $(CFLAGS) $(PROG).c -o $(PROG)

run: $(PROG)
	./$(PROG)
	

clean:
	rm *.o $(PROG)
	
