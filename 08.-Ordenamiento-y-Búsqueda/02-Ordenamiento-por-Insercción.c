#include <stdio.h>

#define MAX 7

int arr[MAX] = {4,6,3,2,1,9,7};


void display() 
{
   int i;
   printf("[");
	
   // Navegar a través del arreglo 
   for(i = 0;i < MAX;i++) {
      printf("%d ",arr[i]);
   }
	
   printf("]\n");
}

void printline(int count) 
{
   int i;
	
   for(i = 0;i < count-1;i++) 
   {
      printf("=");
   }
	
   printf("=\n");
}

/*Algoritmo de ordenamiento por insercción*/
/*Divide el arreglo en dos y toma un elemento del subarreglo desordenado a la vez y 
lo inserta en su posición correcta en el subarreglo ordenado*/

void insertionSort() 
{
   int valueToInsert;
   int holePosition;
   int i;
  
   // Ciclo a tráves de todos los números del arreglo
   for(i = 1; i < MAX; i++) { 
	
      // Selecciona un valor para ser insertado 
      valueToInsert = arr[i];
		
      // Selecciona el espacio donde el valor será insertado 
      holePosition = i;
		
      // Comprobar si el anterior no es mayor que el valor a insertar 
      while (holePosition > 0 && arr[holePosition-1] > valueToInsert) 
      {
         arr[holePosition] = arr[holePosition-1];
         holePosition--;
         printf(" Elementos movidos : %d\n" , arr[holePosition]);
      }

      if(holePosition != i) 
      {
         printf(" Elemento insertado : %d, en la posición: %d\n" , valueToInsert,holePosition);
         // Inserte el número en la posición del agujero
         arr[holePosition] = valueToInsert;
      }

      printf("Iteración %d#:",i);
      display();
		
   }  
}

int main() 
{
   printf("Ordenamiento por insercción con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   display();
   printline(50);
   insertionSort();
   printf("Arreglo de salida: ");
   display();
   printline(50);
}