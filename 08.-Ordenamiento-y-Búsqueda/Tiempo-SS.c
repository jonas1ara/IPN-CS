#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constante MAX que define el tamaño máximo de los números  a generar
#define MAX 1000000
//Constante N que define el número de números a generar
#define NUMS_TO_GENERATE 101
 
int main() {
	int numeros[NUMS_TO_GENERATE] = { 0 }, N, temp, minimo ;


	printf("Este programa genera %d números aleatorios y los ordenada usando el algoritmo de ordenamiento por selección:\n", NUMS_TO_GENERATE-1);
	printf("Arreglo de números generados:\n ");

    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX;
 		
		numeros[i] = N;

    	printf("%d.- %d\n ",i, N);

		//i como la cantidad de números generados
		//N como los números generados
	}
	
	 //Algoritmo de seleccion
    for(int i=0; i<NUMS_TO_GENERATE; i++)
    {
        // Posición del número más pequeño
        minimo = i;

        // Ejecutar un bucle interno j para la ordenación por selección de i+1 a N
        for(int j=i+1; j<NUMS_TO_GENERATE; j++)
        {
            // Ahora compruebe si el valor en num[j] es menor que el valor en num[temp]
            if(numeros[minimo]>numeros[j])
            {
                // Si el valor es menor, almacene el valor de j en minimo
                minimo = j;
            }
        }
            temp = numeros[i];
            numeros[i]= numeros[minimo];
            numeros[minimo]=temp;
    }

	printf("\n\nOrdenados:\n ");

	for(int i=0;i<NUMS_TO_GENERATE;i++)
	{
		printf("%d.- %d\n ", i, numeros[i]);	
	}
	
    exit(EXIT_SUCCESS);
}
