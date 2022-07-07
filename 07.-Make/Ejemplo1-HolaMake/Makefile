main: hellomake.o hellofunc.o 
	gcc -o main hellomake.o hellofunc.o 

hellomake.o: hellomake.c hellomake.h
	gcc -c hellomake.c

hellofunc.o: hellofunc.c hellomake.h
	gcc -c hellofunc.c

clean:
	rm -f main *.o

