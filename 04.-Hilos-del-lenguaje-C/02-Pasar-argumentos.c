#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* myturn(void * arg)
{
    int *iptr = (int *)malloc(sizeof(int));
    *iptr  = 5;
	for(int i = 0;  i < 8; i++)
	{
		sleep(1);
		printf("¡Mi turno putos! %d %d\n", i,*iptr);
        (*iptr)++;
	}
    //¿Qué pasa si retornamos un valor?
	return NULL;
}

void yourturn()
{
	for(int i = 0;  i < 3; i++)
	{
		sleep(2);
		printf("¡Ahora es mi turno putos! %d\n", i);
	}
}

int main()
{
	pthread_t newthread;

    int *result;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	//Esperar mientras el hilo se ejecuta
	pthread_join(newthread, (void*)&result);
    printf("thread's done: *result=%d\n", *result);
}
