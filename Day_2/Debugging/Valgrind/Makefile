all: memory_leak memcheck

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o memory_leak memcheck
