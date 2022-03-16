/*
	Estructuras anidadas
*/

#include <stdio.h>
#define length 2

struct dueño 
{
	char name[20];
	char direction[30];
}; //Punto y coma para separar del siguiente struct
struct dog 
{
	char name[20];
	int age;
	struct dueño dueñoDog; //Estructura anidada --> dueñoDog
}
//Tamaño del arreglo
dogs[length];

int main() 
{
	for(int i = 0; i < length; i++) 
	{
		printf("Nombre del perro:\n");
		scanf("%s",dogs[i].name); //Sintaxis para guardar en un arreglo de structs
		printf("Edad del perro en meses:\n");
		scanf("%i",&dogs[i].age); 
		printf("Nombre del dueño: \n");
		scanf("%s",dogs[i].dueñoDog.name); //Sintaxis para guardar en un arreglo de structs anidados
		printf("Dirección del dueño: \n");
		scanf("%s",dogs[i].dueñoDog.direction);
		printf("\n"); 
	}
	for(int i = 0; i < length; i++) 
	{
			printf("Nombre del perro:  %s\n",dogs[i].name);	
			printf("Edad del perro en meses es: %i\n",dogs[i].age);
			printf("Nombre del dueño: %s\n",dogs[i].dueñoDog.name);	
			printf("Direccipón del dueño: %s\n", dogs[i].dueñoDog.direction);
			printf("\n");
		}
	return 0;
}
