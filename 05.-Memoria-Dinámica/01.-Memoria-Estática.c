#include <stdio.h>

int main()
{
	//Memoria Estática


	int i ;
	int N = 50; //No importa cuantos elementos estes ocupando siempre ocupa espacio en la memoria
	int vector[N];
		
	for (i = 0; i < N; i++)
	{
		vector[i] = i;
	}
	
	for (i = 0; i < N; i++)
	{
		printf("%i, ", vector[i]);
	}
	printf("\n");


	return 0;
}
