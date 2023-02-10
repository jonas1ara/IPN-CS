/*
	
	Arreglo unidimensional

	Los arreglos son un conjunto de datos que se van almacenando dentro de un variable,
	cuándo hablamos de variables imaginalo como una cajita donde se almacenan cosas, 
	se pueden modificar sus propiedades pero siempre de un solo tipo, los ARREGLOS
	nos permiten guardar muchos de estos datos, en ese caso son conocidos como 
	una entidad estática, ya que al declararlas no van a cambiar su tamaño
	mientras dura la ejecución del programa y recuerda que 
	siempre inician en la posición 0.
*/

#include <stdio.h>

int main() 
{
	int tamanioA; //Variable para el tamaño del arreglo
	printf("Ingrese el tamaño del arreglo: \n"); 
	scanf("%i", &tamanioA); 
	int edad[tamanioA]; //Definimos nuestro arreglo como un entero.
	
	for (int i = 0; i < tamanioA; i++)//Entero i inicializado en 0, si i es menor que el tamaño del arreglo SizeA y adherimos 1 al valor de i.
	{	
		printf("Ingresa el valor %i:\n", i+1); //i + 1 para que imprima desde el 1 y no desde el 0
		scanf("%i", &edad[i]);
	}
	
	printf("Los valores del arreglo son: \n");
	
	for(int i = 0; i < tamanioA; i++) 
	{
		printf("%i ", edad[i]); //Imprimir el valor de nuestro arreglo, empezando por la posición cero, hasta que termine. el guión es para separar por guiones.
	}
	printf("\n"); //Salto de línea, por mera estética.

	return 0;
}
