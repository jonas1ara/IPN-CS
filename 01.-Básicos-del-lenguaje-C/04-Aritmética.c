/*
	Operaciones aritméticas en C
*/

#include <stdio.h>

int main() 
{	
	int num1, num2, resultado;
	int a=2;
	int b=3;
	
	printf("Ingresa un número entero:\n");	
	scanf("%d",&num1);

	printf("Ingresa otro número entero:\n");
	scanf("%d",&num2);

	resultado = a*(num1-num2) / b*(num1+num2); //Intercambia el operador aritmético; suma, resta, división y/o multiplicación.
	
	printf("El resultado de la operación es: %d\n", resultado);

	return 0;
}
