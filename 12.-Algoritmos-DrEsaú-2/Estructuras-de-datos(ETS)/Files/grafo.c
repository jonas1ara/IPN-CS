/*
  Grafo.cpp
  13/12/21
  Esau Escobar
  Programa que muestra un grafo de forma enlazada
*/
#include<stdio.h>
#include<stdlib.h>

struct nodo{
    char nombre;//nombre del vertice o nodo
    struct nodo *siguiente;
    struct arista *ady;//puntero hacia la primera arista del nodo
};
            
struct arista{
    struct nodo *destino;//puntero al nodo de llegada
    struct arista *siguiente;
};

typedef struct nodo * Vertice;//  Tipo Nodo
typedef struct arista * Arco; //Tipo Arista


//Prototipos
void menu();
void insertar_nodo(Vertice *);
void agrega_arista(Vertice, Vertice, Arco);
void insertar_arista(Vertice *);
void vaciar_aristas(Vertice);
void eliminar_nodo(Vertice *);
void eliminar_arista(Vertice *);
void mostrar_grafo(Vertice);
void mostrar_aristas(Vertice);

//Función principal
int main(void){   
	Vertice p=NULL; //Grafo
    int op;     // opcion del menu
    
    do{
        menu(); //Mostrar menú
        scanf("%d",&op); //leer opción
        fflush(stdin);

        switch(op){
            case 1:
                insertar_nodo(&p);
                break;
            case 2:
				insertar_arista(&p);
                break;
            case 3:
				eliminar_nodo(&p);
                break;
            case 4:
				eliminar_arista(&p);
                break;
            case 5:
				mostrar_grafo(p);
                break;
            case 6:
				mostrar_aristas(p);
                break;
        }
        printf("\n\n");
    }while(op!=-1);
    return 0;
}

void menu(void){
	printf("\n\tRepresentacion de grafos dirigidos\n\n");
	printf("1. Insertar un nodo\n");
    printf("2. Insertar una arista\n");
    printf("3. Eliminar un nodo\n");
    printf("4. Eliminar una arista\n");
    printf("5. Mostrar grafo\n");
    printf("6. Mostrar aristas de un nodo\n");
    printf("-1. Salir\n");
    printf("\nIngrese opcion: ");
}

void insertar_nodo(Vertice *p){
    Vertice t;
	Vertice nuevo= (Vertice)malloc(sizeof(Vertice));
	printf("Ingrese variable: ");
    scanf("%c",&nuevo->nombre);
    fflush(stdin);
	nuevo->siguiente = NULL;
    nuevo->ady=NULL;

    if(*p==NULL){
        (*p) = nuevo;
        printf("Primer nodo...!!!");
    }else{
        t = *p;
        while(t->siguiente!=NULL){
            t = t->siguiente;
        }
        t->siguiente = nuevo;
        printf("Nodo ingresado...!!!");
    }
 }

void agrega_arista(Vertice aux, Vertice aux2, Arco nuevo){
    Arco q;
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        nuevo->destino=aux2;
        printf("Primera arista\n");
    }
    else
    {   q=aux->ady;
        while(q->siguiente!=NULL)
            q=q->siguiente;
        nuevo->destino=aux2;
        q->siguiente=nuevo;
        printf("Arista agregada\n");
    }
}

void insertar_arista(Vertice *p){
    char ini, fin;
    Arco nuevo=(Arco)malloc(sizeof(Arco));
    Vertice aux, aux2;

    if(*p==NULL){
        printf("Grafo vacío\n");
        return;
    }
    nuevo->siguiente=NULL;
    printf("Ingrese nodo de inicio: ");
    scanf("%c",&ini);
    fflush(stdin);
    printf("Ingrese nodo final: ");
    scanf("%c",&fin);
    fflush(stdin);
    aux=*p;
    aux2=*p;
    while(aux2!=NULL){
        if(aux2->nombre==fin){
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL){
    	printf("Vertice destino no encontrado...\n");
    	return;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            break;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL){
    	printf("Vertice origen no encontrado...\n");
    	return;
    }
	agrega_arista(aux,aux2, nuevo);
	printf("Arista agregada...\n");
	return;
}

void vaciar_aristas(Vertice aux){
    Arco q,r;
    q=aux->ady;
    while(q->siguiente!=NULL){
        r=q;
        q=q->siguiente;
        free(r);
    }
    return;
}

void eliminar_nodo(Vertice *p){
    char var;
    Vertice aux,ant;
    aux=*p;
    printf("Eliminar un nodo\n");
    if(*p==NULL){
        printf("Grafo vacio...!!!!");
        return;
    }
    printf("Ingrese el nombre del nodo: ");
    scanf("%c",&var);
    fflush(stdin);

    while(aux!=NULL){
        if(aux->nombre==var){
            if(aux->ady!=NULL)
                vaciar_aristas(aux);
            if(aux==*p){
                (*p)=(*p)->siguiente;
                free(aux);
                printf("Nodo eliminado...");
                return;
            }
            else{
                ant->siguiente = aux->siguiente;
                free(aux);
                printf("Nodo eliminado...");
                return;
            }
            
        }
        else{
            ant=aux;
            aux=aux->siguiente;
        }
    }
}

void eliminar_arista(Vertice *p){
	char ini, fin;
    Vertice aux, aux2;
    Arco q,r;
    printf("\n Eliminar arista\n");
    printf("Ingrese nodo de inicio: ");
    scanf("%c",&ini);
    fflush(stdin);
    printf("Ingrese nodo final: ");
    scanf("%c",&fin);
    fflush(stdin);
    aux=*p;
    aux2=*p;
    while(aux2!=NULL){
        if(aux2->nombre==fin){
            break;
        }
        else
        	aux2=aux2->siguiente;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            q=aux->ady;
            while(q!=NULL){
                if(q->destino==aux2){
                    if(q==aux->ady)
                        aux->ady=aux->ady->siguiente;
                    else
                        r->siguiente=q->siguiente;
                    free(q);
                    printf("Arista  %c ---> %c eliminada",aux->nombre,aux2->nombre);
                    return;
                }
                r=q;
            	q=q->siguiente;
            }
        }
        aux = aux->siguiente;
    }
}

void mostrar_grafo(Vertice p){
    Vertice ptr;
    Arco ar;
    ptr=p;
    printf("NODO|LISTA DE ADYACENCIA\n");

    while(ptr!=NULL){
        printf("   %c|",ptr->nombre);
        if(ptr->ady!=NULL){
            ar=ptr->ady;
            while(ar!=NULL){
                printf(" %c",ar->destino->nombre);
                ar=ar->siguiente;
            }
        }
        ptr=ptr->siguiente;
        printf("\n");
    }
}

void mostrar_aristas(Vertice p){
    Vertice aux;
    Arco ar;
    char var;
    printf("Mostar aristas de nodo\n");
    printf("Ingrese nodo: ");
    scanf("%c",&var);
    fflush(stdin);
    aux=p;
    while(aux!=NULL){
        if(aux->nombre==var){
            if(aux->ady==NULL){
            	printf("El nodo no tiene aristas!...\n");
                return;
            }
            else{
                printf("Nodo|Lista de adyacencia\n");
                printf("   %c|",aux->nombre);
                ar=aux->ady;
                while(ar!=NULL){
                    printf("%c ",ar->destino->nombre);
                    ar=ar->siguiente;
                }
                printf("\n");
                return;
            }
        }
        else
        	aux=aux->siguiente;
    }
}
