#include <stdio.h>

#define MAX 20

// Conjunto de elementos sobre los que se realizará la búsqueda lineal
int arr[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void display() {
   int i;
   printf("[");
	
   // Navegar a tráves de todos los elementos 
   for(i = 0;i<MAX;i++) // MAX = 20
   {
      printf("%d ",arr[i]);
   }
   printf("]\n");
}

void printline(int count) //Lo que manden en la función se asigna a count
{
   int i;
	
   for(i = 0;i <count-1;i++) 
   {
      printf("=");
   }
	
   printf("=\n");
}

// Esta función realiza una búsqueda lineal.
int find(int data) //Lo que manden en la función se asigna a data
{
   int comparisons = 0;
   int index = -1;
   int i;

   // Navegar a tráves de todos los elementos
   for(i = 0;i<MAX;i++) 
   {
      // Contar las comparaciones hechas
      comparisons++;
		
      // Si se encuentra el dato, se rompe el bucle
      if(data == arr[i]) 
      {
         index = i;
         break;
      }
   }   
	
   printf("Comparaciones totales hechas: %d", comparisons);
   return index;
}



int main() {
   printf("Array de entrada: ");
   display();
   printline(75);
	
   //Encontrar la ubicación de un elemento
   int location = find(50);

   // Si el elemento se encuentra en el array 
   if(location != -1)
      printf("\nElemento encontrado en la posición: %d\n" ,(location+1));
   else
      printf("\nElemento no encontrado ...\n");
}