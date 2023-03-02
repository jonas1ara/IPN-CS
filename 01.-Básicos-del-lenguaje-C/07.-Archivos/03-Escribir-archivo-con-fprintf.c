#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    
void cambio(char aux[]);

int main(int argc, char **argv)
{
    char aux[100];

    FILE *archivo;

    archivo = fopen("Ejemplo3.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    printf("Escribe algo: ");
    fgets(aux, 100, stdin);
    
    fprintf(archivo, "%s", aux);

    fclose(archivo);
    
    return 0;
}

void cambio(char aux[])
{
    int i;

    for (i = 0; i < 100; i++)
    {
        if (aux[i] == '\n')
        {
            aux[i] = '\0';
        }
    }
}