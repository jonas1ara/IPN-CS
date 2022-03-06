//Uso de malloc() en C.

#include <stdio.h>
#include <stdlib.h>

int main()
{

	//Si usamos otros tipo de dato, se cambia támbien en el sizeof
	int *a;

	//Reservar memoria en la áquina
	a = malloc(sizeof(int)); //Tamaño de una variable entera
	
	*a = 5;

	printf("%i \n",*a);
	
	return 0;
}
