/*

	Las funciones recursivas tienen la propiedad de llamar a una versión reducida de ellas mismas

	Ejemplo del factorial de un número

	5! = 5 * 4 * 3 * 2 * 1 o  5*4! = 120
	4! = 4 * 3 * 2 * 1 * o 4*3! = 24
	3! = 3 * 2 * 1 o 3*2! = 6
	2! = 2 * 1 o 2*1! = 2
	1! = 1
	0! = 1
*/

#include <stdio.h>

int factorial(); // Prototipo de función factorial  

int main()
{
	int number;
	printf("Ingresa un número: \n");
	scanf("%i", &number);

	for (int i = 0; i <= number; i++)
	{
		printf("%i\t", factorial(i));
	}
	
	printf("\n");

	return 0;
}


// Función factorial
int factorial(int number)
{ 

	if (number <= 1)
	{
		return 1;
	}
	else
	{
		return (number * factorial(number - 1));
	}
}
