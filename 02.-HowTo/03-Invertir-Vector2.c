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
	int arr[NUMS_TO_GENERATE] = { 0 }, arr2[NUMS_TO_GENERATE], N ,pos, temp;
	
	printf("Arreglo de elementos aleatorios:\n");
	srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX;
        
        arr[i] = N;
 		
    	printf("%d.- %d\n",i, N);
	 }
	 printf("\n");
	 
	 
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
	printf("Arreglo ordenado:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr[i]);	
	}
	printf("\n");
	
	
	//Invertir el arreglo ordenado
	printf("Arreglo ordenado pero invertido:\n");
	
	int arr_length = sizeof(arr) / sizeof(int), arr2_length = sizeof(arr2) / sizeof(int); //Operación que invierte el arreglo
	
	
	int i, j;
	
	for(i = arr_length-1, j = 0; i >= 0 && j < arr2_length; i--, j++)
	{
		arr2[j] = arr[i];
		printf("%d.- %d \n", i, arr2[j]);
	}
	printf("\n");
	
	//Algoritmo insercción para arreglo inverso
	for (int i = 0; i < NUMS_TO_GENERATE ; i++) //Recorrer
	{
    	pos = i; //pos == 0 //Posición en matriz
    	temp = arr2[i]; //temp == 4 //Valor dentro de la matriz
    
   		//mientras 1>0 y arr 8 > 2 --- 2 <> 8
   		while ((pos>0)&&arr2[pos-1]>temp) // //Número izquierda
    	{
      	arr2[pos] = arr2[pos-1]; //2 a la posison 0 
        pos--; //0
    	}
   		arr2[pos]=temp; //2
	}

	//Imprimir arreglo ordenado
	printf("Arreglo invertido reordenado:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr2[i]);	
	}
	printf("\n");
	
	//Algoritmo insercción para arreglo ordenado
	for (int i = 0; i < NUMS_TO_GENERATE ; i++) //Recorrer
	{
    	pos = i; //pos == 0 //Posición en matriz
    	temp = arr2[i]; //temp == 4 //Valor dentro de la matriz
    
   		//mientras 1>0 y arr 8 > 2 --- 2 <> 8
   		while ((pos>0)&&arr2[pos-1]>temp) // //Número izquierda
    	{
      	arr2[pos] = arr2[pos-1]; //2 a la posison 0 
        pos--; //0
    	}
   		arr2[pos]=temp; //2
	}

	//Imprimir arreglo ordenado
	printf("Arreglo ordenado siendo reordenado:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr2[i]);	
	}
	printf("\n");
	
	return 0;
}


