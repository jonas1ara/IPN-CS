#include <stdio.h> //directiva include

int sum(); //función suma
int num3 = 5; //variable global de tipo entero
int main() { //función principal

	int num1, num2;
	
	printf("Ingresa el primer valor: \n");
	scanf("%i", &num1);

	printf("Ingresa el segundo valor:\n");
	scanf("%i", &num2);
	
	printf("El resultado es: %i\n", sum(num1,num2)); // Imprimir lo que retorna la función suma	

	return 0;

}

int sum (int num1, int num2) {
	
	int sum = num1 + num2 + num3; //Add global variable

	return sum;

}
