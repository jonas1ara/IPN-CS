/*
   Función rand para generar números pseudoaleatorios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Directiva necesaria para llamar a la función RAND

int main () 
{
   int i, n;
   time_t t; //Palabra reserva time_t de la libería time.h
   
   n = 5;
   
   // Inicia el generador de número aleatorio con la semilla del tiempo actual 
   srand((unsigned) time(&t));

   /* Imprime 5 números aleatorios del 0 al 49 */
   for( i = 0 ; i < n ; i++ ) 
   {
      printf("%d.- %d\n", i, rand() % 50);
   }
   
   return(0);
}
