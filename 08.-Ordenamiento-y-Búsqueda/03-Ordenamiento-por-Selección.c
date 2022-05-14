#include <stdio.h>

#define MAX 7

int arr[MAX] = {4,6,3,2,1,9,7};

void display() 
{
   int i;
   printf("[");
	
   // Navegar a tráves de todos los elementos del arreglo
   for(i = 0;i < MAX;i++) 
   {
      printf("%d ", arr[i]);
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

/*Algoritmo de ordenamiento por selección*/
/*Divide el arreglo en dos, consiste en encontrar el elemento más pequeño dentro del subarreglo desordenado 
y lo mueve al último indice del subarreglo ordenado*/

void selectionSort() 
{
   int indexMin,i,j;
	
   // Ciclo a tráves de todos los elementos del arreglo
   for(i = 0; i < MAX-1; i++) 
   { 
      //  Establecer el elemento actual como el mínimo
      indexMin = i;
		
      // Compruebe que el elemento sea mínimo
      for(j = i+1;j < MAX;j++) 
      {
         if(arr[j] < arr[indexMin]) 
         {
            indexMin = j;
         }
      }

      if(indexMin != i) 
      {
         printf("Elementos intercambiados: [ %d, %d ]\n" , arr[i], arr[indexMin]); 
			
         // Intercambio de números 
         int temp = arr[indexMin];
         arr[indexMin] = arr[i];
         arr[i] = temp;
      }          

      printf("Iteración %d#:",(i+1));
      display();
   }
}  

int main() 
{
   printf("Ordenamiento por selección con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   display();
   printline(50);
   selectionSort();
   printf("Arreglo de salida: ");
   display();
   printline(50);
}