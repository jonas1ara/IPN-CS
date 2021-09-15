#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 1000
 
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
	//Genaramos números aleatorios
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        //Asigno el número aleatorio a N
		N = rand() % MAX;
		//Asigno el valor del N al arreglo para almacenarlos
 		numeros[i] = N;  
    	printf("%d.- %d\n",i, N);

	 }
	 //Algoritmo Ordenamiento Burbuja
	for(int j=0;j<NUMS_TO_GENERATE;j++)
	{
		for(int k=0;k<NUMS_TO_GENERATE;k++)
		{
			if(numeros[k] > numeros [k+1])
			{
				aux = numeros [k+1];
				numeros[k+1] = numeros[k];
				numeros[k] = aux;
			}
		}
	}
	for(int j=0;j<NUMS_TO_GENERATE;j++)
	{
		printf("%d\n", numeros[j]);	
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
