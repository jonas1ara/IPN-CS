#include <stdio.h>

int sumaMaxSubarreglo(int arr[], int n, int k)
{
    int sumaMax = 0;
    int sumaActual = 0;

    // Calcular la suma de los primeros k elementos
    for (int i = 0; i < k; i++)
        sumaActual += arr[i];

    sumaMax = sumaActual;

    // Calcular la suma de las subcadenas restantes deslizando la ventana
    for (int i = k; i < n; i++)
    {
        sumaActual += arr[i] - arr[i - k]; // Agregar el elemento más reciente y restar el elemento más antiguo
        if (sumaActual > sumaMax)
            sumaMax = sumaActual;
    }

    return sumaMax;
}

int main()
{
    int arr[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int sumaMax = sumaMaxSubarreglo(arr, n, k);
    printf("La suma máxima de una subcadena de longitud %d es: %d\n", k, sumaMax);

    return 0;
}
