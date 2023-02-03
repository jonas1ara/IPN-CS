/*
  ColaDinamica.cpp
  20/10/21
  IIA Algoritmos y Estructuras 
  Este programa genera una cola dinámica
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datos{
	char *nombre;
	int edad;
};

//Generar el elemento nodo
typedef struct datos_personas persona;
struct datos_personas{
     struct datos dato;
	 persona *siguiente; //Puntero al siguiente elemento
};

//Prototipos
void Add(persona **, persona **, char *, int);
struct datos Pull(persona **, persona **);
int vacia(persona *);
int tamanio(persona *);

//FunciÃ³n principal
int main(void){
  //Declaracion de variables
  int eleccion;
  char nombre[50];
  int edad;
  
  //Crear la cola
  persona *inicio = NULL;
  persona *final = NULL;
  
  //Mensaje de inicio
  printf("Este programa genera una cola\n");
  
  //Menu
  while(eleccion != -1){
  	printf("\n Menu\n1- Insertar elemento\n2- Recuperar\n-1- Salir\n\n\tElige: ");
  	scanf("%d",&eleccion);
  	fflush(stdin);
  	switch(eleccion){
  		case 1:
  			printf("Dame el nombre de la persona a insertar: ");
  			gets(nombre);
  			printf("Dame la edad de la persona a insertar: ");
  			scanf("%d",&edad);
  			Add(&inicio,&final,nombre,edad);
  			break;
  		case 2:
  			printf("Recuperar los datos con numero mayor a: ");
  			scanf("%d",&edad);
  			int indice=0;
			int size = tamanio(inicio); //Tamaño de la cola
			struct datos datos_mostrar;
  			if(size==0)
  				printf("La cola esta vacia\n");
  			while(indice < size){
  				datos_mostrar = Pull(&inicio,&final); // Tomar elemento de la cola
				if(datos_mostrar.edad>=edad)
					printf("%s ",datos_mostrar.nombre);
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
void Add(persona **inicio, persona **final, char *cadena,int edad){
	//printf("Agregando %s...\n",cadena);
	//Reservar memoria
	persona *nuevoNodo = (persona *)malloc(sizeof(persona));
	nuevoNodo->dato.nombre = (char *)malloc((strlen(cadena)+1)*sizeof(char));
	//Agregar el dato al nodo
	strcpy(nuevoNodo->dato.nombre,cadena);
	nuevoNodo->dato.edad = edad;
	//Ahora el nuevoNodo es el final de la cola y el siguiente es nulo
	nuevoNodo->siguiente = NULL;
	
	if(vacia(*final)){ //La cola está vacía?
		(*final) = nuevoNodo;
		(*inicio) = nuevoNodo;
	} else{
		(*final)->siguiente = nuevoNodo;
		(*final) = nuevoNodo;
	}
}

struct datos Pull(persona **inicio, persona **final){
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

int vacia(persona *cola){
	return cola==NULL;
}

int tamanio(persona *inicio){
	int n_elementos = 0;
	while(inicio!=NULL){
		inicio = inicio->siguiente;
		n_elementos++;
	}
	return n_elementos;
}

