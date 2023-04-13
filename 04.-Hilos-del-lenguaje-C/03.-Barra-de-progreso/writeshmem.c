#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <semaphore.h>

#include "shared_memory.h"

#define NUM_ITERATIONS 10

int main(int argc, char **argv)
{
    if(argc != 1)
    {
        printf("Uso: %s [cosas para escribir]", argv[0]);
        return -1;
    }

    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);

    sem_t *sem_prod = sem_open(SEM_PRODUCER_FNAME, 0);
    if (sem_prod == SEM_FAILED)
    {
        perror("sem_open/productor");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONSUMER_FNAME, 0);
    if (sem_cons == SEM_FAILED)
    {
        perror("sem_open/consumidor");
        exit(EXIT_FAILURE);
    }

    // Crear la memoria compartida
    char *block = attach_memory_block(FILENAME_MAX, BLOCK_SIZE);
    if(block == NULL)
    {
        printf("Error al crear la memoria compartida");
        return -1;
    }

    // Crear el semaforo

    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        sem_wait(sem_cons);
        printf("Escribiendo en la memoria compartida: \"%s\"\n", argv[1]);
        strncpy(block, argv[1], BLOCK_SIZE);
        sem_post(sem_prod);
    }

    sem_close(sem_prod);
    sem_close(sem_cons);
    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);

    detach_memory_block(block);
    
    return 0;
}