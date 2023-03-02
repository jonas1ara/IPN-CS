#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    
int main(int argc, char **argv)
{
    
    int elements;
    printf("Cantidad de números: ");
    scanf("%d",&elements);

    int numeros[elements];
    for(int i=0; i<elements; i++) {
        printf("Número: %d", i+1);
        numeros[i];
    }

    int *dir_numeros = numeros;
    int menor = numeros[0];
    for(int i=0; i<elements; i++) {
        if(*dir_numeros < menor) menor = *dir_numeros;
        dir_numeros++;
    }

    printf("Número menor: %d\n", menor);
    
    return 0;
}
