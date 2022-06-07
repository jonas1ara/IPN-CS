#include <stdio.h>

#define MAX 7

int arr[MAX] = {4,6,3,2,1,9,7};

void display() 
{
   int i;
   printf("[");
	
   // Navegar a través de todos los elementos del arreglo
   for(i = 0;i < MAX;i++) 
   {
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

void shellSort() 
{
   int inner, outer;
   int valueToInsert;
   int interval = 1;   
   int elements = MAX;
   int i = 0;
   
   while(interval <= elements/3) 
   {
      interval = interval*3 +1;
   }

   while(interval > 0) {
      printf("Iteración %d#:",i); 
      display();
      
      for(outer = interval; outer < elements; outer++) 
      {
         valueToInsert = arr[outer];
         inner = outer;
			
         while(inner > interval -1 && arr[inner - interval] 
            >= valueToInsert) {
            arr[inner] = arr[inner - interval];
            inner -=interval;
            printf(" Elemento movido :%d\n",arr[inner]);
         }
         
         arr[inner] = valueToInsert;
         printf(" Elemento insertado :%d, at position :%d\n",valueToInsert,inner);
      }
		
      interval = (interval -1) /3;
      i++;
   }          
}

int main() 
{
   printf("Ordenamiento burbuja con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: ");
   display();
   printline(50);
   shellSort();
   printf("Arreglo de salida: ");
   display();
   printline(50);
   return 1;
}