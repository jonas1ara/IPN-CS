#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

volatile bool hecho = false;
    
void *tfunc(void *arg)
{
    sleep(1);
    hecho = true;
    return NULL;
}

int main()
{
    pthread_t t1;
    pthread_create(&t1, NULL, tfunc, NULL);

    printf("Esperando ...\n");
    while(!hecho) {}
    printf("Ok, ¡moviendo !\n");
    
    return 0;
}