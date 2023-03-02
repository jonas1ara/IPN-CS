#include <stdio.h>
#include "prueba.h"

int main()
{
    int x = 5;

    prueba (&x);

    printf("El valor de x es %d\n", x);

    return 0;
}