#include <stdio.h>

// Función para combinar dos subarreglos ordenados en uno solo
void merge(int arr[], int izq[], int tamanioIzq, int der[], int tamanioDer)
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

// Función principal de Merge Sort
void mergeSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }

    int mid = n / 2;
    int izq[mid];
    int der[n - mid];

    for (int i = 0; i < mid; i++)
    {
        izq[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        der[i - mid] = arr[i];
    }

    mergeSort(izq, mid);
    mergeSort(der, n - mid);
    merge(arr, izq, mid, der, n - mid);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Arreglo ordenado: ");
    printArray(arr, n);

    return 0;
}
