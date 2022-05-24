#include <stdio.h>
#define CANTIDAD_NUMEROS 5

double valorAbsoluto(double numero)
{
    if (numero < 0)
    {
        return numero * -1;
    }
    return numero;
}

int main(int argc, char const *argv[])
{
    double numeros[CANTIDAD_NUMEROS] = {
        -50,
        1.23,
        -0.95341,
        -10,
        500.62};
    int i;
    for (i = 0; i < CANTIDAD_NUMEROS; i++)
    {
        double numero = numeros[i];
        printf("Valor absoluto de %lf: %lf\n", numero, valorAbsoluto(numero));
    }
    return 0;
}