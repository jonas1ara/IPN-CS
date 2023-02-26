#include <stdio.h>

int main()
{
	int a, b, producto, residuo, mcm, mcd;

	printf("Este programa calcula el mínimo común múltiplo de DOS números naturales y diferentes de cero\n");

    printf("\nIngrese el valor de a: ");
    scanf("%d", &a);

    printf("Ingrese el valor de b: ");
    scanf("%d", &b);

	if(a&&b>0)
	{
    producto = a * b;

    do
    {
        residuo = a%b;

        if (residuo != 0)
        {
            a = b;
            b = residuo;
        }
        else
        {
            mcd = b;
        }

    } while (residuo != 0); //No va a dejar de repetir el ciclo hasta que residuo sea diferente de 0

    mcm = producto / mcd; // mcm(a,b)=a*b/mcd(a,b)

    printf("El Mínimo común múltiplo es: %d\n", mcm);
	} else{
			printf("Introduce un número natural por favor: 1,2,3,4,5,6,7,8...\n");
		}
    
	return 0;

}
