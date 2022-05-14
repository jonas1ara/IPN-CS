#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int arr[MAX] = {4,6,3,2,1,9,7};

void display()
{
   int i;
   printf("[");
	
   // navegar a traves de arreglo
   for(i = 0; i < MAX; i++) {
      printf("%d ",arr[i]);
   }
	
   printf("]\n");
}

void bubbleSort() 
{
   int temp;
   int i,j;
   bool swapped = false;       
   
   // Recorrer todos los elementos del arreglo
   for(i = 0; i < MAX-1; i++) 
   { 
      swapped = false;
		
      // Recorrer los números que se adelantan
      for(j = 0; j < MAX-1-i; j++) 
      {
         printf("Elementos : [ %d, %d ] ", arr[j],arr[j+1]);

         // Checar si el número siguiente es menor que el actual
         //   Intercambiar los números 
         //  (Sube el número más alto) 
			
         if(arr[j] > arr[j+1]) 
         {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;

            swapped = true;
            printf(" => Intecarmbiado [%d, %d]\n",arr[j],arr[j+1]);
         } else {
            printf(" => No intercambiado\n");
         }
      }

      // Si no se intercambió ningún número, eso significa
      //  Arreglo ordenado, romper el ciclo. 
      if(!swapped) 
      {
         break;
      }
      
      printf("Iteración %d#: ",(i+1)); 
      display();                     
   }    
}

int main() 
{
   printf("Ordenamiento burbuja con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   display();
   printf("\n");
   bubbleSort();
   printf("\nArreglo de salida: ");
   display();
}