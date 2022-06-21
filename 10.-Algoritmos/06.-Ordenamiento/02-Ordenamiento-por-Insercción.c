#include <stdio.h>

#define MAX 8

int arr[MAX] = {35, 33, 42, 10, 14, 19, 27, 44};

void imprimirArreglo() 
{
   printf("[");
   // Navegar a través del arreglo 
   for(int i = 0;i < MAX;i++) {
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

/*Algoritmo de ordenamiento por insercción*/
/*Divide el arreglo en dos y toma un elemento del subarreglo desordenado a la vez y 
lo inserta en su posición correcta en el subarreglo ordenado*/

void ordenamiento_por_inserccion() 
{
   int valor_a_insertar;
   int posicion_a_insertar;
  
   // Ciclo a tráves de todos los números del arreglo
   for(int i = 1; i < MAX; i++) { 
	
      // Selecciona un valor para ser insertado 
      valor_a_insertar = arr[i];
		
      // Selecciona el espacio donde el valor será insertado 
      posicion_a_insertar = i;
		
      // Comprobar si el anterior no es mayor que el valor a insertar 
      while (posicion_a_insertar > 0 && arr[posicion_a_insertar-1] > valor_a_insertar) 
      {
         arr[posicion_a_insertar] = arr[posicion_a_insertar-1];
         posicion_a_insertar--;
         printf(" Elementos movidos : %d\n" , arr[posicion_a_insertar]);
      }

      if(posicion_a_insertar != i) 
      {
         printf(" Elemento insertado : %d, en la posición: %d\n" , valor_a_insertar,posicion_a_insertar);
         // Inserte el número en la posición del agujero
         arr[posicion_a_insertar] = valor_a_insertar;
      }
      printf("Iteración %d#:",i);
      imprimirArreglo();
   }  
}

int main() 
{
   printf("Ordenamiento por insercción con complejidad O(n²) \n\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   ordenamiento_por_inserccion();
   printf("Arreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
}