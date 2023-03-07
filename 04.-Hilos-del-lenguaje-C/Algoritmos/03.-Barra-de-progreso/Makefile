# Regla principal, que se ejecutará si no ocurre nada
all:main

# Esta regla compila el programa principal
main: readshmem.o writeshmem.o 
	gcc -o main readshmem.o writeshmem.o 

readshmem.o: readshmem.c shared_memory.h
	gcc -c readshmem.c

writeshmem.o: writeshmem.c shared_memory.h
	gcc -c writeshmem.c

# Regla ficticia
clean:
	rm -f main *.o
