/*Funciones son usadas para hacer una operación particular*/

#include <stdio.h> //directiva include

int suma(); //prototipo de la función suma 

//Palabra reservada void, función que no retorna un tipo de valor fijo
void greeting() 
{ 
	
	printf("hola androide #%i\n", suma());

}

int main() 
{

	greeting();

	return 0;
}

//Función de tipo porque retorna un valor
int suma() 
{
	int num1 = 12;
	int num2 = 4;
	int sum = num1 + num2;

	return sum;	//Retorna el valor de la función

}
