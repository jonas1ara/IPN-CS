#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constante MAX que define el tamaño máximo de los números  a generar
#define MAX 1000000
//Constante N que define el número de números a generar
#define NUMS_TO_GENERATE 10

void printArr(int arr[], int length);

int main()
{
	int arr[NUMS_TO_GENERATE] = { 0 }, arr2[NUMS_TO_GENERATE], N ;
	
	srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX;
        
        arr[i] = N;
 		
    	printf("%d.- %d\n",i, N);
	 }
	 
	 printf("\n");
	
	int arr_length = sizeof(arr) / sizeof(int), arr2_length = sizeof(arr2) / sizeof(int); //Operación que invierte el arreglo
	
	
	int i, j;
	
	for(i = arr_length-1, j = 0; i >= 0 && j < arr2_length; i--, j++)
	{
		arr2[j] = arr[i];
		printf("%d.- %d \n", i, arr2[j]);
	}
	printf("\n");
	return 0;
}


