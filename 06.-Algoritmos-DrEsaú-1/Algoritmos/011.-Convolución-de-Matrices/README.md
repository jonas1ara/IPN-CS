# Convolución de matrices

_La **convolución de dos matrices** es una operación matemática común en el procesamiento de señales y la visión por computadora. En C, se puede implementar la convolución utilizando dos bucles anidados para recorrer cada elemento de las matrices y multiplicarlos antes de sumar los resultados para generar una nueva matriz convolucionada_

![alt text](/00.-Sources/Images/IC.jpg)

_Esta ecuación nos permite realizar la interpolación de un nuevo punto (x,y), simplemente sustituyendo el valor de x, el resultado p(x) será la y buscada_

Aquí está un ejemplo de programa en C que convoluciona dos matrices:

```c
#include <stdio.h>

#define ROWS 3
#define COLS 3

void convolution(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j, k, l;
    int sum;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum = 0;
            for (k = 0; k < ROWS; k++) {
                for (l = 0; l < COLS; l++) {
                    sum += matrix1[i-k+1][j-l+1] * matrix2[k][l];
                }
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];
    int i, j;
    
    convolution(matrix1, matrix2, result);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

En este programa, la función convolution toma dos matrices de entrada matrix1 y matrix2, y una matriz de salida result. La función convoluciona matrix1 y matrix2, y almacena el resultado en result

En la función convolution, se utilizan cuatro bucles anidados. Los bucles externos (i y j) recorren cada elemento de la matriz de salida result. Los bucles internos (k y l) recorren cada elemento de las matrices de entrada matrix1 y matrix2, respectivamente. Dentro del bucle interno, se multiplican los elementos correspondientes de matrix1 y matrix2, y el resultado se suma al valor acumulado sum. Una vez que se han multiplicado todos los elementos correspondientes, se almacena el valor de sum en la matriz de salida result

En el main del programa, se definen dos matrices de entrada matrix1 y matrix2, y una matriz de salida result. Se llama a la función convolution para convolucionar matrix1 y matrix2, y se imprime la matriz de salida result.

En resumen, este programa implementa la operación de convolución de dos matrices utilizando bucles anidados en C

Ahora el programador necesita escribir un programa que convolucione dos matrices de 1000x1000. ¿Cómo puede optimizar el programa para que sea más rápido?


