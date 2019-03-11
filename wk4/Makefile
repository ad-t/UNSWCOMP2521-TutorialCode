CC=gcc
CFLAGS=-Wall -Werror -g
BIN=build

.PHONY: all
all: file1.o
	$(CC) $(CFLAGS) -o $(BIN) file1.o

.PHONY: file1
file1.o: file1.h file1.c
	$(CC) $(CFLAGS) -c file1.c

.PHONY: clean
clean:
	rm *.o
	rm $(BIN)
