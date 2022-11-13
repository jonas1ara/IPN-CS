//Programa para almacenar las notas de un alumno

#include <stdio.h>

//Definimos el tipo de datos "notas"
typedef struct
{
	int matematicas;
	int ingles;
	int fisica;
} notas;

//normalmente se declara la variable not de tipo "notas", fuera de cualquier función para usarla como global, y asi te evitas hacer pasos por referencia
//notas not;

void darnotas(notas *not);

int main()
{
	notas not; //Declaramos la variable not de tipo "notas", al crearla dentro de la función, solo existira en el ambito de la función, si queremos ocupar esa struct se necesitará hacer un paso por referencia
	darnotas(&not); //Llamamos a la funcion darnotas y le pasamos por referencia la direccion de memoria de la variable not
	
	printf("(Main)La nota de física es: %i\n", not.fisica); //Cuándo se imprime en el main una variable que esta dentro de una estructura, se ocupa el punto
	
	return 0;
}

//void darnotas(notas not) Si se usa así, se crea una copia y se hace mál uso de la memoria
void darnotas(notas *not)//Si lo usas así, se ocupa el mismo objeto en todo el programa y se hace buen uso de la memoria
{
	printf("Introduzca la nota de matemáticas: ");
	scanf("%i", &not->matematicas); //Cuándo se guarda el valor de una variable que esta dentro de una estructura, se ocupa -> para apuntar a la variable

	printf("Introduzca la nota de inglés: ");
	scanf("%i", &not->ingles);

	printf("Introduzca la nota de física: ");
	scanf("%i", &not->fisica);

	printf("La nota de matemáticas es: %i\n", (*not).matematicas);	//Cuándo se imprime en la funcion una variable que esta dentro de una estructura, se ocupa el punto
	printf("La nota de inglés es: %i\n", not->ingles); //O se puede ocupar -> para apuntar a la variable
}
