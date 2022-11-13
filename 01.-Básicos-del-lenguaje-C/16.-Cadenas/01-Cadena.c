#include <stdio.h>
#include <string.h>

int main()
{
    printf ("¯  _(ツ)_/¯");

    char c1[5];
    char c2[5];
    
    printf ("\n\nIntroduce una cadena: ");
    fgets (c1, 5, stdin);

    printf ("\nIntroduce otra cadena: ");
    fflush (stdin);
    fgets (c2, 5, stdin);

    if (strcmp(c1, c2) == 0) //Prohibido c1 == c2 porque compara dos direcciones de memoría
    {
        printf ("\nSon iguales");
    }
    else
    {
        printf ("\nNo son iguales");
    }
    

    /*
    char vector[13];

    printf ("introduce una frase: ");
    fgets(vector, 13, stdin); //Guarda en el vector de tamaño 13 la frase introducida
    */
    // gets(vector); //Guarda en vector la frase introducida por el usuario

    // scanf ("%s", &vector); //Guarda en una variable el valor introducido por teclado

    printf("%s\n\n", vector);

    return 0;

    
    return 0;
}