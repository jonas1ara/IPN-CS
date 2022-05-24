#include <stdio.h>
unsigned long long collatz(unsigned long long numero)
{
	// https://parzibyte.me/blog
	unsigned long long iteraciones = 0;
	while (numero != 1)
	{
		if (numero % 2 == 0)
		{
			numero = numero / 2;
		}
		else
		{
			numero = (3 * numero) + 1;
		}
		// Si no quieres imprimir, simplemente elimina o comenta la siguiente línea
		printf("%llu,", numero);
		iteraciones++;
	}
	return iteraciones;
}

int main()
{
	unsigned long long numero = 27;
	unsigned long long iteraciones = collatz(numero);
	printf("\nLas iteraciones para llegar a 1 desde %llu fueron: %llu\n", numero, iteraciones);
	return 0;
}