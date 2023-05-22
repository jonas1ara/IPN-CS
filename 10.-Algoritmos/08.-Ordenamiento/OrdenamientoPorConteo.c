#include <stdio.h>

void ordenamientoPorConteo(int arr[], int n)
{
   int max = arr[0];
   for (int i = 1; i < n; i++)
   {
      if (arr[i] > max)
      {
         max = arr[i];
      }
   }

   int conteo[max + 1];
   int arregloOrdenado[n];

   for (int i = 0; i <= max; i++)
   {
      conteo[i] = 0;
   }

   for (int i = 0; i < n; i++)
   {
      conteo[arr[i]]++;
   }

   for (int i = 1; i <= max; i++)
   {
      conteo[i] += conteo[i - 1];
   }

   for (int i = n - 1; i >= 0; i--)
   {
      arregloOrdenado[conteo[arr[i]] - 1] = arr[i];
      conteo[arr[i]]--;
   }

   for (int i = 0; i < n; i++)
   {
      arr[i] = arregloOrdenado[i];
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

   printf("Ordenamiento por conteto (counting sort) - O(n)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoPorConteo(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}