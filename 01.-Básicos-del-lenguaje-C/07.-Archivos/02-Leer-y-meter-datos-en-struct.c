#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct 
{
    char *nombre;
    int edad;
} trabajadores;

trabajadores *trabajador;  

void vaciar(char temp[]);
void copiar(char temp[], int i);

int main(int argc, char **argv)
{
    char temp[50];

    int cont = 0, aux, i, j;

    FILE * archivo;

    archivo = fopen("Ejemplo2.txt", "r");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    while (!feof (archivo))
    {
        fgets(temp, 50, archivo);
        cont++;
    }

    rewind(archivo);

    trabajador = (trabajadores *) malloc(cont * sizeof(trabajadores));
    if (trabajador == NULL)
    {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (i = 0; !feof(archivo); i++)
    {
        vaciar(temp);
        aux = '0';   
        for (j = 0; aux != '-'; j++)
        {
            aux = fgetc(archivo);
            if (aux != '-')
            {
                temp[j] = aux;
            }
        }     
        copiar(temp, i);

        fgets(temp, 4, archivo);
        trabajador[i].edad  = atoi(temp);

        printf("Nombre: %s -  edad: %i\n", trabajador[i].nombre, trabajador[i].edad);
    }
    return 0;
}

void vaciar(char temp[])
{
    int i;
    for (i = 0; i < 50; i++)
    {
        temp[i] = '\0';
    }
}

void copiar(char temp[], int i)
{
    int N = strlen(temp) + 1;
    
    trabajador[i].nombre = (char *) malloc(N * sizeof(char));
    if (trabajador[i].nombre == NULL)
    {
        printf("Error al reservar memoria\n");
        exit(1);
    }
    strcpy(trabajador[i].nombre, temp);
}