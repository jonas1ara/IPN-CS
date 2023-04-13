#include <stdio.h>
#include <pthread.h> //libreria para hilos

void miTurno(void * arg)
{
	for(int i = 0;  i < 8; i++)
	{
		sleep(1);
		printf("¡Mi turno %d\n", i);
	}
	return NULL;
}

void tuTurno()
{
	for(int i = 0;  i < 3; i++)
	{
		sleep(2);
		printf("¡Ahora es mi turno %d\n", i);
	}
}

int main()
{

	pthread_t newthread;

	pthread_create(&newthread, NULL, miTurno, NULL);
	//myturn();
	tuTurno();
	//esperar mientras el hilo se ejecuta
	pthread_join(newthread, NULL);
}
