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
   int interna, externa;
   int valoraInsertar;
   int intervalo = 1;   
   int elementos = MAX;
   int i = 0;
   
   while(intervalo <= elementos/3) 
   {
      intervalo = intervalo*3 +1;
   }

   while(intervalo > 0) {
      printf("Iteración %d#:",i); 
      display();
      
      for(externa = intervalo; externa < elementos; externa++) 
      {
         valoraInsertar = arr[externa];
         interna = externa;
			
         while(interna > intervalo -1 && arr[interna - intervalo] 
            >= valoraInsertar) {
            arr[interna] = arr[interna - intervalo];
            interna -=intervalo;
            printf(" Elemento movido :%d\n",arr[interna]);
         }
         
         arr[interna] = valoraInsertar;
         printf(" Elemento insertado :%d, at position :%d\n",valoraInsertar,interna);
      }
		
      intervalo = (intervalo -1) /3;
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