CC = clang
CFLAGS = -pipe -flto=auto -march=native -Werror -Wall -Wextra -Wpedantic
srcPath = src
names = $(shell find $(srcPath) -iname "*.c")

main:	main.c main.h $(names)
	$(CC) -Ofast $(CFLAGS) main.c $(names) -o $@

run: main
	./$<

debug: main.c main.h $(names)
	$(CC) -g $(CFLAGS) main.c $(names) -o main

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf main

.phony: clean run debug