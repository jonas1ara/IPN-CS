#include <stdio.h>
#include <pthread.h> //Libreria para que crees WEE :v

/*
	Hilos de ejecución para ejecutar tareas que se ejecuten de manera paralera en nuestro programa, así como los SO pueden usar varios procesos al mismo tiempo
	Los procesos pueden usar hilos para ejecutar diferentes tareas al mismo tiempo, ahora imagina lo siguiente:

	Estamos en un banco con una sola persona trabajando, un solo proceso, tiene lugares para realizar los trabajos, y ofrece diversos servicios, en este escenarios UNA    sola personas hace todo el trabajo, si esta despachando dinero necesita ir a procesar una solicitud en uno de los escritorios, si existieran más personas en el 		  banco cada una dedicada a su función el proceso y productividad del banco seria mucho mejor, esos nuevos empleados en los nuestro programa son los hilos.
*/

typedef struct
{
	int id;
	int a;
	int b;
	int c;
} Triangulo;

void* mostrar_perimetro(void *input)
{
	Triangulo *tmp_triangulo = (Triangulo*)input;
	
	
}

int main()
{
	printf("


	return 0;
}

