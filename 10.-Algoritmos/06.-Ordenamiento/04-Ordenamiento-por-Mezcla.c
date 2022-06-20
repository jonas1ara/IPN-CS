#include <stdio.h>

#define MAX 7

int a[MAX] = {4,6,3,2,1,9,7};
int b[6];

void mezclando(int , int , int ); 
void ordenar(int , int ) ;

int main() 
{ 

   printf("Ordenamiento burbuja con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: \n");
   
   for(int i = 0; i < MAX; i++)
      printf("%d ", a[i]);

   ordenar(0, MAX);

   printf("\nArreglo de salida: \n");
   
   for(int i = 1; i <= MAX; i++)
      printf("%d ", a[i]);
   
   printf("\n");
}

//Recibe por valor el inicio, la mitas y el fin del arreglo
void mezclando(int inicio, int mitad, int final) 
{
   //i1 es el inicio del arreglo 1 y i2 es el inicio del arreglo 2
   int i1, i2, i;

   //Ciclo for para recorrer los vectores a y b
   //Se inicializa i1 en el inicio del arreglo 1, se inicializa i2 en el inicio del arreglo 2
   //Se inicializa i en el inicio del arreglo 1.
   //Mientras que el arreglo 1 y 2 se puedan recorrer, se aumenta el valor de i 
   for(i1 = inicio, i2 = mitad + 1, i = inicio; i1 <= mitad && i2 <= final; i++) 
   {
      //Si el valor dentro del arreglo 1 es menor que el valor dentro del arreglo 2, se copia el valor del arreglo 1 al arreglo 2
      if(a[i1] <= a[i2])
      //Se copia el valor del arreglo 1 al arreglo 2
         b[i] = a[i1++];
      else
      //Se copia el valor del arreglo 2 al arreglo 1
         b[i] = a[i2++];

      //Recordar que b es un arreglo vacio, que se declaro al inicio
   }
   
   //Ciclos while para mezclar los arreglos a y b
   //Mientras que el arreglo 1 se pueda recorrer, se copia el valor del arreglo 1 a la siguiente posición del arreglo 2
   while(i1 <= mitad)    
      b[i++] = a[i1++];

   //Mientras que el arreglo 2 se pueda recorrer, se copia el valor del arreglo 2 a la siguiente posición del arreglo 1
   while(i2 <= final)   
      b[i++] = a[i2++];

   //Se recorre el arreglo 2, copiando el valor de cada posición al arreglo 1
   for(i = inicio; i <= final; i++)
      a[i] = b[i];
}

//Recibe por valor dos enteros que representan el rango de elementos a ordenar
void ordenar(int inicio, int final) 
{
   //Caso base; solo hay un elemento
   if(inicio < final) 
   {
      //Indicara la mitad del arreglo
      int mitad = (inicio + final) / 2;
      //Dividir la parte izquierda del arreglo
      ordenar(inicio, mitad);
      //Dividir la parte derecha del arreglo
      ordenar(mitad+1, final);
      mezclando(inicio, mitad, final);
   } else 
   { 
      return;
   }   
}

