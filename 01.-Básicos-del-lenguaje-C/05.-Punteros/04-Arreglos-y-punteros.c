#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char **argv)
{
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *direccion_numeros; // Guardamos la direccion de memoria de numeros en direccion_numeros
    
    direccion_numeros = &numeros[0]; // Guardamos la direccion de memoria de numeros en direccion_numeros


    for (int i = 0; i < 10; i++)
    {
        printf("El numero %d esta en la posicion de memoria: %p\n", *(direccion_numeros+i), (direccion_numeros+i));
    }
    printf("\n");

    return 0;
}