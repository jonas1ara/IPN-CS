#include <stdio.h>

void factorial();

int main()
{
    factorial();
    return 0;
}

//Función que no devuelve nada, se utilizan para no hacer nada en el int main
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