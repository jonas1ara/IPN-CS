#include <stdio.h>

int main() {
   int a = 5, b = 3, temp;
   printf("Antes de intercambiar a=%d y b=%d\n",a,b);
   
   // Intercambio de valores
   temp = a; //temp vale 5
   a = b; //a vale 3
   b = temp; //b vale 5

   printf("Después de intercambiar a=%d y b=%d",a,b);
}