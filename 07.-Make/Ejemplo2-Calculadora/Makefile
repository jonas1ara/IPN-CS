OBJS = main.o salida.o calculadora.o 
BINARY = main
CC = clang
CFLAGS = -g -Wall

all: main

main: $(OBJS)
	$(CC) -o $(BINARY) $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f main $(BINARY) $(OBJS)
