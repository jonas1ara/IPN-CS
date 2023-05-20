#include <stdio.h>

int encontrarSubsecuencia(int arr[], int n, int target)
{
    int i = 0, j = 0, suma = 0, longitud_max = 0;
    while (j < n)
    {
        suma += arr[j];
        while (suma > target)
        {
            suma -= arr[i];
            i++;
        }
        if (suma == target && (j - i + 1) > longitud_max)
        {
            longitud_max = j - i + 1;
        }
        j++;
    }
    return longitud_max;
}

int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8; 
    int subsecuenciaMasLarga = encontrarSubsecuencia(arr, n, target);
    printf("Longitud de la subsecuencia más larga: %d\n", subsecuenciaMasLarga);
    return 0;
}
