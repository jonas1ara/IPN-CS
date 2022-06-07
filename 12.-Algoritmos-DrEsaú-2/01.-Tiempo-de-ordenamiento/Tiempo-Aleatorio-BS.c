#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 100000
 
int main () {
    double sum = 0;
    double add = 1;
    
    //Declaro variables enteras y un arreglo que esta definido por una constante
   	int arr[NUMS_TO_GENERATE] = { 0 }, N, aux ;

	printf("Este programa genera %d números aleatorios y los ordenada usando el algoritmo de ordenamiento burbuja", NUMS_TO_GENERATE);
	printf("\n\nArreglo de números aleatorio:\n");

	//Genaramos números aleatorios
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++)
    {
        //Asigno el número aleatorio a N
		N = rand() % MAX;
		//Asigno el valor del N al arreglo para almacenarlos
 		arr[i] = N;  
    	printf("%d.- %d\n",i, N);
	 }
	 printf("\n");

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    //Code to measure
	
	//Algoritmo Ordenamiento Burbuja
	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		for(int j=0;j<NUMS_TO_GENERATE;j++)
		{
			if(arr[j] > arr[j+1])
			{
				aux = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = aux;
			}
		}
	}

	printf("Ordenados por el algoritmo burbuja:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.-%d\n", i, arr[i]);	
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
