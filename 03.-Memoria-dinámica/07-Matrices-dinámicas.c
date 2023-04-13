#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("¯  _(ツ)_/¯\n");

    int i, j;
    int filas, columnas;
    int **m1;
    int **m2;

    printf ("Introduce el número de filas: ");
    scanf ("%d", &filas);

    printf ("Introduce el número de columnas: ");
    scanf ("%d", &columnas);

    m1 = (int **) malloc (filas * sizeof(int *));
    if(m1 == NULL)
    {
        printf ("No se ha podido reservar memoria para la matriz 1\n");
        exit(1);
    } 

    for ( i = 0; i < filas; i++)
    {
        m1[i] = (int *) malloc (columnas * sizeof(int));
        if (m1[i] == NULL)
        {
            printf ("No se ha podido reservar memoria para la matriz 1\n");
            exit(1);
        }
    }
    
    for ( i = 0; i < filas; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            scanf ("%d", &m1[i][j]);
        }
    }

    m2 = (int **) malloc (filas * sizeof(int *));
    if (m2 == NULL)
    {
        printf ("No se ha podido reservar memoria para la matriz 2\n");
        exit(1);
    }
    
    for ( i = 0; i < filas; i++)
    {
        m2[i] = (int *) malloc (columnas * sizeof(int));
        if (m2[i] == NULL)
        {
            printf ("No se ha podido reservar memoria para la matriz 2\n");
            exit(1);
        }
    }
    
    for ( i = 0; i < filas; i++)
    {
        for ( j = 0; j < columnas; j++)
        {
            m2[i][j] = m1[i][j];
            printf ("%d ", m2[i][j]);
        }
        printf ("\n");
    }

    return 0;
}

