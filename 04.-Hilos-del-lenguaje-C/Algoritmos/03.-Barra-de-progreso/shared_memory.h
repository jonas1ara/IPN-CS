#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/sem.h>
#include <semaphore.h>


char * attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);

#ifndef SHARED_MEMORY_H

#define BLOCK_SIZE 4096
#define FILENAME "writeshmem.c"
#define IPC_RESULT_ERROR (-1)

#define SEM_PRODUCER_FNAME "/tmp/productor"
#define SEM_CONSUMER_FNAME "/tmp/consumidor"


#endif