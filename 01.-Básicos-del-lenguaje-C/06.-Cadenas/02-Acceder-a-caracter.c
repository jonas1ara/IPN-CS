#include <stdio.h>
#include <string.h> 

void funcion(char c1[]);

int main()
{
    printf ("¯  _(ツ)_/¯"); 

    char c1[] =  "Si te gusta C usa Linux vaya";

    funcion(c1);

    printf("%s\n\n", c1);

    return 0;
}

void funcion (char c1[])
{
    int limite;

    limite = strlen(c1);

    for (int i = 0; i < limite; i++)
    {
        if (c1[i] == 'a')
        {
            c1[i] = ' ';
        }    
    }
}