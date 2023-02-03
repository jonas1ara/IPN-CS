/*
	ColaEstatica.cpp
  05/10/21
  IIA Algoritmos y Estructuras 
  Este programa genera una cola Estatica
*/
#include<stdio.h>

//Estructura
struct cola{
  int limite;
  char *elementos;
  int final;
};

//Prototipos
void imprimir(struct cola );
int crearcola(struct cola *,int);
int vacia(struct cola);
int llena(struct cola);
int retirar(struct cola *);
int adicionar(struct cola *,int);

//Funcion principal
int main(void){
  //Declarar variables
  int elegir=0, dato;
  //Crear la pila
  struct cola tail;
  
  //Mensaje de inicio
  printf("Cola Estatica\n");
  
  while(elegir != -1){
  	printf("\t1.- Agregar elemento\n");
    printf("\t2.- Retirar elemento\n");
    printf("\t3.- Imprimir cola\n");
    printf("\t4.- Comprobar si esta vacia\n");
    printf("\t5.- Imprimir tamanio\n");
    printf("\t-1.- Salir\n");
    printf("\n\n\tElige una opcion: ");
    scanf("%d",&elegir);
    switch(elegir){
      case 1:
    		//Ingresar datos con add
        printf("Ingresa el dato a agregar: ");
        scanf("%d",&dato);
  			adicionar(&tail,dato);
        break;
      case 2:
  	  	//Sacar datos con poll
        printf("El dato recuperado es: %d\n",retirar(&tail));
      case 3:
        //imprimir(tail);
        printf("Los datos de la cola son: \n");
        break;
      case 4:
        if(vacia(tail))
          printf("La cola esta vacia\n");
        else
          printf("La cola NO esta vacia\n");
        break;
      case 5:
        printf("El tamanio de la cola es: \n");
    }
  }
  return 0;
}

//Adicionar
int adicionar(struct cola *c, int valor){
 //Verificar si la cola esta llena
  if(llena(*c)==1)
   	return 0;
  //Ingresar el elemento
  p->elementos[p->final]=valor;
  //Incrementar el final
  p->final++;
  return 1;
}

//Retirar
int retirar(struct cola *p){
  int valor;
  if (isEmpty (*p==1)
      return -1;
  
  valor = p->elementos[0];
  for(int i=0;i<(p->final)-1;i++)    
  	p->elementos[i]=p->elementos[i+1];    
  p->final--;
  return valor;
}   

void imprimir(struct cola c){
  for(int i=0;i<c.final;i++)
  	printf(" %d",c.elementos[i]);
}

//Crear
int crearcola(struct cola *c,int no_elementos){
  if (no_elementos<0){
    return 0;}
  c->elementos = (int *)malloc(no_elementos * sizeof(int));
  c->limite = no_elementos-1;
  c->final=0;
  return 1;
}

//Vacia
int vacia(struct cola c){
  if(c.final == 0)
    		return 1;
  	return 0;
}
  
//Llena
int llena(struct cola c) {                  
  	if(c.final > c.limite)
      	return 1;
    return 0;
}
