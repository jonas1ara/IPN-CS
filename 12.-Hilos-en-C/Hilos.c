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
	int perimetro = tmp_triangulo->a+tmp_triangulo->b+tmp_triangulo->c;
	printf("El perimetro es: %d\n",perimetro);
}

int main()
{
	Triangulo mis_triangulos[]={{0,10,15,28},{1,4,17,22},{2,32,10,91}};
	pthread_t threads[3];
	for (int i = 0; i < 3; i++)
	{
		pthread_create(&threads[i],NULL,mostrar_perimetro, (void*)&mis_triangulos[i]);
		pthread_join(threads[i],NULL);
	}
	return 0;
}

