#include <stdio.h>
#include <stdbool.h>

#define MAX 8

int arr[MAX] = {35, 33, 42, 10, 14, 19, 27, 44};

void imprimirArreglo()
{
   printf("[");	
   // navegar a traves de arreglo
   for(int i = 0; i < MAX; i++) {
      printf("%d ",arr[i]);
   }
   printf("]\n");
}

void imprimirLineas(int count) 
{	
   for(int i = 0;i < count-1;i++) 
   {
      printf("=");
   }	
   printf("=\n");
}

void ordenamiento_burbuja() 
{
   int temp;
   int i,j;
   bool intercambio = false;       
   
   // Recorrer todos los elementos del arreglo
   for(i = 0; i < MAX-1; i++) 
   { 
      intercambio = false;
		
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

            intercambio = true;
            printf(" => Intecarmbiado [%d, %d]\n",arr[j],arr[j+1]);
         } else {
            printf(" => No intercambiado\n");
         }
      }

      // Si no se intercambió ningún número, eso significa
      //  Arreglo ordenado, romper el ciclo. 
      if(!intercambio) 
      {
         break;
      }
      
      printf("Iteración %d#: ",(i+1)); 
      imprimirArreglo();                     
   }    
}

int main() 
{
   printf("Ordenamiento burbuja con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   printf("\n");
   ordenamiento_burbuja();
   printf("\nArreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
}