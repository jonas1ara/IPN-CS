#include <stdio.h>

int factorial(int n)
{
	if( n < 2 )
		return 1;
	else
		return n * factorial(n-1);
}

int main()
{
	int resultado = factorial(5);

	printf("Resultado: %d\n", resultado);

	return 0;
}