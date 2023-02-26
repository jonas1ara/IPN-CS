#include <stdio.h>

int main()
{
	//Inicializo variables flotantes
	double e = 1;
	float n = 1;
	int numero = 1, i;
	printf("Este programa cálcula una aproximación del número e");
	printf("\n");

	//Número a aproximar
	printf("Dame un número: \n");
	scanf("%d",&numero);
	if(numero >= 1) //Condición if
	{
		//Cálculo euler
		for(i = 1 ; i <= numero ; i++)
		{
			n = n*i;
			e = e+(1/n);
		}
	 		printf("\nEl valor de aproximado de Euler es: %.10lf \n", e);
		}
		else
		{
			printf("\nIngresa un número mayor o igual a 1\n");
		}
	return 0;
}
