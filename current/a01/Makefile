.PHONY: run clean

CC= ggc
CFLAGS= -g -ansi -pedantic -Wall
PROG=a03

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) $(PROG).c -o $(PROG)
    
run: $(PROG)
	./$(PROG)
	
clean:
	rm $(PROG)
