/*
  PilaDinamica.cpp
  04/10/21
  IIA Algoritmos y Estructuras 
  Este programa genera una pila din√°mica
*/
#include<stdio.h>
#include<stdlib.h>

//Generar el elemento nodo
struct nodo{
  char dato;
  struct nodo *siguiente;
};

//Prototipos
void Push(struct nodo **, char);
char Pop(struct nodo **);
int vacia(struct nodo *);
int balanceoParentesis(char *);
void Liberar(struct nodo **);

//Funci√≥n principal
int main(void){
  //Declaracion de variables
  char cadena[80];
  
  //Mensaje de inicio
  printf("Este programa muestra si una expresion esta bien balanceada\n");
  
  //Pedir la cadena
  printf("Dame la cadena a evaluar: \n");
  gets(cadena);
  
  if(balanceoParentesis(cadena))
  	printf("Parentesis bien balanceados\n");
  else
  	printf("Expresion desbalanceada\n");
  	
  return 0;
}

int balanceoParentesis(char *S){
    //Crear la pila
	struct nodo *cima = NULL;
	int n_simbolo = 0;
	
    // leer siguientesÌmbolo de S
    while(S[n_simbolo]!='\0'){
    	if(S[n_simbolo]=='(') //si it = (
            Push(&cima,S[n_simbolo]);
        else if(S[n_simbolo]==')'){ //si it =)
        	printf("Se encontro )\n");
            if(Pop(&cima)==NULL) //Esta vacÌa
                return 0;
        	}
        n_simbolo++;
    }
    if(!vacia(cima)){
         Liberar(&cima);
         return 0;
    }
    return 1;
}

void Push(struct nodo **pila, char numero){
	printf("Agregando %c...\n",numero);
	//Reservar memoria
	struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
	//Agregar el dato al nodo
	nuevoNodo->dato = numero;
	//Ahora el nuevoNodo ser· la cim
	nuevoNodo->siguiente = *pila;
	*pila = nuevoNodo;
}

char Pop(struct nodo **pila){
	char x;
	if(!(vacia(*pila))){//Si la pila NO esta vacÌa
		x=(*pila)->dato;
		struct nodo *temporal = *pila;
		*pila = temporal->siguiente;
		//liberar memoria
		free(temporal);
		printf("Retirando %c...\n",x);
		return x;
	}
	return NULL;
}

void Liberar(struct nodo **pila){
	while(!(vacia(*pila))){//Si la pila NO esta vacÌa
		struct nodo *temporal = *pila;
		*pila = temporal->siguiente;
		//liberar memoria
		printf("Vaciando %c...\n",temporal->dato);
		free(temporal);
	}
}

int vacia(struct nodo *pila){
	return pila==NULL;
}
