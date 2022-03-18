#include <stdio.h>
#include <math.h>

void plano(int n);

int main()
{
	//1.-Imprimir un cuadro y buscar sentencias logicas para que nos imprima un espacio o numeral
	
	plano(int n);
	
	return 0;
}

void plano(int n, int j, int i)
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
}



