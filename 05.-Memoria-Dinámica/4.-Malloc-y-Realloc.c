//Realizar n vecor dinámicode 10 elementos aleaorios comprendidos entre 0 y 2 y eliminar todos los numeros repetidos
//----------> Reajustando el vector <---------------

//i1 2 0 j2 1 1 1 1 0 b0

#include <stdio.h>
#include<stdlib.h>
#include <time.h>


void aleatorio(int *vector, int N);

int main()
{
    int N = 10;
    int *vector;

    vector = (int*)malloc(N*sizeof(int)); //Asignar un tamaño al vector (2 bytes(int) * N(10) = 20 bytes)

    return 0;
}

void aleatorio(int *vector, int N)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        *(vector+i) = rand() % 3;
        printf("%i, ", *(vector+i));
    }
    printf("\n");
}