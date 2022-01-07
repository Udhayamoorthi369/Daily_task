

CC = gcc
CFLAGS = -g -fsanitize=address -static-libasan

all : leak

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o leak
