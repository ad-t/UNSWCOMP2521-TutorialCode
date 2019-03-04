CC=gcc
CFLAGS=-Wall -Werror -g
BIN=bst

.PHONY: all
all: BSTree.o 
	$(CC) $(CFLAGS) -o $(BIN) BSTree.o

BSTree.o: BSTree.h BSTree.c
	$(CC) $(CFLAGS) -c BSTree.c

.PHONY: clean
clean:
	rm $(BIN)
	rm *.o
