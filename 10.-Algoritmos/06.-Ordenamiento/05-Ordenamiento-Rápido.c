#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int arr[MAX] = {4,6,3,2,1,9,7};

void printline(int count) 
{
   int i;
	
   for(i = 0;i < count-1;i++) 
   {
      printf("=");
   }
	
   printf("=\n");
}

void display() 
{
   int i;
   printf("[");
	
   // Navegar a través del arreglo
   for(i = 0;i < MAX;i++) {
      printf("%d ",arr[i]);
   }
	
   printf("]\n");
}

void swap(int num1, int num2) 
{
   int temp = arr[num1];
   arr[num1] = arr[num2];
   arr[num2] = temp;
}

int partition(int left, int right, int pivot) 
{
   int leftPointer = left -1;
   int rightPointer = right;

   while(true) {
      while(arr[++leftPointer] < pivot) 
      {
         //No hacer nada
      }
		
      while(rightPointer > 0 && arr[--rightPointer] > pivot) 
      {
         //No hacer nada
      }

      if(leftPointer >= rightPointer) 
      {
         break;
      } else 
      {
         printf(" Elemento intercambiado :%d,%d\n", arr[leftPointer],arr[rightPointer]);
         swap(leftPointer,rightPointer);
      }
   }
	
   printf(" Pivote intercambiado :%d,%d\n", arr[leftPointer],arr[right]);
   swap(leftPointer,right);
   printf("   Arreglo actualizado: "); 
   display();
   return leftPointer;
}

void quickSort(int left, int right) 
{
   if(right-left <= 0) 
   {
      return;   
   } else 
   {
      int pivot = arr[right];
      int partitionPoint = partition(left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }        
}

int main() 
{
   printf("Ordenamiento rápido con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: ");
   display();
   printline(50);
   quickSort(0,MAX-1);
   printf("Arreglo de salida: ");
   display();
   printline(50);
}