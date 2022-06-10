#include <stdio.h>

#define MAX 20

// Conjunto de elementos sobre los que se realizará la búsqueda binaria
int arr[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void printline(int count) 
{
   int i;
	
   for(i = 0;i <count-1;i++) 
   {
      printf("=");
   }
	
   printf("=\n");
}

void display() 
{
   int i;
   printf("[");
	
   // Navegar a través de todos los elementos del arreglo
   for(i = 0;i<MAX;i++) 
   {
      printf("%d ",arr[i]);
   }
	
   printf("]\n");
}

int find(int data) 
{
   int limiteInferior = 0;
   int limiteSuperior = MAX -1;
   int puntoMedio = -1;
   int comparacion = 0;      
   int index = -1;
	
   while(limiteInferior <= limiteSuperior) 
   {
      printf("Comparación %d\n" , (comparacion +1) );
      printf("Límite inferior : %d, arr[%d] = %d\n",limiteInferior,limiteInferior,
         arr[limiteInferior]);
      printf("Límite superior : %d, arr[%d] = %d\n",limiteSuperior,limiteSuperior,
         arr[limiteSuperior]);
      comparacion++;
		
      // Calcular el punto medio
      // punto medio = (límite inferior + límite superior) / 2;
      //Va disminuyendo el rango de búsqueda
      puntoMedio = limiteInferior + (limiteSuperior - limiteInferior) / 2;	
		
      // Dato encontrado
      if(arr[puntoMedio] == data) 
      {
         index = puntoMedio;
         break;
      } else 
      {
         // Si los datos son más grandes
         if(arr[puntoMedio] < data) 
         {
            // Los datos están en la mitad superior
            limiteInferior = puntoMedio + 1;
         }
         // Los datos son mas pequeños
         else 
         {
            // Los datos están en la mitad inferior
            limiteSuperior = puntoMedio -1;
         }
      }               
   }
   printf("Total de comparaciones hechas: %d" , comparacion);
   return index;
}



int main() 
{
   printf("Búsqueda binaria con complejidad O(log n)\n\n");

   printf("Arreglo de entrada: ");
   display();
   printline(50);
	
   //Encontrar la ubicación del elemento X
   int location = find(55);

   // Si el elemento fue encontrado
   if(location != -1)
      printf("\nElemento encontrado en la posición: %d\n" ,(location+1));
   else
      printf("\nElemento no encontrado ... \n"); 
}