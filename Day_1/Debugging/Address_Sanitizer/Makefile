
CC = gcc
CFLAGS = -g -fsanitize=address -static-libasan

all : test

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o test
