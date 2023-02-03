/*
	PilaEstatica.cpp
  28/09/2021
  IIA Algoritmos y estructuras de datos
  Este programa genera una pila estática
*/
#include<stdio.h>
#include<stdlib.h>

//Usar una estructura para guardar la pila que contenga
//  - Los elementos en un arreglo
//  - cima
//  - limite
struct pila{
  int *elementos;
  int cima;
  int limite;
};

int crearpila(struct pila *, int);
int push(struct pila *, int);
int pop(struct pila*);
int isFull(struct pila);
int isEmpty(struct pila);


int main(){
  struct pila mipila;
  int tam;
  
  //Mensaje de inicio
  printf("Programa que crea un TDA Pila y muestra algunas funciones\n");
  
  printf("Dame el tamanio de la pila: ");
  scanf("%d",&tam);
  
  //Crear la pila y verificar que todo haya salido bien
  if(!crearpila(&mipila,tam)){
  	printf("No se pudo crear la pila\n");
  	return -1;
  }
  
  //Ingresar con push 3 valores 4, 6, 8
  printf("El primer push ingresa: 4\n");
  push(&mipila,4);
  printf("El segundo push ingresa: 6\n");
  push(&mipila,6);
  printf("El tercer push ingresa: 8\n");
  push(&mipila,8);
  
  //Usar pop para recuperar esos 3 valores e irlos imprimiendo.
  printf("El primer pop da: %d\n",pop(&mipila));
  printf("El segundo pop da: %d\n",pop(&mipila));
  printf("El tercer pop da: %d\n",pop(&mipila));
  
  //Tratar de ingresar mas de 10 elementos para producir un overflow
  for(int i=0;i<11;i++){
  	printf("Ingresando un %d\n",i);
  	if(!push(&mipila,i))
  		printf("Se produjo un overflow con i = %d\n",i);
  }
  
  //Tratar de retirar mas elementos de los que tenga la pila para producir un underflow
  int valor;
  for(int i=0;i<11;i++){
    valor = pop(&mipila);
  	if(valor == -1)
  		printf("Se produjo un underflow con i = %d\n",i);
    else
    	printf("Se recupera un %d\n",valor);
  }
  
}

//Crear Pila
int crearpila(struct pila *p, int no_elementos){
  if (no_elementos<0){
    return 0;}
  p->elementos = (int *)malloc(no_elementos * sizeof(int));
  p->limite = no_elementos-1;
  p->cima=0;
  return 1;
}

//Push
int push(struct pila *p, int valor){
  //Comprobaciones: Verificar si no hay overflow
  if(isFull(*p)==1)
    	return 0;
  //Ingresar el elemento
  p->elementos[p->cima] = valor;
  //Incremento la cima
  p->cima++;
  return 1;
}

//Pop
int pop(struct pila *p){
	int valor;
	//Comprobar: Verificar si no hay un underflow
	if(isEmpty(*p)==1)
		return -1;
	//Recuperar el valor que esta en la cima	
	valor = p->elementos[p->cima-1];
	//Borrar el valor en la cima y decrementar la cima
	p->elementos[p->cima-1]=0;
	p->cima--;
	
	return valor;
}

//isFull
int isFull ( struct pila p ) {                  
  	if(p.cima > p.limite)
      	return 1;
    return 0;
}

//isEmpty
int isEmpty(struct pila p){
  	if(p.cima == 0)
    	return 1;
  	return 0;
}
