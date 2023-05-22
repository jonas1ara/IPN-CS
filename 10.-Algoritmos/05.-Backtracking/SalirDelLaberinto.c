#include <stdio.h>
#include <stdbool.h>

#define N 4

void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

bool esSeguro(int lab[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && lab[x][y] == 1)
		return true;

	return false;
}

bool resolverLab(int lab[N][N], int x, int y, int sol[N][N])
{
	if (x == N - 1 && y == N - 1 && lab[x][y] == 1)
	{
		sol[x][y] = 1;
		return true;
	}

	if (esSeguro(lab, x, y) == true)
	{

		if (sol[x][y] == 1)
			return false;

		sol[x][y] = 1;

		if (resolverLab(lab, x + 1, y, sol) == true)
			return true;

		if (resolverLab(lab, x, y + 1, sol) == true)
			return true;

		sol[x][y] = 0;
		return false;
	}
	return false;
}

bool laberinto(int lab[N][N])
{
	int sol[N][N] = {{0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0}};
	if (resolverLab(lab, 0, 0, sol) == false)
	{
		printf("No existe solución\n");
		return false;
	}
	printSolution(sol);
	return true;
}

int main()
{
	int lab[N][N] =
		{
			{1, 0, 0, 0},
			{1, 1, 0, 1},
			{0, 1, 0, 0},
			{1, 1, 1, 1}};

	laberinto(lab);

	return 0;
}
