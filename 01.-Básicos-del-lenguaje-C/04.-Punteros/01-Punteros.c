//Intercambia los valores de dos valores con una función, el principal uso de los punteros es para trabajar con referencias en las funciones

#include <stdio.h>


void cambio(int *a, int *b, int z);

int main()
{

	//* señalan y & son la dirección de memoria
	int i, *j,  x, y, z;
	
	i = 4;
	j = &i;
	//Es decir en j se metio el valor de la dirección de i, y el puntero esta apuntando EL VALOR a esa dirección
	printf("El valor de *j es %i y el valor de la dirección de memoria de *j es %p \n\n",*j, j);

	x = 5;
	y = 10;
	z = 20;

	printf("X vale: %i, Y vale: %i y Z vale: %i\n\n", x,y,z);
	cambio(&x, &y, z);

	printf("El valor actual de X es %i, el valor actual de Y es %i y el valor de Z es %i\n \n", x, y, z);


	
	return 0;
}

//En una función normal los valores del main se pasan a la función, no tienen nada que ver, pero en una con paso por referencia, las variables del main y la de función comparten el mismo espacio de memoria.

void cambio(int *a, int *b, int c) //a = &x y por tanto *a será lo mismo que x.
{
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;

	c = 100;
}

