CC=gcc
CFLAGS=-Wall

prime: prime.c
	$(CC) $(CFLAGS) -o prime prime.c

test: prime
	./prime -n 50

clean:
	$(RM) prime
