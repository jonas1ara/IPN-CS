# Regla principal, que se ejecutará si no ocurre nada
all:main

# Esta regla compila el programa principal
main: hola-make.o func-hola.o 
	gcc -o main hola-make.o func-hola.o 

hola-make.o: hola-make.c hola-make.h
	gcc -c hola-make.c

func-hola.o: func-hola.c hola-make.h
	gcc -c func-hola.c

# Regla ficticia
clean:
	rm -f main *.o

