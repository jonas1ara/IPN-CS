#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 10
 
int main () {
    double sum = 0;
    double add = 1;
    
    //Declaro variables enteras y un arreglo que esta definido por una constante
   	int arr[NUMS_TO_GENERATE] = { 0 }, arr2[NUMS_TO_GENERATE], N ,aux, pos, temp;
	
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
	printf("\n");
	
	//Invertir el arreglo ordenado
	printf("Arreglo de ordén inverso:\n");
	
	int arr_length = sizeof(arr) / sizeof(int), arr2_length = sizeof(arr2) / sizeof(int); //Operación que invierte el arreglo
	
	int i, j;
	
	for(i = arr_length-1, j = 0; i >= 0 && j < arr2_length; i--, j++)
	{
		arr2[j] = arr[i];
		printf("%d.- %d \n", i, arr2[j]);
	}
	printf("\n");

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    //Code to measure
	
	///Algoritmo Ordenamiento Burbuja
	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		for(int j=0;j<NUMS_TO_GENERATE;j++)
		{
			if(arr2[j] > arr2[j+1])
			{
				aux = arr2[j+1];
				arr2[j+1] = arr2[j];
				arr2[j] = aux;
			}
		}
	}

	//Imprimir arreglo ordenado
	printf("Ordenados por el algoritmo burbuja:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr2[i]);	
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
