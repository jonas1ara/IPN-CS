#include <stdio.h>

void ordenar (int v[]);
void imprimir (int v[]);

#define Length 10


int main()
{
	int v[Length] = {4,7,8,9,6,5,2,1,3,0};
	imprimir (v);

	ordenar (v);
	imprimir (v);

	return 0;
}

void ordenar(int v[])
{
	int i, j, aux;

	for (i = 0; i < Length; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

void imprimir(int v[])
{
	int i;
	
	for (i=0; i < Length; i++)
	{
		printf("%i ", v[i]);
	}
	printf("\n");
}

