// &n = direccion de memoria de n
// *n = valor de la direccion de memoria de n

#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char **argv)
{
    int numero,  *direccion_numero;

    printf("Introduce un numero: ");
    scanf("%d", &numero);

    direccion_numero = &numero; // Guardamos la direccion de memoria de numero en direccion_numero
    
    if(*direccion_numero % 2 == 0)
    {
        printf("El numero %d es par y la ", *direccion_numero);
        printf("posición de memoria es: %p\n\n", direccion_numero);
    }
    else
    {
        printf("El numero %d es impar y la", *direccion_numero);
        printf("posición de memoria es: %p\n\n", direccion_numero);
    }
    return 0;
}