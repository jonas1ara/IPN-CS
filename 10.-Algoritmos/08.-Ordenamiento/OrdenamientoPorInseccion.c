#include <stdio.h>

void ordenamientoPorInserccion(int arr[], int n)
{
   int i, j, valor;
   for (i = 1; i < n; i++)
   {
      valor = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > valor)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = valor;
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

   printf("Ordenamiento por inserccion (insertion sort) - O(n²)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoPorInserccion(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}