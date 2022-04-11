/*
	Conversión de datos en C
*/

#include <stdio.h>

int main () {
	
	int a = 80; //Se inicializa la variable a en 80
	float f = 45.3; //Se inicializa la variable flotante 43.5
	float sum = (float)a + f; //Aderimos (float)a para convertir el entero a en flotante y sumarlo con el entero f

	printf("Esta es la suma: %.3f\n",sum);

	printf("\nY estos son el entero convertido: \nEntero: %i\nFlotante: %.2f\nDoble: %.3f\nCarácter: %c\n",a, (float)a, (double)a, (char)a);

	return 0;


}
