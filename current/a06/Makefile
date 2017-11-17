.PHONY: run clean

CC= gcc
CFLAGS= -g -ansi -pedantic -Wall
PROG=a06

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) $(PROG).c -o $(PROG)
    

run: $(PROG)
	./$(PROG)
	

clean:
	rm $(PROG)
	
