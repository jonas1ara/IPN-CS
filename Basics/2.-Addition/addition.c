#include <stdio.h>

int main() {

	int num1; //Int; define variables enteras
	int num2;
	int resultado;

	printf("Ingresa un número entero:\n");
	scanf("%d",&num1); //Scanf para leer, almacenar el valor especificado por el usuario, %d: entero decimal y el operador de dirección indica dónde almacenar.
	
	printf("Ingresa otro número entero:\n");
	scanf("%d",&num2);

	resultado= num1 + num2; //Suma las variables num1 y num2 para guardarlas en resultado.
	
	printf("El resultado de la suma es: %d\n",resultado); //%d para imprimir el valor entero, <<resultado>> es variable a imprimir.

	return 0;	

}
