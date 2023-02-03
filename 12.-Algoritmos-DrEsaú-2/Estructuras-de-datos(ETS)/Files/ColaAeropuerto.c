/*
  ColaDinamica.cpp
  16/11/21
  IIA Algoritmos y Estructuras 
  Este programa genera una cola dinámica
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>

//Generar el elemento nodo
typedef struct aeronave avion;
struct aeronave{
     int numero; //Numero de avion
     int tiempo; //Tiempo ingreso
     avion *siguiente; //Puntero al siguiente elemento
};

//Prototipos
void Add(avion **, avion **, int, int);
int Pull(avion **, avion **, int *, int *);
int vacia(avion *);
void Mostrar_hangar(int *, int);
void Recorrer(int *,int, int);
int Cuenta(avion *);
void Imprimir(avion *);

//FunciÃ³n principal
int main(void){
  setlocale(LC_CTYPE,"Spanish");
  //Declaracion de variables
  int avionaterrizaje; //Avión actual
  int max_cola_aterrizaje; //tamaño cola de aterrizaje
  int max_cola_despegue; //tamaño cola de despegue
  int max_hangar; //tamaño hangar
  int pasos_sim; //pasos de simulacióm
  float prob_llegada; //probabilidad de llegada
  float prob_despegue; //probabilidad de despegue
  int num_avion; //Número de avión en la cola
  int tiempo_avion; //Tiempo que esta el avión en la cola
  int aviones_hangar = 0; //Aviones en el hangar
  int avion_hangar; //Avión a seleccionar del hangar
  int avion_despegue; //Avión seleccionado
  int hangar[40]; //Arreglo del hangar
  int puede_despegar; //Bandera para ver si un avión puede despegar
  
  //Variables para estadisticas
  int aterrizaron = 0;
  int despegaron = 0;
  int rechazados = 0;
  int pasos_at=0;
  int pasos_de=0;
  
  //Crear la cola aterrizaje
  avion *iniAt = NULL;
  avion *finAt = NULL;
  
  //Crear la cola despegue
  avion *iniDe = NULL;
  avion *finDe = NULL;
  
  //Mensaje de inicio
  printf("Este programa simula un aeropuerto\n");
  
  //Pedir datos
  printf("¿Cuántos aviones pueden esperar para aterrizar (max_cola_aterrizaje)?:");
  scanf("%d",&max_cola_aterrizaje);
  printf("¿Cuántos aviones pueden esperar para despegar (max_cola_despegue)?:");
  scanf("%d",&max_cola_despegue);
  printf("¿Cuántos aviones pueden estar en el hangar (max_hangar)?:");
  scanf("%d",&max_hangar);
  printf("¿Cuántos pasos de tiempo simularemos?:");
  scanf("%d",&pasos_sim);
  printf("Dime la probabilidad de llegada de un avión:");
  scanf("%f",&prob_llegada);
  printf("Dime la probabilidad de que un avión esté listo para despegar:");
  scanf("%f",&prob_despegue);
  
  srand(time(NULL));
  
  avionaterrizaje = 0;
  
  //Ciclo de simulación
  for(int i=0;i<pasos_sim;i++){
  	printf("Tiempo %d: \n",i);
  	//Gestionar aterrizaje o despegue
  	if(Cuenta(iniAt)>0){ //Hay aviones en la cola de aterrizaje?
  		if(aviones_hangar<max_hangar){ //El hangar tiene espacio?
  			Pull(&iniAt,&finAt,&num_avion, &tiempo_avion); //Retirar avión de la cola de aterrizaje
  			printf("\tAvión %d aterrizó, estuvo en la cola de aterrizaje durante %d pasos de tiempo.\n",num_avion,i-tiempo_avion);
  			hangar[aviones_hangar]=num_avion; //Ingresar avión al hangar
			aviones_hangar++; //Incrementar la cuenta de aviones en el hangar
			pasos_at+=i-tiempo_avion; //Acumular los pasos que estuvo el avión para las estadísticas
			aterrizaron++; //Se incrementa el numero de aviones que aterrizaron para las estadísticas
			puede_despegar=0;
  		}else{ //El hangar esta lleno
  			printf("\tAvión %d no pudo aterrizar porque el hangar está lleno.\n",iniAt->numero);
  			puede_despegar=1;
  		}
  	} else 
  		puede_despegar=1;
  	
  	if(Cuenta(iniDe)>0&&puede_despegar){ //Hay aviones en la cola de despegue?
  		Pull(&iniDe,&finDe, &num_avion, &tiempo_avion); //Retirar avión de la cola de despegue
  		printf("\tAvión %d despegó, estuvo en la cola de despegue durante %d pasos de tiempo.\n",num_avion,i-tiempo_avion);
  		pasos_de+=i-tiempo_avion; //Acumular la cuenta de pasos de los aviones de despegue para estadísticas
  		despegaron++; //Se incrementa la cuenta de aviones que despegaron para las estadísticas
  	}
  	
  	//Probabilidad de llegada
  	int n_aterrizar = (rand()%2)+1; //Genero número aleatorio 1 o 2
  	for(int j=0;j<n_aterrizar;j++) //Llega un avión o 2 aviones
	  if(prob_llegada>=(rand()%101)/100.0){ //Calculo la probabilidad y verifico
  		printf("\tAvión número %d listo para aterrizar.\n",avionaterrizaje);
		if(Cuenta(iniAt)<max_cola_aterrizaje){ //Hay espacio en la cola de aterrizaje?
			Add(&iniAt,&finAt,avionaterrizaje,i); //Agregar avión
			avionaterrizaje++; //Se incrementa el número de avión
		}else{
			printf("\tAvión número %d rechazado pues la cola de aterrizaje no permite más aeronaves.\n",avionaterrizaje);
			rechazados++; //Incrementar la cuenta de rechazados
			avionaterrizaje++; //Se incrementa el número de avión
		}
	  }
	//Probabilidad de despegue
  	int n_despegue = (rand()%2)+1; //Genero número aleatorio 1 o 2
  	for(int j=0;j<n_despegue;j++) //Llega 1 o 2 aviones
	  if(prob_despegue>=(rand()%101)/100.0&&aviones_hangar){ //Calcular la probabilidad de despegue y verificar si hay aviones en el hangar
  		avion_hangar = rand()%aviones_hangar; //Producir un número aleatorio de retiro de avión del hangar
  		avion_despegue = hangar[avion_hangar]; //Ver cuál avión se retirará del hangar
  		printf("\tAvión número %d listo para despegar.\n",avion_despegue);
		if(Cuenta(iniDe)<max_cola_despegue){//La cola de despegue tiene espacio?
			Add(&iniDe,&finDe,avion_despegue,i); //Agregamos el avión a la cola de despegue
			Recorrer(hangar,avion_hangar,aviones_hangar); //Retirar del hangar
			aviones_hangar--; //Decremento el número de aviones en el hangar
		}else{
			printf("\tAvión número %d rechazado pues la cola de despegue no permite más aeronaves.\n",avion_despegue);
		}
	  }
	  
	//Mostrar colas
	printf("\tAviones en la cola de aterrizaje: ");
	Imprimir(iniAt);
	printf("\n\tAviones en la cola de despegue: ");
	Imprimir(iniDe);
  	printf("\n\tAviones en el hangar: ");
  	Mostrar_hangar(hangar,aviones_hangar);
  	printf("\n");
  }
  
  printf("Simulación concluida, estadísticas:\n");
  printf("\tNúmero total de aviones procesados (aviones que despegaron o aterrizaron): %d\n",despegaron+aterrizaron);
  printf("\tNúmero total de aviones que se les concedió turno para aterrizar: %d\n",aterrizaron);
  printf("\tNúmero total de aviones que se les concedió turno para despegar: %d\n",despegaron);
  printf("\tNúmero total de aviones que se rechazó en el aeropuerto: %d\n",rechazados);
  printf("\tNúmero total de aviones que quedaron en la cola de aterrizaje: %d\n",Cuenta(iniAt));
  printf("\tNúmero total de aviones que quedaron en la cola de despegue: %d\n",Cuenta(iniDe));
  printf("\tPromedio de espera en la cola de aterrizaje: %f pasos de tiempo\n",(float)pasos_at/aterrizaron);
  printf("\tPromedio de espera en la cola de despegue: %f pasos de tiempo\n",(float)pasos_de/despegaron);
  return 0;
}

//Función que agrega un elemento a la cola
void Add(avion **inicio, avion **final, int num, int tiempo){
	//printf("Agregando %d...\n",num);
	//Reservar memoria
	avion *nuevoNodo = (avion *)malloc(sizeof(avion));
	//Agregar el dato al nodo
	nuevoNodo->numero = num;
	nuevoNodo->tiempo = tiempo;
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

int Pull(avion **inicio, avion **final, int *num, int *tiempo){
	if(!(vacia(*inicio))){//Si la pila NO esta vacía
		*num = (*inicio)->numero;
		*tiempo = (*inicio)->tiempo;
		//Hacemos referencia al nodo de inicio para poder liberar la memoria
		avion *temporal = *inicio;
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

int vacia(avion *cola){
	return cola==NULL;
}

int Cuenta(avion *cola){
	int cont=0;
	while(cola!=NULL){
		cont++;
		cola = cola->siguiente;
	}
	return cont;
}

void Imprimir(avion *cola){
	while(cola!=NULL){
		printf("%d ",cola->numero);
		cola = cola->siguiente;
	}
	return;
}

void Recorrer(int *hangar,int desde, int hasta){
	for(int i=desde;i<hasta;i++){
		hangar[i]=hangar[i+1];
	}
	return;
}

void Mostrar_hangar(int *hangar, int limite){
	for(int i=0;i<limite;i++){
		printf("%d ",hangar[i]);
	}
	return;
}
