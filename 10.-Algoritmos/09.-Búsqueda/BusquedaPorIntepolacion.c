#include <stdio.h>

int busquedaInterpolacion(int arr[], int n, int target)
{
   int inicio = 0;
   int fin = n - 1;

   while (inicio <= fin && target >= arr[inicio] && target <= arr[fin])
   {
      if (inicio == fin)
      {
         if (arr[inicio] == target)
         {
            return inicio;
         }
         return -1;
      }

      // Cálculo de la posición estimada por interpolación
      int posicion = inicio + ((target - arr[inicio]) * (fin - inicio)) / (arr[fin] - arr[inicio]);

      if (arr[posicion] == target)
      {
         return posicion;
      }

      if (arr[posicion] < target)
      {
         inicio = posicion + 1;
      }
      else
      {
         fin = posicion - 1;
      }
   }

   return -1;
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

   printf("Búsqueda por interpolación (interpolation search) - O(log(log n))\n\n");

   printf("Arreglo: ");
   imprimirArreglo(arr, n);
   printf("Elemento a buscar: %d\n", target);

   int resultado = busquedaInterpolacion(arr, n, target);
   
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
