#include <stdio.h>

void amontonar(int arr[], int n, int i)
{
   int mayor = i;
   int izq = 2 * i + 1;
   int der = 2 * i + 2;
   if (izq < n && arr[izq] > arr[mayor])
   {
      mayor = izq;
   }
   if (der < n && arr[der] > arr[mayor])
   {
      mayor = der;
   }
   if (mayor != i)
   {
      // Intercambio de elementos
      int temp = arr[i];
      arr[i] = arr[mayor];
      arr[mayor] = temp;
      amontonar(arr, n, mayor);
   }
}

void ordenamientoPorMonticulo(int arr[], int n)
{
   // Construir montículo (heap)
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      amontonar(arr, n, i);
   }
   // Extraer elementos del montículo
   for (int i = n - 1; i > 0; i--)
   {
      // Intercambio de elementos
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      amontonar(arr, i, 0);
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

   printf("Ordenamiento por montículo (heap Sort) - O(n log n) \n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoPorMonticulo(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}