CC = clang
CFLAGS = -g -pipe -flto -Wall -march=native
srcPath = src
names = $(shell find $(srcPath) -iname "*.c")

main:	main.c $(names)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o 

.phony: clean