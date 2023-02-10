/*
    Funciones de tipo void
*/

#include <stdio.h>

void factorial(); //Prototipo de la función factorial

int main()
{
    factorial();
    return 0;
}

//Función que no devuelve nada, se utilizan para evitar hacer una operación en la función main
void factorial ()
{
    printf ("¯  _(ツ)_/¯");

    int x, aux = 1;
    printf ("\nIntroduce un número: ");
    scanf ("%d", &x);

    for (int i = 1; i <= x; i++)
    {
        aux *= i;
    }
    printf ("\nEl factorial de %d es %d\n", x, aux);
}
