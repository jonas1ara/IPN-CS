#include <stdio.h>

int main() {

	int num1; //Int para definir variables de números enteros.
	int num2;
	int resultado;

	printf("Ingresa un número entero:\n");
	scanf("%d",&num1); //Scanf para leer, almacenar el valor dado por el usuario, %d: entero decimal y & operador de dirección indica donde almacenar. 
	
	printf("Ingresa otro número entero:\n");
	scanf("%d",&num2);

	resultado = num1 + num2; //Operación de adición que se almacenara en la variable resultado
	
	printf("El resultado de la suma es: %d\n",resultado); //%d para que nos imprima un entero y , la variable resultado de operación.

	return 0;	

}
