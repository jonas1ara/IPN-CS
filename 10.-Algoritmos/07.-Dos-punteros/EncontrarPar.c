#include <stdio.h>

void encontrarPar(int arr[], int n, int target)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            printf("Par encontrado: (%d, %d)\n", arr[i], arr[j]);
            return;
        }
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }
    printf("No se encontró ningún par\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11; // Suma objetivo
    encontrarPar(arr, n, target);
    return 0;
}
