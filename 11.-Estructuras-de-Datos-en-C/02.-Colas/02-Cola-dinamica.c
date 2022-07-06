#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Generar el elemento nodo
typedef struct actividad agenda;
struct actividad{
     char act[50]; //Actividad a realizar...
     char hora[10]; //Hora de la actividad...
     agenda *siguiente; //Puntero al siguiente elemento
};

//Prototipos
void Add(agenda **, agenda **, char *, char *);
int Pull(agenda **, agenda **, char *, char *);
int vacia(agenda *);

//FunciÃ³n principal
int main(void){
  //Declaracion de variables
  int eleccion;
  char act[50];
  char hora[10];
  
  //Crear la cola
  agenda *inicio = NULL;
  agenda *final = NULL;
  
  //Mensaje de inicio
  printf("Este programa genera una cola\n");
  
  //Menu
  while(eleccion != -1){
  	printf("\n Menu\n1- Agregar elemento\n2- Recuperar\n-1- Salir\n\n\tElige: ");
  	scanf("%d",&eleccion);
  	fflush(stdin);
  	switch(eleccion){
  		case 1:
  			printf("Dame la actividad a ingresar: ");
  			gets(act);
  			printf("Dame la hora a ingresar: ");
  			gets(hora);
  			Add(&inicio,&final,act,hora);
  			break;
  		case 2:
  			if(Pull(&inicio,&final,act,hora))
  				printf("La actividad y su hora recuperadas son: %s -- %s\n",act,hora);
  			else
  				printf("Tu agenda esta vacia\n");
  			break;
  	}
  }
  return 0;
}

//Función que agrega un elemento a la cola
void Add(agenda **inicio, agenda **final, char *cadena, char *hora){
	//printf("Agregando %s...\n",cadena);
	//Reservar memoria
	agenda *nuevoNodo = (agenda *)malloc(sizeof(agenda));
	//Agregar el dato al nodo
	strcpy(nuevoNodo->act,cadena);
	strcpy(nuevoNodo->hora,hora);
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

int Pull(agenda **inicio, agenda **final, char *cadena, char *hora){
	if(!(vacia(*inicio))){//Si la pila NO esta vacía
		strcpy(cadena,(*inicio)->act);
		strcpy(hora,(*inicio)->hora);
		//Hacemos referencia al nodo de inicio para poder liberar la memoria
		agenda *temporal = *inicio;
		//Inicio apunta a siguiente
		(*inicio) = temporal->siguiente;
		if((*inicio)==NULL) //Solo había un nodo?
			(*final)=NULL;
		//liberar memoria
		free(temporal);
		//printf("Retirando %s...\n",cadena);
		return 1;
	}
	return 0;
}

int vacia(agenda *cola){
	return cola==NULL;
}
