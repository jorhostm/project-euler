CC = clang
CFLAGS = -pipe -flto -Wall -march=native
srcPath = src
names = $(shell find $(srcPath) -iname "*.c")

main:	main.c main.h $(names)
	$(CC) -O0 $(CFLAGS) main.c $(names) -o $@

run: main
	./$<

debug: main.c main.h $(names)
	$(CC) -g $(CFLAGS) main.c $(names) -o main

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o 

.phony: clean