#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char *nombre;
    char *autor;
}libro;

void cambio(char aux[100]);

int main()
{
    char aux[50];
    libro JDT;
    printf("Ingrese el nombre del libro: ");
    fgets(aux, 50, stdin);
    cambio(aux);

    //Libro 1
    JDT.nombre = (char*)malloc((strlen(aux)+1)*sizeof(char));
    if(JDT.nombre == NULL)
    {
        printf("No hay memoria disponible");
        exit(1);
    }
    strcpy(JDT.nombre, aux);

    //Libro 2
    printf("Ingrese el autor del libro: ");
    fflush(stdin);
    fgets(aux, 50, stdin);
    cambio(aux);

    JDT.autor = (char*)malloc((strlen(aux)+1)*sizeof(char));
    if(JDT.autor == NULL)
    {
        printf("No hay memoria disponible");
        exit(1);
    }
    strcpy(JDT.autor, aux);

    printf("%s. \n", JDT.nombre);
    printf("%s. \n", JDT.autor);

    free(JDT.nombre);
    free(JDT.autor);

    return 0;
}

void cambio(char aux[50])
{
    int i, j, temp = 0;
    
    for ( i = 0; i < 100 && temp == 0; i++)
    {
        if (aux[i]=='\n')
        {
            aux[i] = '\0';
            temp = 1;
        }
    } 
}