#include <stdio.h>

#define N 8

int tablero[N][N];

int esSeguro(int fila, int col)
{
	int i, j;

	// Verificar la fila hacia la izquierda
	for (i = 0; i < col; i++)
	{
		if (tablero[fila][i])
			return 0;
	}

	// Verificar la diagonal superior izquierda
	for (i = fila, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (tablero[i][j])
			return 0;
	}

	// Verificar la diagonal inferior izquierda
	for (i = fila, j = col; j >= 0 && i < N; i++, j--)
	{
		if (tablero[i][j])
			return 0;
	}

	return 1;
}

int resolverNQueens(int col)
{
	if (col >= N)
		return 1;

	for (int fila = 0; fila < N; fila++)
	{
		if (esSeguro(fila, col))
		{
			tablero[fila][col] = 1;

			if (resolverNQueens(col + 1))
				return 1;

			tablero[fila][col] = 0; // Backtracking
		}
	}

	return 0;
}

void printSolution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", tablero[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	if (resolverNQueens(0))
	{
		printf("Solución encontrada:\n");
		printSolution();
	}
	else
	{
		printf("No se encontró solución para N = %d\n", N);
	}

	return 0;
}
