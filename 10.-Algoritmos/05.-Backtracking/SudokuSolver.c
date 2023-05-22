#include <stdio.h>
#include <stdlib.h>

#define N 9

void print(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int esSeguro(int red[N][N], int fila,
		   int col, int num)
{

	for (int x = 0; x <= 8; x++)
		if (red[fila][x] == num)
			return 0;

	for (int x = 0; x <= 8; x++)
		if (red[x][col] == num)
			return 0;

	int iniciarFila = fila - fila % 3,
		iniciarCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (red[i + iniciarFila][j +
								   iniciarCol] == num)
				return 0;

	return 1;
}

int resolverSudoku(int red[N][N], int fila, int col)
{
	if (fila == N - 1 && col == N)
		return 1;

	if (col == N)
	{
		fila++;
		col = 0;
	}

	if (red[fila][col] > 0)
		return resolverSudoku(red, fila, col + 1);

	for (int num = 1; num <= N; num++)
	{

		if (esSeguro(red, fila, col, num) == 1)
		{
			red[fila][col] = num;

			if (resolverSudoku(red, fila, col + 1) == 1)
				return 1;
		}

		red[fila][col] = 0;
	}
	return 0;
}

int main()
{
	int red[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	if (resolverSudoku(red, 0, 0) == 1)
		print(red);
	else
		printf("No existe solución\n");

	return 0;
}
