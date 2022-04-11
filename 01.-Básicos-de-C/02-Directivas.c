/*
	Las directivas del procesador son todas las que contienen librerias y macros, commienzan con #
*/
#include <stdio.h>
/*
#include <math.h> //Libreria para funciones matemáticas.
#include <stdio.h> //Libreria standard de entrada y salida.
#include <time.h> //Libreria para asignar funciones de tiempo.
*/

#define PI 3.14159 //La directiva define crea constantes simbolicas: valores inmutables.

#define CUBO(a) a*a*a //Macro: Es una serie de instrucciones que se almacenan para que se puedan ejecutar secuencialmente a través de una sola llamada.
//Las macro resultan más rapidas que las funciones en tiempo de ejecución, ya que se ahorran los detalles que implica llamar o construir una función.

int main() {

	int a = 3, suma;
	suma = PI + 3;

	printf("Este es el valor de la suma entre la constante simbolica y 3: %i\n",suma);

	printf("El cubo de la variable a es:  %i\n",CUBO(a));//Se agrega la marco y manda a llamar

	return 0;

}
