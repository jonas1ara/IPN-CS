#include <stdio.h>

int main() {
   int a = 5, b = 3, temp;
   printf("Antes de intercambiar a=%d y b=%d\n",a,b);
   
   // Intercambio de valores
   temp = a;
   a = b;
   b = temp;

   printf("Después de intercambiar a=%d y b=%d",a,b);
}