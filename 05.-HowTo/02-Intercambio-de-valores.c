#include <stdio.h>

void swap(a,b);

int main() 
{
   int a = 5, b = 3, temp;
   printf("Antes de intercambiar a = %d y b = %d\n",a,b);

   swap(a,b);

   return 0;
}

// Intercambio de valores
void swap(int a, int b) {
   int temp;
   temp = a; 
   a = b; 
   b = temp; 

   printf("Despues de intercambiar a = %d y b = %d \n",a,b);
}