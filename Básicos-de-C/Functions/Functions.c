/*Funciones son usadas para hacer una operación particular*/

#include <stdio.h> //directiva include

int suma(); //prototipo de la función suma 

void greeting() { //Palabra reservada void, función que no retorna un tipo de valor fijo
	
	printf("hola androide #%i\n", suma());

}

int main() {

	greeting();

	return 0;
}

int suma() {
	int num1 = 12;
	int num2 = 4;
	int sum = num1 + num2;

	return sum;	//Retorna el variable de la función

}
