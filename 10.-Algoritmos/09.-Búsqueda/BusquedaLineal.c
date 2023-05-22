#include <stdio.h>

int busquedaLineal(int arr[], int n, int target)
{
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == target)
      {
         return i; // Devuelve el índice donde se encontró el elemento
      }
   }
   return -1; // Devuelve -1 si el elemento no se encuentra
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
   int arr[] = {2, 5, 7, 10, 14, 18, 20};
   int n = sizeof(arr) / sizeof(arr[0]);
   int target = 10;

   printf("Búsqueda lineal (linear search) - O(n)\n\n");

   printf("Arreglo: ");
   imprimirArreglo(arr, n);

   printf("Elemento a buscar: %d\n", target);

   int resultado = busquedaLineal(arr, n, target);
   
   if (resultado == -1)
   {
      printf("El elemento no se encuentra en el arreglo\n");
   }
   else
   {
      printf("El elemento se encuentra en el índice %d\n", resultado);
   }
   return 0;
}
