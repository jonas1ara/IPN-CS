#include <stdio.h>

int main()
{
	//Memoria Pseudoestática


	int i ;
	int N ;
	//La diferencia esta en que yo no inicio N, lo hace el usuario
	printf("Dame un valor para N: ");
	scanf("%i", &N); 

	int vector[N];
		
	for (i = 0; i < N; i++)
	{
		vector[i] = i;
	}
	
	for (i = 0; i < N; i++)
	{
		printf("%i ", vector[i]);
	}
	printf("\n");


	return 0;
}

