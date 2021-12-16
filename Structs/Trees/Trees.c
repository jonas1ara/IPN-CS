/*
	Arbol.cpp
	07/12/21
	Esaú Escobar
*/
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
 
//Definición de la estructura del nodo
struct nodoa{
    int valor;
    struct nodoa *izq, *der;
};
 
//Prototipos
void insertarArbol(struct nodoa **, int);
void imprimirArbol(struct nodoa *);
void borrarArbol(struct nodoa **);
struct nodoa *buscar(struct nodoa *, int);
int esHoja(struct nodoa *);
int alturaArbolNodo(struct nodoa *, int);
void alturaArbol(struct nodoa *, int *);
void auxAltura (struct nodoa *, int, int *); 
int vacio(struct nodoa *);
int cuenta(struct nodoa *);
struct nodoa *eliminacion(struct nodoa *, int);
struct nodoa *eli(struct nodoa *);
int menmay(struct nodoa *);
/*Funciones a agregar
mejorar Imprimir
Recorrido en profundidad
	PreOrden
	InOrden
	PostOrden
Recorrido en anchura
Convertir el árbol en AVL
	RSD
	RDD
	RSI
	RDI
*/

int main(void){
  //Declaración de variables
  struct nodoa *raiz;
  int dato, aux, eleccion;
  
  //Generamos el árbol vacío
  raiz = NULL; //Arbol vacío
  
  //Mensaje de inicio
  printf("Este programa gestiona un arbol binario de busqueda\n");
  
  //Menu
  while(eleccion != -1){
    printf("\n Menu\n1- Agregar dato\n2- Eliminar\n3- Mostrar\n4- Buscar\n");
	printf("Informacion:\n\t5- Hoja\n\t6- Altura nodo\n\t7- Altura Arbol\n\t8- Vacio\n\t9- Num nodos\n-1- Salir\n\n\tElige: ");
    scanf("%d",&eleccion);
    fflush(stdin);
    switch(eleccion){
        case 1: //Insertar un nodo
            printf("\nDame el dato a ingresar: ");
            scanf("%d",&dato);
            insertarArbol(&raiz, dato);
			break;
        case 2: //Eliminar un nodo
        	printf("\nEliminar que dato: ");
        	scanf("%d",&dato);
        	raiz = eliminacion(raiz,dato);
            break;
        case 3: //Imprimir árbol
            imprimirArbol(raiz);
            break;
        case 4:	//Buscar nodo
        	printf("\nDame el dato a buscar: ");
            scanf("%d",&dato);
            printf("Recorrido: ");
            if(buscar(raiz, dato)){ //Buscar devuelve el nodo encontrado
            	printf("%d\n",dato);
       			printf("El dato esta en el arbol\n\n");           
    		}else{
    			printf("?\n");
       			printf("El dato no esta en el arbol\n\n");      
    		}
			break;
    	case 5: //El nodo es hoja
    		//Verificamos si el Nodo pasado como parametro es Hoja o no
    		printf("\nDame el dato a verificar si es hoja: ");
            scanf("%d",&dato);
            if(esHoja(buscar(raiz, dato))){
		       printf("Es hoja\n\n");           
    		}else{
       			printf("No es hoja\n\n");      
		    }
    		break;
    	case 6:	//Altura nodo    		
    		printf("\nDame el dato a saber su altura: ");
            scanf("%d",&dato);
    		aux = alturaArbolNodo(raiz, dato);
    		printf("\nLa Altura del Nodo %d es: %d\n",dato,aux);
 			break;
 		case 7: //Obtenemos la Altura del Arbol
    		alturaArbol(raiz, &aux);
    		printf ("La Altura del Arbol es: %d\n\n", aux);
 			break;
     	case 8:	//Vacio
     		if(vacio(raiz))
     			printf("El arbol esta vacio\n\n");
     		else
     			printf("El arbol no esta vacio\n\n");
     		break;
     	case 9:	//Num nodos
     		printf("El arbol tiene %d nodos\n\n",cuenta(raiz));
     		break;
    }
  }
 //Borramos el Arbol
 borrarArbol(&raiz);
 printf("El Arbol fue borrado correctamente\n\n");
 return 0;
}
 
