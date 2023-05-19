#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
    int maxSum = 0;
    int currentSum = 0;

    // Calcular la suma de los primeros k elementos
    for (int i = 0; i < k; i++)
        currentSum += arr[i];

    maxSum = currentSum;

    // Calcular la suma de las subcadenas restantes deslizando la ventana
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k];  // Agregar el elemento más reciente y restar el elemento más antiguo
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int arr[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int maxSum = maxSumSubarray(arr, n, k);
    printf("La suma máxima de una subcadena de longitud %d es: %d\n", k, maxSum);

    return 0;
}
