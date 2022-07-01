#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datos{
	char *nombre;
	int edad;
};

//Generar el elemento nodo
typedef struct datos_personas persona;

struct datos_personas
{
     struct datos dato; //Estructura de datos de la persona
	 persona *siguiente; //Puntero al siguiente elemento
};

//Prototipos
void Add(persona **, persona **, char *, int);
struct datos Pull(persona **, persona **);
int vacia(persona *);
int tamanio(persona *);

//Función principal
int main()
{
  //Declaración de variables
  int eleccion;
  char nombre[50]; //Vector de caracteres para el nombre
  int edad;
  
  //Crear la cola
  persona *inicio = NULL; //Puntero al inicio de la cola
  persona *final = NULL; //Puntero al final de la cola
  
  //Mensaje de inicio
  printf("Este progama simula un gestor de tareas de un procesador\n");
  
  //Menu
  while(eleccion != -1)
  {
  	printf("\n Menu\n 1.-Insertar tareas\n 2.-Tiempo de ejecución\n -1.-Salir\n\n\tElige: ");
  	scanf("%d",&eleccion);
  	fflush(stdin); //Limpiar el buffer
  	switch(eleccion)
	{
  		case 1:
  			printf("Dame el nombre de la tarea a insertar: ");
			scanf("%s",nombre);
  			printf("Dame el tiempo de ejecución de la tarea: ");
  			scanf("%d",&edad);
  			Add(&inicio,&final,nombre,edad);
  			break;
  		case 2:
  			printf("Retirar las tareas con tiempo de ejecuación menores a: ");
  			scanf("%d",&edad);
  			int indice=0;
			int size = tamanio(inicio); //Tamaño de la cola
			struct datos datos_mostrar;
  			if(size==0)
  				printf("La cola esta vacia\n");
  			while(indice < size){
  				datos_mostrar = Pull(&inicio,&final); // Tomar elemento de la cola
				if(datos_mostrar.edad<=edad)
					printf("%s y ",datos_mostrar.nombre);
			    else{
					Add(&inicio,&final,datos_mostrar.nombre,datos_mostrar.edad);
				}
				free(datos_mostrar.nombre); //Liberar memoria reservada para el nombre
				indice++;
			}
			printf("\n");
  			break;
  	}
  }
  return 0;
}

//Función que agrega un elemento a la cola
void Add(persona **inicio, persona **final, char *cadena,int edad)
{
	//Reservar memoria
	persona *nuevoNodo = (persona *)malloc(sizeof(persona));
	nuevoNodo->dato.nombre = (char *)malloc((strlen(cadena)+1)*sizeof(char));
	//Agregar el dato al nodo
	strcpy(nuevoNodo->dato.nombre,cadena);
	nuevoNodo->dato.edad = edad;
	//Ahora el nuevoNodo es el final de la cola y el siguiente es nulo
	nuevoNodo->siguiente = NULL;
	
	if(vacia(*final)) //¿La cola está vacía?
	{ 
		(*final) = nuevoNodo;
		(*inicio) = nuevoNodo;
	} else{
		(*final)->siguiente = nuevoNodo;
		(*final) = nuevoNodo;
	}
}

//Función que retira un elemento de la cola
struct datos Pull(persona **inicio, persona **final)
{
	struct datos dato_mostrar;
	dato_mostrar.nombre = NULL;
	dato_mostrar.edad = 0;
	if(!(vacia(*inicio))){//Si la cola NO esta vacía
		dato_mostrar = (*inicio)->dato;
		//Hacemos referencia al nodo de inicio para poder liberar la memoria
		persona *temporal = *inicio;
		//Inicio apunta a siguiente
		(*inicio) = temporal->siguiente;
		if((*inicio)==NULL) //Solo había un nodo?
			(*final)=NULL;
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
int tamanio(persona *inicio)
{
	int n_elementos = 0;
	while(inicio!=NULL){
		inicio = inicio->siguiente;
		n_elementos++;
	}
	return n_elementos;
}


