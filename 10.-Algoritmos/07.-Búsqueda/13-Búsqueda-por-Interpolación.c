#include<stdio.h>

#define MAX 20

// Conjunto de elementos sobre los que se realizará la búsqueda por interpolación 
int list[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

int find(int data) 
{
   int lo = 0;
   int hi = MAX - 1;
   int mid = -1;
   int comparisons = 1;      
   int index = -1;

   while(lo <= hi) 
   {
      printf("\nComparación %d  \n" , comparisons ) ;
      printf("lo : %d, list[%d] = %d\n", lo, lo, list[lo]);
      printf("hi : %d, list[%d] = %d\n", hi, hi, list[hi]);
      
      comparisons++;

      // Sondear el punto medio 
      mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
      printf("mid = %d\n",mid);

      // Datos encontrados 
      if(list[mid] == data) 
      {
         index = mid;
         break;
      } else 
      {
         if(list[mid] < data) 
         {
            // Si los datos son más grandes, los datos están en la mitad superior 
            lo = mid + 1;
         } else 
         {
            // Si los datos son más chicos, los datos están en la mitad inferior 
            hi = mid - 1;
         }
      }               
   }
   
   printf("\nTotal de comparaciones hechas: %d", --comparisons);
   return index;
}

int main() 
{

   printf("Búsqueda por interpolación con complejidad O(log n)\n\n");

   //Encontrar la ubicación de un elemento X
   int location = find(33);

   // Si el elemento X se encuentra en el arreglo, mostrar su posición
   if(location != -1)
      printf("\nElemento encontrado en la posición: %d\n" ,(location+1));
   else
      printf("Elemento no encontrado ... \n");
   
   return 0;
}
