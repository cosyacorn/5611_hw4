CC=gcc
CFLAGS=-Wall

gauss: gauss.c
	$(CC) $(CFLAGS) -o gauss gauss.c

test: gauss
	./gauss -n 3

clean:
	$(RM) gauss
