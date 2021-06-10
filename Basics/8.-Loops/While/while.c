/*
	Ciclo While: El bucle While es una estructura de control en programación
	en la que se puede indicar de antemano el 
	número máximo de iteraciones.
	Tienes la ventaja de que puede ser de cualquier tipo de dato numérico y no
	solo int como el cilo for.
*/

#include <stdio.h>

int main(){

	int contador = 1; //Se inicializa la variable contador en 1

	while(contador <= 10) //Se condiciona el bloque de código, mientas contador sea menor o igual a 10
		{
		printf("%i\n",contador);

		contador++; //Se adhiere 1 a contador
		}

	return 0;
}
