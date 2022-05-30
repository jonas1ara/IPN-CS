//Hacer un vector con 100 enteros que estén entre 0 y 2, y contar con un vector dinámico cuántas veces aparece
//cada número.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Función que genera un número aleatorio entre 0 y 2
void aleatorio(int *vector, int N);

int main()
{
    int i,op, N = 3, vector[100];
    int *contador;

    contador = (int *)calloc(N, sizeof(int)); //Asignar un tamaño al vector
    if (contador == NULL)
    {
        printf("No hay memoria disponible\n");
    }
    else
    {
        aleatorio(vector, 100);
        for (i = 0; i < 100; i++)
        {
            op = vector[i];
            *(contador+op) = *(contador+op) + 1;
        }
        for (i = 0; i < N; i++)
        {
            printf("%d ", *(contador+i));
        }
    }
    //Liberar memoria de un vector dinámico
    free(contador);
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