#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Memoria dinámica

	//Desventajas:
		//Más código engorroso == menos productividad
		//Es más lento para el procesador utilizar memoria dinámica
	//Cuando utilizar memoria dinámica
		//Cuando tengas grandes vectores lo ideal es usarala
		//Usa la memoria estática cuando sean vectores pequeños

	int i ;
	int N ;
	int *vector;

	printf("Dame un valor para N: ");
	scanf("%i",&N);

	vector = (int*)malloc(N*sizeof(int));
	if (vector == NULL)
	{
		printf("No se ha podido reservar la memoria \n");
	}
	else
	{
		for(i = 0; i < N; i++)
		{
			*(vector + i) = i;
		}
		for(i = 0; i < N; i++)
		{
			printf("%i, ",*(vector + i));
		}
		printf("\n");

		printf("Dame un valor para N: ");
		scanf("%i",&N);
				
		vector = (int*)malloc(N*sizeof(int));
		
		if (vector == NULL)
		{
			printf("No se ha podido reservar la memoria \n");
		}
		
		else
		{
			for(i = 0; i < N; i++)
			{
				*(vector + i) = i;
			}
			for(i = 0; i < N; i++)
			{
				printf("%i, ",*(vector + i));
			}
			printf("\n");
		}
	}
	
	return 0;
}


