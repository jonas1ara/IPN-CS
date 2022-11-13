/*
	Usar funciones para trabajar con vectores
*/

#include <stdio.h>

void ordenar ();
void imprimir ();

#define Length 10 //Tamaño del vector

int main()
{
	int arr[Length] = {4,7,8,9,6,5,2,1,3,0};
	imprimir (arr); //Imprime el arreglo desordenado

	ordenar (arr); //Retorna el arreglo ordenado
	imprimir (arr);

	return 0;
}

//Ordenamiento
void ordenar(int arr[])
{
	int i, j, aux;

	for (i = 0; i < Length; i++)
	{
		for (j = i; j < Length; j++)
		{
			if (arr[i] > arr[j])
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}
}

void imprimir(int arr[])
{
	int i;
	
	for (i=0; i < Length; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

