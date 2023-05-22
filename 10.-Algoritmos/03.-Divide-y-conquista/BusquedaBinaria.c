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


int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int resultado = busquedaBinaria(arr, 0, n - 1, target);

    if (resultado == -1)
    {
        printf("El elemento no se encuentra en el arreglo.\n");
    }
    else
    {
        printf("El elemento se encuentra en la posición %d.\n", resultado);
    }

    return 0;
}
