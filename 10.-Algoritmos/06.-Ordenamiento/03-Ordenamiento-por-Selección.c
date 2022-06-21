#include <stdio.h>

#define MAX 8

int arr[MAX] = {35, 33, 42, 10, 14, 19, 27, 44};

void imprimirArreglo() 
{
   printf("[");
	
   // Navegar a tráves de todos los elementos del arreglo
   for(int i = 0;i < MAX;i++) 
   {
      printf("%d ", arr[i]);
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

/*Algoritmo de ordenamiento por selección*/
/*Divide el arreglo en dos, consiste en encontrar el elemento más pequeño dentro del subarreglo desordenado 
y lo mueve al último indice del subarreglo ordenado*/

void ordenamiento_por_Seleccion() 
{
   int indice_Minimo,i,j;
	
   // Ciclo a tráves de todos los elementos del arreglo
   for(i = 0; i < MAX-1; i++) 
   { 
      //  Establecer el elemento actual como el mínimo
      indice_Minimo = i;
		
      // Compruebe que el elemento sea mínimo
      for(j = i+1;j < MAX;j++) 
      {
         if(arr[j] < arr[indice_Minimo]) 
         {
            indice_Minimo = j;
         }
      }

      if(indice_Minimo != i) 
      {
         printf("Elementos intercambiados: [ %d, %d ]\n" , arr[i], arr[indice_Minimo]); 
			
         // Intercambio de números 
         int temp = arr[indice_Minimo];
         arr[indice_Minimo] = arr[i];
         arr[i] = temp;
      }          

      printf("Iteración %d#:",(i+1));
      imprimirArreglo();
   }
}  

int main() 
{
   printf("Ordenamiento por selección con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   ordenamiento_por_Seleccion();
   printf("Arreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
}