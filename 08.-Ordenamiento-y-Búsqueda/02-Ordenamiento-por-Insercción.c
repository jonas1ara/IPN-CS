#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count) {
   int i;
	
   for(i = 0;i < count-1;i++) {
      printf("=");
   }
	
   printf("=\n");
}

void display() {
   int i;
   printf("[");
	
   // Navegar a través del arreglo 
   for(i = 0;i < MAX;i++) {
      printf("%d ",intArray[i]);
   }
	
   printf("]\n");
}

void insertionSort() {

   int valueToInsert;
   int holePosition;
   int i;
  
   // Ciclo a tráves de todos los números del arreglo
   for(i = 1; i < MAX; i++) { 
	
      // Selecciona un valor para ser insertado 
      valueToInsert = intArray[i];
		
      // Selecciona el espacio donde el valor será insertado 
      holePosition = i;
		
      // Comprobar si el anterior no es mayor que el valor a insertar 
      while (holePosition > 0 && intArray[holePosition-1] > valueToInsert) {
         intArray[holePosition] = intArray[holePosition-1];
         holePosition--;
         printf(" item moved : %d\n" , intArray[holePosition]);
      }

      if(holePosition != i) {
         printf(" item inserted : %d, at position : %d\n" , valueToInsert,holePosition);
         // Inserte el número en la posición del agujero
         intArray[holePosition] = valueToInsert;
      }

      printf("Iteration %d#:",i);
      display();
		
   }  
}

void main() {
   printf("Input Array: ");
   display();
   printline(50);
   insertionSort();
   printf("Output Array: ");
   display();
   printline(50);
}