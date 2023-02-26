#include <stdio.h>

int main( )
{	
	int a, b, m, mc, c = 0;
		
	printf("Este progra cálcula una multiplicación pero con el método Ruso\n");
	printf("Dame tu primer factor: ");
	scanf("%d",&m);
	printf("Dame tu segundo factor: ");
		scanf("%d",&mc);
	printf("\n");

	printf("Factor 1: %d   Factor 2: %d\n",m,mc);		
	printf("---------------------------------\n");	

	a = m;

	b = mc; 

	while(b>=1){ //Mientras b sea mayor o igual a 0 (condiciono asi porque, si solo pongo b > 1, no toma en cuenta el ultimo valor que es 1), hara lo siguiente:

			if (b % 2 != 0)//Si el segundo número es Impar, entonces
			{  
				c=c+a;
			}			

			a = a * 2;  //El primer factor va a ser igual a si mismo pero mutiplicado por dos
			b = b / 2; //El segundo factor va a ser igual a si mismo pero entre dos
			printf("	%d		 %d\n", a, b);
				
	}

	printf("El resultado de la multiplicación rusa es : %d * %d = %d\n", m, mc, c);
	
	return 0;

}
