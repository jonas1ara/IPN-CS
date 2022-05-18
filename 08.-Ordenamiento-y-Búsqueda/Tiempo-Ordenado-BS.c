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
   	int arr[NUMS_TO_GENERATE] = { 0 }, N ,aux, pos, temp;
	
	//printf("Arreglo de elementos aleatorios:\n");
	srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++)
    {
        N = rand() % MAX;
        arr[i] = N;
	}
	 
	 //Algoritmo insercción para arreglo aleatorio
	for (int i = 0; i < NUMS_TO_GENERATE ; i++) //Recorrer
	{
    	pos = i; //pos == 0 //Posición en matriz
    	temp = arr[i]; //temp == 4 //Valor dentro de la matriz
    
   		//mientras 1>0 y arr 8 > 2 --- 2 <> 8
   		while ((pos>0)&&arr[pos-1]>temp) // //Número izquierda
    	{
      	arr[pos] = arr[pos-1]; //2 a la posison 0 
        pos--; //0
    	}
   		arr[pos]=temp; //2
	}

	//Imprimir arreglo ordenado
	printf("Arreglo de números ordenados:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr[i]);	
	}
	printf("\n");

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    
	// Code to measure
	///Algoritmo Ordenamiento Burbuja
	for(int i=0; i<NUMS_TO_GENERATE; i++)
	{
		for(int j=j+1;j<NUMS_TO_GENERATE;j++)
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
