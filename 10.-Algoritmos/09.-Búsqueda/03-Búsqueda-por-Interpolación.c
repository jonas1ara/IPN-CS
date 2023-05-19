#include<stdio.h>

#define MAX 20

// Conjunto de elementos sobre los que se realizará la búsqueda por interpolación 
int arr[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

int find(int data) 
{
   int limiteInferior = 0;
   int limiteSuperior = MAX - 1;
   int puntoMedio = -1;
   int comparacion = 1;      
   int index = -1;

   while(limiteInferior <= limiteSuperior) 
   {
      printf("\nComparación %d  \n" , comparacion ) ;
      printf("Limite inferior : %d, arr[%d] = %d\n", limiteInferior, limiteInferior, arr[limiteInferior]);
      printf("Limite superior : %d, arr[%d] = %d\n", limiteSuperior, limiteSuperior, arr[limiteSuperior]);
      
      comparacion++;

      // Sondear el punto medio 
      puntoMedio = limiteInferior + (((double)(limiteSuperior - limiteInferior) / (arr[limiteSuperior] - arr[limiteInferior])) * (data - arr[limiteInferior]));
      printf("puntoMedio = %d\n",puntoMedio);

      // Datos encontrados 
      if(arr[puntoMedio] == data) 
      {
         index = puntoMedio;
         break;
      } else 
      {
         if(arr[puntoMedio] < data) 
         {
            // Si los datos son más grandes, los datos están en la mitad superior 
            limiteInferior = puntoMedio + 1;
         } else 
         {
            // Si los datos son más chicos, los datos están en la mitad inferior 
            limiteSuperior = puntoMedio - 1;
         }
      }               
   }
   
   printf("\nTotal de comparaciones hechas: %d", --comparacion);
   return index;
}

int main() 
{

   printf("Búsqueda por interpolación con complejidad O(log n)\n\n");

   //Encontrar la ubicación de un elemento X
   int location = find(55);

   // Si el elemento X se encuentra en el arreglo, mostrar su posición
   if(location != -1)
      printf("\nElemento encontrado en la posición: %d\n" ,(location+1));
   else
      printf("Elemento no encontrado ... \n");
   
   return 0;
}
