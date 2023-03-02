# Regla principal, que se ejecutará si no ocurre nada
all:main

# Esta regla compila el programa principal
main: prueba.o main.o 
	gcc -o main prueba.o main.o 

prueba.o: prueba.c prueba.h
	gcc -c prueba.c

main.o: main.c prueba.h
	gcc -c main.c

# Regla ficticia
clean:
	rm -f main *.o
