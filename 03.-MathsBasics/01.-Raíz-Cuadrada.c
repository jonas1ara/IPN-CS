#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    double numero;

    printf("Escribe un número y te dire su raíz cuadra\n");
    scanf("%lf", &numero);

    double raizCuadrada = sqrt(numero);
    printf("La raíz cuadrada de %lf  es %lf\n", numero, raizCuadrada);

    return 0;


}