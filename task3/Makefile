CC=gcc
CFLAGS=-Wall -fopenmp

all: gauss prime

gauss: gauss.c
	$(CC) $(CFLAGS) -o gauss gauss.c

prime: prime.c
	$(CC) $(CFLAGS) -o prime prime.c

clean:
	$(RM) gauss prime
