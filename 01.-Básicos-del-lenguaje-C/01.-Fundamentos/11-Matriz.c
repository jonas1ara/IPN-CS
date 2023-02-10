/*
	Matriz, arreglos en dos dimensiones
	
	Los arreglos son un conjunto de datos que se van almacenando dentro de un variable,
	cuándo hablamos de arreglos imaginalo como una cajita donde se almacenan cosas, 
	se pueden modificar sus propiedades pero siempre de un solo tipo, los ARREGLOS
	nos permiten guardar muchos de estos datos, en ese caso son conocidos como 
	una entidad estática, ya que al declararlas no van a cambiar su tamaño
	mientras dura la ejecución del programa y recuerda que siempre inician en la posición 0.
	Arreglo multidimensional, piensa en los arreglos multidimensionales como coordenadas y 
	recuerda que este se define por tener dos corchetes.
*/

#include<stdio.h>

int main()
{
	/*	
		Sistemas de coordenadas
			Col...  0 1 2 // Columnas tienen el valor vertical
			Fila 0 |5 3 1 // Valor horizontal
			Fila 1 |6 4 2 // Valor horizantal
	*/
	int multi[2][3] = {{5, 3, 1},{6, 4, 2}}; 
	//La primeras llaves  quedan en la fila 0 y así sucesivamente, dentro de una llave que engloba las dos filas
	//El primer corchete define el número de filas
	//El segundo corchete define el número de columnas

	printf("%i\n", multi[0][0]); //Imprimos el valor en entero del arreglo multi

	return 0;
}
