#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constante MAX que define el tamaño máximo de los números  a generar
#define MAX 1000000
//Constante N que define el número de números a generar
#define NUMS_TO_GENERATE 101
 
int main() {
	int numeros[NUMS_TO_GENERATE] = { 0 }, N, pos, temp; 


	printf("Este programa genera %d números aleatorios y los ordena usando el algoritmo de ordenamiento por insercción:\n", NUMS_TO_GENERATE-1);
	printf("Arreglo de números generados:\n ");

    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX;
 		
		numeros[i] = N;

    	printf("%d.- %d\n ",i, N);

		//i como la cantidad de números generados
		//N como los números generados
	}
	
	//Algoritmo insercción
	for (int i = 0; i < NUMS_TO_GENERATE ; i++) //Recorrer
	{
    	pos = i; //pos == 0 //Posición en matriz
    	temp = numeros[i]; //temp == 4 //Valor dentro de la matriz
    
   		//mientras 1>0 y arr 8 > 2 --- 2 <> 8
   		while ((pos>0)&&numeros[pos-1]>temp) // //Número izquierda
    	{
      	numeros[pos] = numeros[pos-1]; //2 a la posison 0 
        pos--; //0
    	}
   		numeros[pos]=temp; //2
	}

	//Imprimir arreglo ordenado
	printf("\n\nOrdenados:\n ");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n ", i, numeros[i]);	
	}
	
    exit(EXIT_SUCCESS);
}
