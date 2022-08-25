CC=clang
CFLAGS=-g -Wall
OBJS=main.o matrix.o ui.o

all: matrix

matrix: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o matrix

