/*
	Hash.cpp
	22/11/2021
	Esau Escobar
	Programa que genera una tabla hash abierta
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define TAM_TABLA 1553 //Longitud de la tabla
//#define TAM_TABLA 1024 //Longitud de la tabla

struct hash_nodo{
	char *clave;  //Campo llave
	char *valor;  //Valor del nodo
	int ocupado;  //campo para indicar si el nodo esta ocupado
	struct hash_nodo *siguiente; //En caso de colisión aquí comienza la lista
};

struct hash_tabla{
	struct hash_nodo **tabla; //lista de apuntadores a los nodos
};

//Prototipos
struct hash_tabla *crear(void);
int funcion_hash(char *);
int add_nodo(struct hash_tabla *, char *, char *);
void inicializar(struct hash_nodo *);
char *Recuperar(struct hash_tabla *, char *);
int Borrar(struct hash_tabla *, char *);
void BorraCompleta(struct hash_tabla *);

int main(void){
//Declaracion de variables
  int eleccion,i,j,n,colisiones;
  char valor[30];
  char clave[30];
  
  //Crear la tabla
  struct hash_tabla *tablaH = crear();
  
  srand(time(NULL));
  
  //Mensaje de inicio
  printf("Este programa gestiona una tabla hash abierta con una lista enlazada\n");
  
  //Menu
  while(eleccion != -1){
    printf("\n Menu\n1- Agregar dato\n2- Eliminar\n3- Mostrar\n4- Aleatorio\n-1- Salir\n\n\tElige: ");
    scanf("%d",&eleccion);
    fflush(stdin);
    switch(eleccion){
        case 1:
            printf("\nDame el dato a ingresar: ");
            gets(valor);
            printf("Dame la clave: ");
            gets(clave);
            add_nodo(tablaH, clave, valor);
            break;
        case 2:
        	printf("\nEliminar que dato: ");
            gets(clave);
            if(Borrar(tablaH,clave))
            	printf("Dato borrado correctamente\n");
            else
            	printf("No se encontro la clave\n");
            break;
        case 3:
            printf("Dime la clave del dato a mostrar: ");
            gets(clave);
            printf("El dato con esa clave es: %s\n",Recuperar(tablaH,clave));
            break;
        case 4:
        	printf("\nCuantos datos simular: ");
        	scanf("%d",&n);
        	fflush(stdin);
        	colisiones=0;
            for(j=0;j<n;j++){
				for(i=0;i<5;i++){
            		clave[i]=(rand()%27)+65;
            	}
            	clave[5]='\0';
            	printf("Genera clave: %s\n",clave);
            	itoa(j,valor,10);
            	printf("Valor a introducir: %s\n",valor);
            	colisiones += add_nodo(tablaH, clave, valor);
            }
            printf("El numero de colisiones fue: %d\n",colisiones);
            break;
    }
  }
  BorraCompleta(tablaH);
  return 0;
}

//Función que crea la tabla
struct hash_tabla *crear(void){
	struct hash_tabla *Tabla = (struct hash_tabla *)malloc(sizeof(struct hash_tabla)); //Reservar memoria para la estructura tabla
	Tabla->tabla = (struct hash_nodo **)malloc(sizeof(struct hash_nodo)*TAM_TABLA); //Resevar memoria para la tabla
	memset(Tabla->tabla,0,sizeof(struct hash_nodo)*TAM_TABLA); //Inicializar a 0 toda la tabla
	return Tabla;
}

//Función que calcula el valor hash método de división
/*int funcion_hash(char *clave){
	int len = strlen(clave);
	long long int numero_clave = 0;
	for(int i=0;i<len;i++) //Convertir caracteres a un sólo entero
		numero_clave += numero_clave*128+clave[i];
	return numero_clave%TAM_TABLA; //Función hash de división
}*/

//Función 2 método de multiplicación
/*int funcion_hash(char *clave){
	int len = strlen(clave);
	long long int numero_clave = 0;
	for(int i=0;i<len;i++) //Convertir caracteres a un sólo entero
		numero_clave += numero_clave*128+clave[i];
	double tmp;
	return (int)floor(TAM_TABLA*modf((((sqrt(5)-1.0)/2.0)*numero_clave),&tmp));
}*/

//Función 3 método de aproximación
int funcion_hash(char* key){
	unsigned int hash = 1315423911;
	unsigned int i = 0;
	for(i = 0; i < strlen(key); key++, i++)
		hash ^= ((hash << 5) + (*key) + (hash >> 2));
	return hash%TAM_TABLA;
}


