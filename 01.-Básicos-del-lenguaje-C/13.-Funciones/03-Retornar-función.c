/*
	Retornar el valor de una función
*/

#include <stdio.h> 

int sum(); //prototipo de la función suma
int num3 = 5; //variable global de tipo entero

int main() 
{ 
	int num1, num2;
	
	printf("Ingresa el primer valor: \n");
	scanf("%i", &num1);

	printf("Ingresa el segundo valor:\n");
	scanf("%i", &num2);
	
	printf("El resultado es: %i\n", sum(num1,num2)); // Imprimir lo que retorna la función suma pasandole el valor de num1 y num2	

	return 0;
}

int sum (int num1, int num2) 
{	
	int suma = num1 + num2 + num3; //Sumar variable globar

	return suma; //Retornar el valor de sum
}
