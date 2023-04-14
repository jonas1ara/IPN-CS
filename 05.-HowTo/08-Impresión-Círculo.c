#include <stdio.h>

int main()
{
    int n = 10;

    for(int j = 0; j <= n*2; j++) //y
	{
		for(int i = 0; i<= n*2; i++) //x
		{
			if (pow(i-n,2) + pow(j-n,2) <= pow(n,2))
			{
				printf("%c",176);
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