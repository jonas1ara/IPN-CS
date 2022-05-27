// Realizar un vector dinámico de 10 elementos aleatorios comprendidos entre 0 y 2, eliminar todos los números repetidos
// Reajustando el vector

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio(int *vector, int N);

int main()
{
    int i, j, k;
    int N = 10;
    int *vector;

    vector = (int *) malloc(N * sizeof(int)); //Asignar un tamaño al vector
    if(vector == NULL)
    {
        printf("No hay memoria disponible\n");
    }
    else
    {
        aleatorio(vector, N);
        for(i = 0; i < N; i++)
        {
            j = i+1;
            while(j<N)
            {
                if(*(vector+i) == *(vector+j))
                {
                    for(k = j; k+1 < N; k++)
                    {
                        *(vector+k) = *(vector+k+1);
                    }
                    N--;
                }
                else
                {
                    j++;
                }
            }
        }
        vector = (int *) realloc(vector, N * sizeof(int)); //Redimensionar el vector conservando sus valores
        if(vector == NULL)
        {
            printf("No hay memoria disponible\n");
        }
        else
        {
            for(i = 0; i < N; i++)
            {
                printf("%d", *(vector+i));
            }
        }
    }
    
    return 0;
}

void aleatorio(int *vector, int N)
{
     int i;
     srand(time(NULL));
     for(i = 0; i < N; i++)
     {
         *(vector+i) = rand() % 3;
         printf("%d", *(vector+i));
     }
     printf("\n");
}