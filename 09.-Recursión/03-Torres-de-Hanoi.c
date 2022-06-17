#include <stdio.h>

void Hanoi(char, char, char, int);

int main()
{
	Hanoi('A', 'B', 'C', 3);
	
	return 0;
}

void Hanoi(char varInicial, char varCentral, char varFinal, int n)
{
	if(n==1)//Caso base
	{
		//Cuándo nos quede un solo disco por mover a la varilla final, es el caso base
		printf("Mover disco %d desde varilla %c a varilla %c\n", n, varInicial, varFinal);
	}
	else //Caso recursivo, una versión reducida de la misma función
	{
		// 
		Hanoi(varInicial, varFinal, varCentral, n-1);	
		printf("Mover disco %d desde varilla %c a varilla %c\n", n, varInicial, varFinal);
		Hanoi(varCentral, varInicial, varFinal, n-1);
	}
}

