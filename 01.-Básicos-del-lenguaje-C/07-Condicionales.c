/*
	Condicionales en C

	Operadores de igualdad:                   	 |      	Operadores de relación:
		== X es igual a Y                                     	 	   > X Es mayor que Y
		!= X es diferente de  Y								  		< X  Es menor que Y
																				>= X Es mayor o igual que Y																<= X Es es menor o igual que Y
*/

#include <stdio.h>

int main() 
{
	int edad;
	
	printf("Dime tu edad:\n");
	scanf("%d",&edad);

	if(edad >= 18) 
	{
		printf("Eres mayor de edad\n");
	} else 
		{
		printf("Eres menor de edad\n");
		}

	return 0;

}
