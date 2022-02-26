/*
	Los arreglos son un conjunto de datos que se van almacenando dentro de un variable,
	cuándo hablamos de variables imaginalo como una cajita donde se almacenan cosas, 
	se pueden modificar sus propiedades pero siempre de un solo tipo, los ARREGLOS
	nos permiten guardar muchos de estos datos, en ese caso son conocidos como 
	una entidad estática, ya que al declararlas no van a cambiar su tamaño
	mientras dura la ejecución del programa y recuerda que 
	siempre inician en la posición 0.
*/

//Arreglo unidimensional.

#include <stdio.h>

int main() 
{
		
	int SizeA; //Inicializo una variable entera llamada SizeA
	printf("Ingrese el tamaño del arreglo: \n"); //Pedimos al usuario el tamaño del arreglo
	scanf("%i", &SizeA); //Guardamos el valor introducido por el usuario en SizeA
	int edad[SizeA]; //Definimos nuestro arreglo como un entero, dentro de los corchetes va la variable.
	
	for (int i = 0; i < SizeA; i++)//Entero i inicializado en 0, si i es menor que el tamaño del arreglo SizeA y adherimos 1 al valor de i.
	{	//Ahora, vamos a rellenar el arreglo.
		printf("Ingresa el valor %i:\n", i+1); //El usuario ingresa el tamaño del arreglo i, i+1 para que itere el valor a partir de 0
		scanf("%i", &edad[i]); //Guardamos el valor introducido por el usuario en 0, recuerda que inicializamos int i = 0
	}
	printf("Los valores del arreglo son: \n"); //Imprimimoslos valores de arreglo
	for(int i = 0; i < SizeA; i++) //Definimos nuestro contador i en 0, si i es menor a SizeA y adherimos 1 al iterador
	{
		printf("%i-", edad[i]); //Imprimir el valor de nuestro arreglo, empezando por la posición cero, hasta que termine. el guión es para separar por guiones.
	}
	printf("\n"); //Salto de línea, por mera estética.

	return 0;
	
}