int add_nodo(struct hash_tabla *tablaH, char *clave, char *valor){
	int colision = 0;
	int posicion_tabla = funcion_hash(clave); //Obtener la posicion con la función hash
	printf("La posicion hash calculada es: %d\n",posicion_tabla);
	struct hash_nodo *p = tablaH->tabla[posicion_tabla]; //Recuperar el nodo en esa posición
	struct hash_nodo *ant = p;
	
	while(p){ //Si ya hay algo en la posición de la tabla entonces
	    colision = 1;
		if(strcmp(clave,p->clave)==0){ //Si es la misma clave actualizar el valor
			strcpy(p->valor,valor);
			break;
		}
		printf("Ya hay algo en la tabla[%d] valor: %s\n",posicion_tabla,p->valor);
		ant = p;
		p = p->siguiente;
	}
	
	if(!p){
		struct hash_nodo *tmp = (struct hash_nodo *)malloc(sizeof(struct hash_nodo));
		inicializar(tmp); //Función que inicializa el nodo
		char *tmp_clave = (char *)malloc((strlen(clave)+1)*sizeof(char)); //Generamos memoria para la clave a guardar
		strcpy(tmp_clave,clave); //Copiamos la clave en la memoria reservada
		tmp->clave = tmp_clave; //Actualizamos clave
		char *tmp_valor = (char *)malloc(30*sizeof(char)); //Generamos memoria para el valor a guardar
		strcpy(tmp_valor,valor); //Copiamos el valor en la memoria reservada
		tmp->valor = tmp_valor; //Actualizamos valor
		tmp->ocupado = 1; //Se marca como utilizado
		if(ant != NULL) // El nodo formará parte de una lista, ya había colisiones
			ant->siguiente = tmp; //Se coloca al final de la lista
		else //El nodo es el primero en esa posición
			tablaH->tabla[posicion_tabla] = tmp; //Se coloca en la tabla
	}
	return colision;
}

//Inicializar todos los valores a nulo
void inicializar(struct hash_nodo *nodo){
	nodo->siguiente = NULL;
	nodo->clave = NULL;
	nodo->valor = NULL;
	nodo->ocupado = 0;
}

//Función que recupera un dato
char *Recuperar(struct hash_tabla *tablaH, char *clave){
	int posicion_tabla = funcion_hash(clave); //Obtener la posicion con la función hash
	struct hash_nodo *p = tablaH->tabla[posicion_tabla]; //Recuperar el nodo en esa pos
	while(p){  //Revisar si el nodo tiene algún valor
		printf("Hay algo en la tabla[%d] valor: %s\n",posicion_tabla,p->valor);
		if(strcmp(p->clave,clave)==0) //Preguntar si el nodo es el correspondiente a la clave
			return p->valor; //Regresar el valor en el nodo
		p = p->siguiente; //Recorrer la lista
	}
	return NULL; //Si no esta el nodo regresar nulo
}

//Función que borra un dato
int Borrar(struct hash_tabla *tablaH, char *clave){
	int posicion_tabla = funcion_hash(clave); //Obtener la posicion con la función hash
	struct hash_nodo *p = tablaH->tabla[posicion_tabla]; //Recuperar el nodo en esa posición
	struct hash_nodo *ant = p; //Guardar el nodo anterior
	while(p){  //Revisar si el nodo tiene algún valor
		printf("Hay algo en la tabla[%d] valor: %s\n",posicion_tabla,p->valor);
		if(strcmp(p->clave,clave)==0){ //Preguntar si el nodo es el correspondiente a la clave
		    printf("Retirando %s...\n",p->valor);
            //Inicio apunta a siguiente
            if(p == tablaH->tabla[posicion_tabla])
                tablaH->tabla[posicion_tabla] = p->siguiente;
            else
                ant->siguiente = p-> siguiente;
            //liberar memoria
            free(p->valor);
            free(p->clave);
            free(p);
            return 1;
		}
		ant = p;
		p = p->siguiente; //Recorrer la lista
	}
	return 0; //Si no esta el nodo regresar nulo
}

void BorraCompleta(struct hash_tabla *tablaH){
    if (tablaH){
        if (tablaH->tabla){
            for (int i = 0; i<TAM_TABLA; i++){	// Recorrer cada nodo
			    struct hash_nodo *p = tablaH->tabla[i];
                struct hash_nodo *q = NULL;
                while (p){		// Hay contenido de almacenamiento en este nodo
				    q = p;
                    p = q->siguiente;
                    printf("Eliminando: %s\n",q->valor);
                    free(q->valor);
                    free(q->clave);
                    free(q);
                }
            }
            free(tablaH->tabla);	// Libera el uso de memoria del puntero de almacenamiento de la tabla  
        }
        free(tablaH);		// Libera el puntero de la tabla
    }
	return;
}
