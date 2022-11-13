/*
	Ciclo for: El bucle for es una estructura de control en programación
	en la que se puede indicar de antemano el 
	número máximo de iteraciones
*/

#include <stdio.h>

int main(){
	
	int contador; //Se inicializa la variable de tipo entero contador
	for(contador = 1; contador <= 10; contador++) //Se le asigna 1 a contador, se condiciona que contador sea menor o igual a 10 y si en cada repetición contador va a adherirse 1
	{
		printf("%i\n",contador);
	}

	return 0;

}
