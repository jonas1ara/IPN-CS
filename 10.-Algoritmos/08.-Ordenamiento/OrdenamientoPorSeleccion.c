#include <stdio.h>

void ordenamientoPorSeleccion(int arr[], int n)
{
   int i, j, indiceMinimo;

   for (i = 0; i < n - 1; i++)
   {
      indiceMinimo = i;
      for (j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[indiceMinimo])
         {
            indiceMinimo = j;
         }
      }
      // Intercambio de elementos
      int temp = arr[indiceMinimo];
      arr[indiceMinimo] = arr[i];
      arr[i] = temp;
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

   printf("Ordenamiento por seleccion (selection sort) - O(n²)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoPorSeleccion(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}