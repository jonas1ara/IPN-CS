#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 100
 
int main () {
    double sum = 0;
    double add = 1;

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    /*
	Code to measure
	*/
	//Declaro variables enteras y un arreglo que esta definido por una constante
   int numeros[NUMS_TO_GENERATE] = { 0 }, N, aux ;

	printf("Este programa genera %d números aleatorios y los ordenada usando el algoritmo de ordenamiento por selección", NUMS_TO_GENERATE);
	printf("\n\nArreglo de elementos desordenados:\n ");

	//Genaramos números aleatorios
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        //Asigno el número aleatorio a N
		N = rand() % MAX;
		//Asigno el valor del N al arreglo para almacenarlos
 		numeros[i] = N;  
    	printf("%d.- %d\n ",i, N);

	 }
	 //Algoritmo Ordenamiento Burbuja
	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		for(int j=0;j<NUMS_TO_GENERATE;j++)
		{
			if(numeros[j] > numeros [j+1])
			{
				aux = numeros [j+1];
				numeros[j+1] = numeros[j];
				numeros[j] = aux;
			}
		}
	}

	printf("\n\nOrdenados:\n ");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.-%d\n ", i, numeros[i]);	
	}
    
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
	printf("\n");

    printf("Result: %.20f\n", sum);
    
    printf("Time measured: %.3f seconds.\n", elapsed);
    
    return 0;
}
