#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <semaphore.h>

#include "shared_memory.h"
    

int main(int argc, char **argv[])
{
    if(argc != 1)
    {
        printf("Uso: %s //no necesita argumentos", argv[0]);
        return -1;
    }

    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);

    sem_t *sem_prod = sem_open(SEM_PRODUCER_FNAME, IPC_CREAT, 0660, 0);
    if (sem_prod == SEM_FAILED)
    {
        perror("sem_open/productor");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONSUMER_FNAME, IPC_CREAT, 0660, 1);
    if (sem_cons == SEM_FAILED)
    {
        perror("sem_open/consumidor");
        exit(EXIT_FAILURE);
    }

    char *block = attach_memory_block(FILENAME_MAX, BLOCK_SIZE);

    if(block == NULL)
    {
        printf("Error al crear la memoria compartida");
        return -1;
    }

    // Crear el semaforo
    while(true)
    {
            sem_wait(sem_prod);
            
            if(strlen(block) > 0)
            {
                printf("Leyendo: \"%s\"\n", block);
                bool done = (strcmp(block, "done") == 0);
                block[0] = 0;
                if (done)
                {
                    break;
                }
            }
            sem_post(sem_cons);
    }

    sem_close(sem_cons);
    sem_close(sem_prod);
    detach_memory_block(block);
    
    return 0;
}