/*
	Un struct en C permite usar algo parecido a los objetos anónimos de OOP. No son clases, simplemente son
	un modo de agrupar un objeto de determinado tipo con ciertas propiedades.
*/

#include<stdio.h>

struct dog //declaración de struct
{
	//atributos o propiedades del struct
	char name[30]; 
	int age;
	float weight;
}

//Asignación de valores a los atributos del struct
//Se instancia en perro1 y perro2
dog1={"Pikachu", 10, 3.50}, dog2={"Arduino",4,2.30};

int main() 
{
	printf("El peso de %s es: %.2f Kg y tiene %i meses de edad\n ", dog1.name,dog1.weight,dog1.age);
	
	return 0;	

}

