#include <stdio.h>

#define P 5


int main()
{
	for (int i = 0; i < P; i++)
	{
		for (int k = 0; k < P - i; k++)
		{
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
