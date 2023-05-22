#include <stdio.h>
#include <stdbool.h>

void ordenamientoBurbuja(int arr[], int n)
{
    int i, j;
    bool intercambio = false;
    for (i = 0; i < n - 1; i++)
    {
        intercambio = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Intercambio de elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                intercambio = true;
            }
        }

        if (!intercambio)
        {
            break;
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

    printf("Ordenamiento burbuja (bubble sort) - O(n²)\n\n");

    printf("Arreglo original: ");
    imprimirArreglo(arr, n);

    ordenamientoBurbuja(arr, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n);

    return 0;
}