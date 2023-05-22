#include <stdio.h>

//Función para unir dos subarreglos ordenados
void unir(int arr[], int izq[], int tamanioIzq, int der[], int tamanioDer)
{
    int i = 0, j = 0, k = 0;

    while (i < tamanioIzq && j < tamanioDer)
    {
        if (izq[i] <= der[j])
        {
            arr[k] = izq[i];
            i++;
        }
        else
        {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < tamanioIzq)
    {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while (j < tamanioDer)
    {
        arr[k] = der[j];
        j++;
        k++;
    }
}

// Función principal del ordenamiento por mezcla
void ordenamientoPorMezcla(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }

    int medio = n / 2;
    int izq[medio];
    int der[n - medio];

    for (int i = 0; i < medio; i++)
    {
        izq[i] = arr[i];
    }

    for (int i = medio; i < n; i++)
    {
        der[i - medio] = arr[i];
    }

    ordenamientoPorMezcla(izq, medio);
    ordenamientoPorMezcla(der, n - medio);
    unir(arr, izq, medio, der, n - medio);
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

   printf("Ordenamiento por mezcla (merge sort) - O(n log n)\n\n");

    printf("Arreglo original: ");
    imprimirArreglo(arr, n);

    ordenamientoPorMezcla(arr, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n);

    return 0;
}