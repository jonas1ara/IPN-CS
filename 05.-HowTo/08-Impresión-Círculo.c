#include <stdio.h>
#include <math.h>

#define N 10

int main()
{

    for(int j = 0; j <= N*2; j++) //y
	{
		for(int i = 0; i<= N*2; i++) //x
		{
			if (pow(i-N,2) + pow(j-N,2) <= pow(N,2))
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	} 
    
    return 0;
}