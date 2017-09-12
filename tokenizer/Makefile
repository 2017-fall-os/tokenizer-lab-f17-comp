all: test

CFLAGS=-g -O3

test: main.o
	cc -o $@ $^

test.o: main.c
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o tokenizer *.exe *.stackdump
# only c files h files readme and makefile