#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    
int main(int argc, char **argv)
{

    char aux;

    char aux2[100];

    FILE * archivo;

    archivo = fopen("Ejemplo1.txt", "r"); // Abrimos el archivo en modo lectura

    if (archivo == NULL) // Si no se pudo abrir el archivo
    {
        printf("No se pudo abrir el archivo\n");
        exit (1);
    }

    while(aux != EOF)
    {
        // Leemos el archivo hasta llegar a EOF
        aux = fgetc(archivo);

        // Imprimimos el caracter leido
        printf("%c", aux);
    }
    printf("\n");

    fclose(archivo); // Cerramos el archivo para liberar memoria

    archivo = fopen("Ejemplo1.txt", "r"); 

    if (archivo == NULL) // Si no se pudo abrir el archivo
    {
        printf("No se pudo abrir el archivo\n");
        exit (1);
    }

    while(!feof(archivo)) // feof() regresa 1 si se llego al final del archivo con ! se convierte en 0
    {
        // Leemos el archivo hasta llegar a EOF
        fgets(aux2, 100, archivo);

        // Imprimimos el caracter leido
        printf("%s", aux2);
    }
    printf("\n");

    fclose(archivo); // Cerramos el archivo para liberar memoria
    
    return 0;
}