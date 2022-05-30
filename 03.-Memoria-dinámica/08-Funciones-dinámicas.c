#include <stdio.h>
#include <stdlib.h>

int** reservar (int filas, int columnas);
void introduce (int filas, int columnas, int **mat);
void comparar(int filas, int columnas, int **m1, int **m2);


int main()
{
    printf ("¯  _(ツ)_/¯"); 

    int filas, columnas;
    int **m1;
    int **m2;

    printf("\nIntroduce el numero de filas: ");
    scanf("%d", &filas);

    printf("\nIntroduce el numero de columnas: ");
    scanf("%d", &columnas);

    m1 = reservar (filas, columnas);
    m2 = reservar (filas, columnas);

    introduce(filas, columnas, m1);
    introduce(filas, columnas, m2);

    comparar(filas, columnas, m1, m2);

    return 0;
}

//matriz dinámica
int** reservar (int filas, int columnas)
{
    int **mat;

    mat = (int **) malloc (filas * sizeof(int *));
    if (mat == NULL)
    {
        printf("\nNo hay memoria disponible");
        exit(1);
    }
    for (int i = 0; i < filas; i++)
    {
        mat[i] = (int *) malloc (columnas * sizeof(int));
        if (mat[i] == NULL)
        {
            printf("\nNo hay memoria disponible");
            exit(1);
        }
    }
    //retornar dirección de memoria
    return mat;
}

//introducir datos
void introduce (int filas, int columnas, int **mat)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("\nIntroduce el elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void comparar(int filas, int columnas, int **m1, int **m2)
{
    int aux = 0;
    for (int i = 0; i < filas && aux == 0; i++)
    {
        for (int j = 0; j < columnas && aux == 0; j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                aux = 1;
            }
        }
    }
    if(aux == 0)
    {
        printf("\nLas matrices son iguales\n");
    }
    else
    {
        printf("\nLas matrices son distintas\n");
    }
}