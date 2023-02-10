/*	
	Switch en C, darle opciones al usuario.
*/

#include<stdio.h>

int main() 
{
	int casos;

	printf("Ingresa un número:\n");
	scanf("%i",&casos);
	
	switch(casos)
	{
		case 1:
			printf("Elegiste el caso #1\n");
			break;
		case 2:	
			printf("Elegiste el caso #2\n");
			break;
		case 3:
			printf("Elegiste el caso #3\n");
			break;
		case 4:	
			printf("Elegiste el caso #4\n");
			break;
		case 5:	
			printf("Elegiste el caso #5\n");
			break;
		default:
			printf("No encontramos el caso que elegiste... :/\n");
			break;
	}
	return 0;
}

