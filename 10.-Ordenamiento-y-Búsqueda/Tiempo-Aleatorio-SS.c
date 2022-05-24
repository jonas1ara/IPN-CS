#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

//Constante MAX que define el tamaño máximo de los números  a generar
#define MAX 1000000
//Constante N que define el número de números a generar
#define NUMS_TO_GENERATE 100000

int main () {
    double sum = 0;
    double add = 1;
    
    int arr[NUMS_TO_GENERATE] = { 0 }, N, temp, minimo ;

	printf("Este programa genera %d números aleatorios y los ordenada usando el algoritmo de ordenamiento por selección:\n", NUMS_TO_GENERATE);
	printf("Arreglo de números aleatorios:\n ");

    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++)
    {
        N = rand() % MAX;	
		arr[i] = N;
    	printf("%d.- %d\n",i, N);

		//i como la cantidad de números generados
		//N como los números generados
	}
	printf("\n");

    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    //Code to measure
   	
	
	 //Algoritmo de ordenamiento por selección
    for(int i=0; i<NUMS_TO_GENERATE; i++)
    {
        // Posición del número más pequeño
        minimo = i;

        // Ejecutar un bucle interno j para la ordenación por selección de i+1 a N
        for(int j=i+1; j<NUMS_TO_GENERATE; j++)
        {
            // Ahora compruebe si el valor en num[j] es menor que el valor en num[temp]
            if(arr[minimo]>arr[j])
            {
                // Si el valor es menor, almacene el valor de j en minimo
                minimo = j;
            }
        }
            temp = arr[i];
            arr[i]= arr[minimo];
            arr[minimo]=temp;
    }

	printf("Ordenados por ordenamiento de selección:\n");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n", i, arr[i]);	
	}
	printf("\n");
   
    
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Result: %.20f\n", sum);
    
    printf("Time measured: %.3f seconds.\n", elapsed);
    
    return 0;
}
