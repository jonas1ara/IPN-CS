#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datos{
	char *nombre_tarea;
	int duracion_tarea;
};

//Generar el elemento nodo
typedef struct datos_personas persona;

struct datos_personas
{
     struct datos dato; //Estructura de datos de la persona
	 persona *siguiente; //Puntero al siguiente elemento
};

//Prototipos
void Agregar(persona **, persona **, char *, int);
struct datos Retirar(persona **, persona **);
int vacia(persona *);
int tam(persona *);

//Función principal
int main()
{
  //Declaración de variables
  int eleccion;
  char nombre_tarea[50]; //Vector de caracteres para el nombre_tarea
  int duracion_tarea;
  
  //Crear la cola
  persona *inicio = NULL; //Puntero al inicio de la cola
  persona *final = NULL; //Puntero al final de la cola
  
  //Mensaje de inicio
  printf("Este progama simula un gestor de tareas de un procesador, insertas tareas identificadas con un nombre y una duración determinada, posteriormente proporcionas un tiempo de ejecución que servirá para ir quitando tareas de la\n");
  
  //Menu
  while(eleccion != -1)
  {
  	printf("\n Menu\n 1.-Insertar tareas\n 2.-Retirar tareas\n -1.-Salir\n\n\tElige: ");
  	scanf("%d",&eleccion);
  	fflush(stdin); //Limpiar el buffer
  	switch(eleccion)
	{
  		case 1:
  			printf("Dame el nombre de la tarea a insertar: ");
			scanf("%s",nombre_tarea);
  			printf("Dame el tiempo(en minutos) de ejecución de la tarea: ");
  			scanf("%d",&duracion_tarea);
  			Agregar(&inicio,&final,nombre_tarea,duracion_tarea);
  			break;
  		case 2:
  			printf("Retirar tareas con tiempo(en minutos) de ejecución menor a: ");
  			scanf("%d",&duracion_tarea);
  			int indice=0;
			int size = tam(inicio); //Tamaño de la cola
			struct datos datos_mostrar; 
  			if(size==0)
  				printf("La cola esta vacia\n");
  			while(indice < size){
  				datos_mostrar = Retirar(&inicio,&final); // Tomar el elemento de la cola
				if(datos_mostrar.duracion_tarea<=duracion_tarea)
					printf("Tarea retirada: %s, con duración de: %d minutos.\n",datos_mostrar.nombre_tarea,datos_mostrar.duracion_tarea);
			    else{
					Agregar(&inicio,&final,datos_mostrar.nombre_tarea,datos_mostrar.duracion_tarea);
				}
				free(datos_mostrar.nombre_tarea); //Liberar memoria reservada para el nombre_tarea
				indice++;
			}
			printf("\n");
  			break;
  	}
  }
  return 0;
}

//Función que agrega un elemento a la cola
void Agregar(persona **inicio, persona **final, char *cadena,int duracion_tarea)
{
	//Reservar memoria
	persona *nuevoNodo = (persona *)malloc(sizeof(persona));
	nuevoNodo->dato.nombre_tarea = (char *)malloc((strlen(cadena)+1)*sizeof(char));
	//Agregar el dato al nodo
	strcpy(nuevoNodo->dato.nombre_tarea,cadena);
	nuevoNodo->dato.duracion_tarea = duracion_tarea;
	//Ahora el nuevoNodo es el final de la cola y el siguiente es nulo
	nuevoNodo->siguiente = NULL;
	
	if(vacia(*final)) //¿Si la cola está vacía?
	{ 
		(*final) = nuevoNodo;
		(*inicio) = nuevoNodo;
	} else{
		(*final)->siguiente = nuevoNodo;
		(*final) = nuevoNodo;
	}
}

//Función que retira un elemento de la cola
struct datos Retirar(persona **inicio, persona **final)
{
	struct datos dato_mostrar;
	dato_mostrar.nombre_tarea = NULL;
	dato_mostrar.duracion_tarea = 0;
	if(!(vacia(*inicio))) //Si la cola NO esta vacía
	{
		dato_mostrar = (*inicio)->dato; //Tomar el dato del inicio
		//Hacemos referencia al nodo de inicio para poder liberar la memoria
		persona *temporal = *inicio;
		//Inicio apunta a siguiente
		(*inicio) = temporal->siguiente;
		if((*inicio)==NULL) //¿Si solo hay un nodo?
			(*final)=NULL; //Ahora, el final apunta a nulo
		//liberar memoria
		free(temporal);
		//printf("Retirando %s...\n",cadena);
		return dato_mostrar;
	}
	return dato_mostrar;
}

//Función para saber si la cola está vacía
int vacia(persona *cola)
{
	return cola==NULL; //Si la cola es nula, está vacía
}

//Función para saber el tamaño de la cola
int tam(persona *inicio)
{
	int n_elementos = 0;
	while(inicio!=NULL) //Mientras la cola no esté vacía
	{
		inicio = inicio->siguiente;
		n_elementos++;
	}
	return n_elementos;
}


