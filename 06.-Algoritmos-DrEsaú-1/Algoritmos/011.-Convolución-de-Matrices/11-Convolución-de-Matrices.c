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
