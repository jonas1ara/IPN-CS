/*
	Los arreglos son un conjunto de datos que se van almacenando dentro de un variable,
	cuándo hablamos de variables imaginalo como una cajita donde se almacenan cosas, 
	se pueden modificar sus propiedades pero siempre de un solo tipo, los ARREGLOS
	nos permiten guardar muchos de estos datos, en ese caso son conocidos como 
	una entidad estática, ya que al declararlas no van a cambiar su tamaño
	mientras dura la ejecución del programa y recuerda que 
	siempre inician en la posición 0.
*/

//Arreglo multidimensional, piensa en los arreglos multidimensionales como coordenadas y recuerda que este se define por tener dos corchetes.

#include<stdio.h>

int main()
{
	/*	
		Sistemas de coordenadas
			Col... 0 1 2 // Columnas tienen el valor vertical
			Fila0 |5 3 1 // Valor horizontal
			Fila1 |6 4 2 // Valor horizantal
	*/
	int multi[2][3] = {{5, 3, 1},{6, 4, 2}}; //El primer corchete contiene nuestras filas(horizantal) 2 y el segundo las columnas(vertical) 3
	//La primera fila va a contener 5,3, y 1 y la segunda fila 6,4 y 2. Estas filas se crean dentro de una llave que dentro una llave que engloba las dos filas.
	
	printf("%i\n", multi[1][1]); //Imprimos el valor en entero del arreglo multi

	return 0;
}
