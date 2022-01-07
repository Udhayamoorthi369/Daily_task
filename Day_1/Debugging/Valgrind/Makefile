
CC = gcc
CFLAGS = -g -O0

all : test

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o test
