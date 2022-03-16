/*
	//Llamadas por referencia; para elevar un número al cubo.

	Muchas funciones requieren la capacidad de modificar una o más variables en una llamada de función en ese caso que podemos evitar sobre cargas están haciendo copias del objeto o nuestra variable.

*/


#include <stdio.h>

void cubo(int *n); //Prototipo de nuestra función, argumento de apuntador.

int main() 
{	
	int num = 5;
	printf("Valor original: %i\n",num);
	cubo(&num); //Le deciamos a num que le asigne el valor devuelto por la función, haga referencia con &
	printf("El nuevo valor: %i\n", num);
	
	return 0;	

}
void cubo(int *n) ///Valor VOID no son necesarios para devolver un valor, recibirá el parámetro que enviamos anteriormente y lo utilizará como *n
	{
	
	*n = *n * *n * *n;

	}


