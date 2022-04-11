/*

	C provee el operador binario para determinar el tamño en bytes de un arreglo o cualquier otro tipo de dato

sizeof(array); returns: 80 ---> the size of the entire array.
sizeof(ptr);   returns: 8  ---> the size of the pointer or pointer.
sizeof(*ptr);  returns: 4  --->the size of the first object in the array (the "pointers" point only to one object in the array, which by default is the first).

*/

#include <stdio.h>

size_t getsize(float *ptr); //Prototipo de la función

int main() 
{	
	float array[20]; //Arreglo de tipo flotante
	printf("El número de bytes en el array es: %lu\n", getsize(array)); //Imprimimos el valor de nuestro array, enviando la llamada a la función getsize y pasandola al mismo array

	printf("El número de bytes en el array es: %lu \n", sizeof(array)); //largo sin firmar nos permitirá poder imprimir el valor en bytes y como parámetro le pasamos el arreglo flotante, ya que al usar flotante almacena 4 bytes y lo multiplica por el tamaño del arreglo
	
	return 0;
}
size_t getsize(float *ptr)
{ //Function of type size that receives our float type array by making it our pointer, size_t is a type defined by the standard of C as an integer type and the value we must return must not have a sign
	
	return sizeof(*ptr);// We return the sizeof of our pointer.

}




























