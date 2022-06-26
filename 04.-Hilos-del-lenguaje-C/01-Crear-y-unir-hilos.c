#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void myturn(void * arg)
{
	for(int i = 0;  i < 8; i++)
	{
		sleep(1);
		printf("¡Mi turno putos! %d\n", i);
	}
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

	pthread_create(&newthread, NULL, myturn, NULL);
	//myturn();
	yourturn();
	//esperar mientras el hilo se ejecuta
	pthread_join(newthread, NULL);
}
