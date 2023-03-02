#include <stdio.h>
#include <stdlib.h>

void ordenar_arreglo(int *arr, int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Ingrese el número %d: ", i+1);
        scanf("%d", arr+i);
    }

    ordenar_arreglo(arr, n);

    printf("El arreglo ordenado es:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");

    free(arr);

    return 0;
}
