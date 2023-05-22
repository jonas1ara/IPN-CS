#include <stdio.h>

void ordenamientoShell(int arr[], int n)
{
   for (int brecha = n / 2; brecha > 0; brecha /= 2)
   {
      for (int i = brecha; i < n; i++)
      {
         int temp = arr[i];
         int j;
         for (j = i; j >= brecha && arr[j - brecha] > temp; j -= brecha)
         {
            arr[j] = arr[j - brecha];
         }
         arr[j] = temp;
      }
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

   printf("Ordenamiento shell (shell sort) - O(n²)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoShell(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}