#include <stdio.h>

int particion(int arr[], int izq, int der)
{
   int pivote = arr[der];
   int i = (izq - 1);
   for (int j = izq; j <= der - 1; j++)
   {
      if (arr[j] < pivote)
      {
         i++;
         // Intercambio de elementos
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   // Intercambio de elementos
   int temp = arr[i + 1];
   arr[i + 1] = arr[der];
   arr[der] = temp;
   return (i + 1);
}

void ordenamientoRapido(int arr[], int izq, int der)
{
   if (izq < der)
   {
      int indiceParticion = particion(arr, izq, der); 
      ordenamientoRapido(arr, izq, indiceParticion - 1);
      ordenamientoRapido(arr, indiceParticion + 1, der);
   }
}

void imprimirArreglo(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

int main()
{
   int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
   int n = sizeof(arr) / sizeof(arr[0]);

   printf("Ordenamiento rapido (quick sort) - O(n log n)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoRapido(arr, 0, n - 1);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}