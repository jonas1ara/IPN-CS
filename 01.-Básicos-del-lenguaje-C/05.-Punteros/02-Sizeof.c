/*

	C provee el operador binario para determinar el tamaño en bytes de un arreglo o cualquier otro tipo de dato

sizeof(array); returns: 80 ---> El tamaño del arreglo entero.
sizeof(ptr);   returns: 8  ---> El tamaño de un puntero.
sizeof(*ptr);  returns: 4  ---> El tamaño del primer objeto en el arreglo (los "punteros" solo apuntan a un objeto en el arreglo, que por defecto es el primero).

*/

#include <stdio.h>

size_t getsize(); //Prototipo de la función

int main() 
{	
	float arr[20]; //Arreglo de tipo flotante
	printf("El número de bytes en el array es: %lu\n", getsize(arr)); //Imprimimos el valor de nuestro array, enviando la llamada a la función getsize y pasandola al mismo array
	//Primer imprime el tamaño del primer objeto en el arreglo = 4
	printf("El número de bytes en el array es: %lu \n", sizeof(arr)); //largo sin firmar nos permitirá poder imprimir el valor en bytes y como parámetro le pasamos el arreglo flotante, ya que al usar flotante almacena 4 bytes y lo multiplica por el tamaño del arreglo
	//Imprime el valor del arreglo en bytes 4 * 20 = 80
	return 0;
}
size_t getsize(float *ptr)
{ //Función de tipo size que recibe nuestro array de tipo float convirtiéndolo en nuestro puntero, size_t es un tipo definido por el estándar de C como un tipo entero y el valor que debemos devolver no debe tener signo
	
	return sizeof(*ptr);// Retornamos sizeof el tamaño de todo el arreglo

}
