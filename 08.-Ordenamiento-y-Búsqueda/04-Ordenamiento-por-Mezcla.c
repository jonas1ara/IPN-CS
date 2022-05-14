#include <stdio.h>

#define MAX 7

int a[MAX] = {4,6,3,2,1,9,7};
int b[6];

void merging(int low, int mid, int high) 
{
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) 
{
   int mid;
   
   if(low < high) 
   {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else 
   { 
      return;
   }   
}

int main() 
{ 
   int i;
   printf("Ordenamiento burbuja con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: \n");
   
   for(i = 0; i < MAX; i++)
      printf("%d ", a[i]);

   sort(0, MAX);

   printf("\nArreglo de salida: \n");
   
   for(i = 1; i <= MAX; i++)
      printf("%d ", a[i]);
   
   printf("\n");
}

