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
  int limite;
  int *elementos;
  int cima;
}


int main(){
  struct pila mipila;
  
  //Crear la pila y verificar que todo haya salido bien
  
  //Ingresar con push 3 valores 4, 6, 8
  
  //Usar pop para recuperar esos 3 valores e irlos imprimiendo.
  
  //Tratar de ingresar mas de 10 elementos para producir un overflow
  
  //Tratar de retirar mas elementos de los que tenga la pila para producir un underflow
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
  if(isfull(*p)==1)
    	return 0;
  //Ingresar el elemento
  p->elementos[p->cima] = valor;
  //Incremento la cima
  p->cima++;
  return 1;
}

//Pop


//isFullint isFull ( struct pila p ) {                  
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
