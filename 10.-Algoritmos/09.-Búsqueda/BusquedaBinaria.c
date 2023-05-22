#include <stdio.h>

// Función de búsqueda binaria
int busquedaBinaria(int arr[], int izq, int der, int target)
{
   if (der >= izq)
   {
      int mitad = izq + (der - izq) / 2;

      if (arr[mitad] == target)
      {
         return mitad;
      }

      if (arr[mitad] > target)
      {
         return busquedaBinaria(arr, izq, mitad - 1, target);
      }

      return busquedaBinaria(arr, mitad + 1, der, target);
   }

   return -1; // Elemento no encontrado
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

   printf("Búsqueda binaria (binary search) - O(log n)\n\n");

   printf("Arreglo: ");
   imprimirArreglo(arr, n);

   printf("Elemento a buscar: %d\n", target);

   int resultado = busquedaBinaria(arr, 0, n - 1, target);

   if (resultado == -1)
   {
      printf("El elemento no se encuentra en el arreglo\n");
   }
   else
   {
      printf("El elemento se encuentra en la posición %d\n", resultado);
   }

   return 0;
}
