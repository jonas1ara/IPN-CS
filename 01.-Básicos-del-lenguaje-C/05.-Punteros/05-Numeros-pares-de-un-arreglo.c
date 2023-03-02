#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    
int main(int argc, char **argv)
{
    
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *dir_numeros;

    dir_numeros = numeros;

    for (int i = 0; i < 10; i++)
    {
        if(*dir_numeros % 2 == 0)
        {
            printf("El número %d es par y su ", *dir_numeros);
            printf("dirección de memoria es: %p\n", dir_numeros);
        }
        else
        {
            printf("El número %d es impar y su ", *dir_numeros);
            printf("dirección de memoria es: %p\n", dir_numeros);
        }
        dir_numeros++;

        printf("\n ");          

    }
    
    
    return 0;
}
