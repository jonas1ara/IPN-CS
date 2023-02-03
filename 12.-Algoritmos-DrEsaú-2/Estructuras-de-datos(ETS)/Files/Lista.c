/*
  Lista.cpp
  03/11/21
  IIA Algoritmos y Estructuras 
  Este programa genera una cola dinámica
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Generar el elemento nodo
struct nodo{
  char dato[30];
  struct nodo *siguiente;
};

//Prototipos
void Insertar(struct nodo **, struct nodo **, char *);
struct nodo *Buscar(struct nodo *, char *);
void Eliminar(struct nodo **, char *);
void Recorrer(struct nodo *);
int vacia(struct nodo *);

//FunciÃ³n principal
int main(void){
  //Declaracion de variables
  int eleccion;
  char cadena[80];
  char cadena2[80];
  
  //Crear la cola
  struct nodo *inicio = NULL;
  
  //Nodo para las búsquedas
  struct nodo *nodoencontrado;
  
  //Mensaje de inicio
  printf("Este programa genera una lista enlazada\n");
  
  //Menu
  while(eleccion != -1){
    printf("\n Menu\n1- Agregar elemento\n2- Eliminar\n3- Buscar\n4- Recorrer\n-1- Salir\n\n\tElige: ");
    scanf("%d",&eleccion);
    fflush(stdin);
    switch(eleccion){
        case 1:
            printf("Dame la cadena a ingresar: ");
            gets(cadena);
            printf("Después de cual cadena quieres insertar, en caso de no encontrarla se insertara al inicio: ");
            gets(cadena2);
            nodoencontrado = Buscar(inicio,cadena2);
            Insertar(&inicio,&nodoencontrado,cadena);
            break;
        case 2:
            printf("Dame la cadena a eliminar: ");
            gets(cadena);
            Eliminar(&inicio,cadena);
            break;
        case 3:
            printf("Dame la cadena a buscar: ");
            gets(cadena);
            nodoencontrado = Buscar(inicio,cadena);
            printf("El dato recuperado en el nodo encontrado es: %s\n",nodoencontrado->dato);
            break;
        case 4:
            printf("El contenido de la lista es:\n");
            Recorrer(inicio);
            break;
    }
  }
  return 0;
}

//Función que agrega un elemento a la lista
void Insertar(struct nodo **inicio, struct nodo **anterior, char *lista){
    printf("Agregando %s...\n",lista);
    //Apuntador a un nuevo nodo
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    //Copiar el dato al nuevo nodo
    strcpy(nuevoNodo->dato,lista);
    nuevoNodo-> dato;
    if(*anterior==NULL){ //Insertar al inicio de la lista
        nuevoNodo->siguiente = (*inicio); //Hacer que el nuevo nodo apunte al inicio
        (*inicio) = nuevoNodo;
    }
    else{ //Insertar en medio o al final de la lista
        nuevoNodo->siguiente = (*anterior)->siguiente;
        (*anterior)->siguiente = nuevoNodo;
    }
}

void Eliminar(struct nodo **inicio, char *cadena){
    if(!(vacia(*inicio))){//Si la lista NO esta vacía
        struct nodo *actual = (*inicio);
        struct nodo *anterior = NULL;
        int encontrado = 1;
        //Buscar el nodo a eliminar
        while((actual!=NULL)&&(encontrado)){
            encontrado = strcmp(cadena,actual->dato);
            printf("El valor de comparar %s con %s es: %d\n",cadena,actual->dato,encontrado);
            if(encontrado){
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        if(actual!=NULL){
            printf("Retirando %s...\n",actual->dato);
            //Inicio apunta a siguiente
            if(actual == (*inicio))
                (*inicio) = actual->siguiente;
            else
                anterior->siguiente = actual-> siguiente;
            //liberar memoria
            free(actual);
            return;
        }
    }
    return;
}

struct nodo *Buscar(struct nodo *inicio, char *elemento){
    struct nodo *indice;
    for(indice=inicio;indice!=NULL;indice=indice->siguiente) //Se recorre la lista para buscar el dato
        if(!strcmp(elemento,indice->dato)) //Se comparan las cadenas para ver si es el nodo que se busca
            return indice;
    return NULL;
}



void Recorrer(struct nodo *inicio){
    struct nodo *indice;
    for(indice=inicio;indice!=NULL;indice=indice->siguiente) //Se recorre la lista para buscar el dato
        printf("%s -> ",indice->dato);
    if(indice==NULL)
        printf("NULL");    
    return;
}

int vacia(struct nodo *lista){
    return lista==NULL;
}
