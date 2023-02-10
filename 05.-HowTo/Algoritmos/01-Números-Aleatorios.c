#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constante MAX que define el tamaño máximo de los números  a generar
#define MAX 1000000
//Constante N que define el número de números a generar
#define NUMS_TO_GENERATE 1000
 
int main() {

	int numeros[NUMS_TO_GENERATE] = { 0 }, N ;
	//Declara arreglo vacio del tamaño que tome NUMS_TO_GENERATE 
 
    srand(time(NULL)); //Semilla para empezar el conteo
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX; //Función rand() para generar números pseudo aleatorios desde la semilla hasta el valor que tome MAX y son almacenados en la variable N
 		
    	printf("%d.- %d\n",i, N); //Se imprime variable N y el número del número que es

	 }

    exit(EXIT_SUCCESS);
}
