/*
	Estructuras de arreglos
	
*/

#include<stdio.h>

struct dog //struct de tipo perro se llama dog
{
	char name[30]; //atributos
	int age;
	float weight;
}
//Declaración del arreglo "perros"
dogs[2];
int main() {
	for(int i = 0; i < 2; i++) //Primera pasada para perro 1
	{
		printf("Dame el nombre del perro %i:\n", i+1); //Puedes aumentar i al final del ciclo o acá
		scanf("%s",dogs[i].name);	
		printf("Dame la edad del perro %i en meses: \n", i+1);
		scanf("%i",&dogs[i].age);	
		printf("Dame el peso del perro %i: \n", i+1);
		scanf("%f",&dogs[i].weight);
		printf("\n");	
	} 
	for(int i = 0; i < 2; i++) //reinicias contador //Primera pasada para perro 1
	{	
		printf("El nombre del perro %i es: %s\n", i+1,dogs[i].name);
		printf("La edad en meses del perro  %i es: %i\n", i+1,dogs[i].age);
		printf("La edad del perro %i es: %.2f\n", i+1,dogs[i].weight);
		printf("\n");
	}
	
	return 0;
}
