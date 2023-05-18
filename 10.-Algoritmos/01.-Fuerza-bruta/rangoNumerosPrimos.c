#include <stdio.h>

void encontrarPrimos(int rangoInicial, int rangoFinal)
{
    printf("Números primos en el rango [%d, %d]:\n", rangoInicial, rangoFinal);

    for (int num = rangoInicial; num <= rangoFinal; num++)
    {
        if (esPrimo(num))
        {
            printf("%d ", num);
        }
    }

    printf("\n");
}

int esPrimo(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int rangoInicial, rangoFinal;

    printf("Ingrese el rango inicial: ");
    scanf("%d", &rangoInicial);

    printf("Ingrese el rango final: ");
    scanf("%d", &rangoFinal);

    encontrarPrimos(rangoInicial, rangoFinal);

    return 0;
}