void insertarArbol(struct nodoa **raiz, int dato){
    if(*raiz == NULL){ //Si el nodo está vacío entonces reservar memoria e inicializar
        *raiz = (struct nodoa *)malloc(sizeof(struct nodoa));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{ //Si no está vacío entonces buscar un lugar vacío en el subárbol derecho o izquierdo
        if(dato <= (*raiz)->valor){
            insertarArbol(&(*raiz)->izq, dato);
        }else{
            insertarArbol(&(*raiz)->der, dato);
        }
    }
}
 
void imprimirArbol(struct nodoa *raiz){
    if(raiz != NULL){ //Recorrido en profundidad en orden
        imprimirArbol(raiz->izq);
        printf("%d, ", raiz->valor);
        imprimirArbol(raiz->der);
    }
}
 
void borrarArbol(struct nodoa **raiz){
    if(*raiz != NULL){ //Si la raíz tiene datos primero borramos los subarboles derecho e izquierdo
        borrarArbol(&(*raiz)->izq);
        borrarArbol(&(*raiz)->der);
        free (*raiz); //Borramos la raíz
        *raiz = NULL;
    }
}
 
struct nodoa *buscar (struct nodoa *raiz, int dato){
    if (raiz == NULL){ //Si la raíz es nula entonces el dato no se encuentra
        return NULL;
    }else{
        if (dato == raiz->valor){ //EL dato es justo el que tenemos en la raíz
            return raiz; //devolvemos el nodo
        }else{
            if (dato < raiz->valor){ //Recorremos los subarboles derecho o izquierdo según se necesite
            	printf("%d -> ",raiz->valor);
                return buscar(raiz->izq, dato);
            }else{
            	printf("%d -> ",raiz->valor);
                return buscar(raiz->der, dato);
            }
        }
    }
}
 
int alturaArbolNodo (struct nodoa *raiz, int dato){
    int altura=0;
    struct nodoa *actual=raiz;
    while(actual!=NULL){ //Recorremos el arbol buscando el nodo y contando la profundidad
        if(dato == actual->valor){ //Es el nodo buscado
            return altura; //Devolvemos altura
        }else{
            altura++; //Incrementamos la altura
            if(dato < actual->valor){ //Si el nodo buscado es menor que el valor de raíz entonces
                actual=actual->izq; // recorrer el subárbol izquierdo
            }else{
                if (dato > actual->valor){ //Si el nodo buscado es mayor que el valor de raíz entonces
                    actual=actual->der;  //recorrer el subárbol derecho
                }
            }
        }
    }
	printf("\nNo existe ese valor en el nodo.\n");
	return 0;
}
 
int esHoja(struct nodoa *raiz){
    if(!raiz->der && !raiz->izq) //Si el nodo no tiene hijos entonces es hoja
       return 1;
    else
       return 0; 
}
 
void alturaArbol(struct nodoa *raiz, int *altura){
    *altura=0;
    auxAltura(raiz, 0, altura);
}
 
void auxAltura(struct nodoa *raiz, int a, int *altura){
    if(raiz->izq){ //Si hay hijo izquierdo entonces bajar
        auxAltura(raiz->izq, a+1, altura);
    }
    if(raiz->der){ //Si hay hijo derecho entonces bajar
        auxAltura(raiz->der, a+1, altura);
    }
    if(esHoja(raiz) && a>*altura){ //Si el nodo es hoja y además es de mayor altura que los demás nodos 
        *altura=a; //Actualizar altura del árbol
    }
}

int vacio(struct nodoa *raiz){
    if (raiz == NULL) //Si la raíz es nula entoces el árbol está vacío
        return 1;
	else
		return 0;
}

int cuenta(struct nodoa *raiz){
    if (raiz == NULL){ //Si la raíz es nula regreso cero nodos
        return 0;
    }else{
        return cuenta(raiz->der)+cuenta(raiz->izq)+1; //Sumamos los nodos de los dos subarboles y el nodo raíz
    }
}

struct nodoa *eliminacion(struct nodoa *raiz, int dato){
	if(raiz!=NULL){
		if(dato == raiz->valor){
			printf("Si esta: %d\n",raiz->valor);
			return eli(raiz);
		}else{
            if(dato < raiz->valor){
            	printf("Recorre izq: %d\n",raiz->valor);
            	raiz->izq = eliminacion(raiz->izq, dato);
            	return raiz;
            }else{
            	printf("Recorre der: %d\n",raiz->valor);
                raiz->der = eliminacion(raiz->der, dato);
                return raiz;
            }
        }
	}
	else
	 	return NULL;
	
}

struct nodoa *eli(struct nodoa *raiz){
	struct nodoa *tmp;
    if(raiz->izq==NULL && raiz->der==NULL){
		free(raiz);
		printf("Caso1: sin hijos\n");
		return NULL;
	}
    else{
    	if(raiz->izq==NULL && raiz->der!=NULL){
    		tmp =raiz->der;
    		free(raiz);
    		printf("Caso2: hijoder: %d\n",tmp->valor);
            return tmp;
        }else{
        	if(raiz->izq!=NULL && raiz->der==NULL){
    			tmp =raiz->izq;
    			free(raiz);
    			printf("Caso2: hijoizq: %d\n",tmp->valor);
            	return tmp;
	        }
		    else{
            	int mm=menmay(raiz->der);
                raiz->valor=mm;
                printf("Caso3: memmay: %d\n",raiz->valor);
                eliminacion(raiz->der,mm);
                return raiz;
            }
    	}
	}
}

int menmay(struct nodoa *raiz){
	printf("entrando a memmay()\n");
    if(raiz->izq==NULL){
    	printf("Encontrado es %d\n",raiz->valor);
    	return raiz->valor;
    }
    else
        menmay(raiz->izq);
}

