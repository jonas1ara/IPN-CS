/*
  Lista_Agenda.cpp
  17/11/21
  IIA Algoritmos y Estructuras 
  Este programa genera una lista dinámica para manejo de una agenda
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Generar el elemento nodo
struct nodo{
  char actividad[30];
  char hora[10];
  struct nodo *siguiente;
};

//Prototipos
void Insertar(struct nodo **, struct nodo **, char *, char *);
struct nodo *Buscar(struct nodo *, char *);
struct nodo *BuscarHora(struct nodo *, char *);
void EliminarActividad(struct nodo **, char *);
void EliminarHora(struct nodo **, char *, char *);
void Mostrar(struct nodo *);
void MostrarHora(struct nodo *, char *, char *);
int vacia(struct nodo *);
void obtenerHora(const char *, char *);

//Función principal
int main(void){
  //Declaracion de variables
  int eleccion,eleccion2;
  char actividad[30];
  char hora[10];
  char horafin[10];
  
  //Crear la lista
  struct nodo *inicio = NULL;
  
  //Nodo para las búsquedas
  struct nodo *nodoencontrado;
  
  //Mensaje de inicio
  printf("Este programa gestiona una agenda con una lista enlazada\n");
  
  //Menu
  while(eleccion != -1){
    printf("\n Menu\n1- Agregar evento\n2- Eliminar evento\n3- Actualizar evento\n4- Mostrar eventos\n-1- Salir\n\n\tElige: ");
    scanf("%d",&eleccion);
    fflush(stdin);
    switch(eleccion){
        case 1:
            printf("\nDame el evento a ingresar: ");
            gets(actividad);
            obtenerHora("Dame la hora: ",hora);
			nodoencontrado = BuscarHora(inicio,hora);
            Insertar(&inicio,&nodoencontrado,actividad,hora);
            break;
        case 2:
        	printf("\nSelecciona criterio:\n\t1- actividad\n\t2- hora\n\tElige: ");
        	scanf("%d",&eleccion2);
        	fflush(stdin);
        	if(eleccion2==1){
            	printf("\nDame la actividad a eliminar: ");
            	gets(actividad);
            	EliminarActividad(&inicio,actividad);
            }
            if(eleccion2==2){
            	obtenerHora("\nDame la hora inicial para comenzar eliminación: ",hora);
            	obtenerHora("Dame la hora final para terminar eliminación: ",horafin);
            	EliminarHora(&inicio,hora,horafin);
            }
            break;
        case 3:
            printf("Dime de que evento actualizamos la hora: ");
            gets(actividad);
            nodoencontrado = Buscar(inicio,actividad);
            printf("La hora en el nodo es: %s\n",nodoencontrado->hora);
            obtenerHora("Dime la nueva hora: ",nodoencontrado->hora);
			break;
        case 4:
        	printf("\nSelecciona criterio:\n\t1- Dia completo\n\t2- Intervalo de horas\n\tElige: ");
        	scanf("%d",&eleccion2);
        	fflush(stdin);
        	if(eleccion2==1){
	          	printf("Las actividades del dia son:\n");
	          	printf("%c",218);   //Mostrar formato de tabla
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c",191);
				printf("\n| Actividades | Hora  |\n");
            	printf("%c",195);
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c\n",180);
				Mostrar(inicio); //Mostrar lista completa
            	printf("%c",192);
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c\n",217);
            }
            if(eleccion2==2){
            	obtenerHora("\nDame la hora inicial del intervalo: ",hora);
            	obtenerHora("Dame la hora final del intervalo: ",horafin);
            	printf("Las actividades en el intervalo son:\n");
	          	printf("%c",218); //Formato de tabla
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c",191);
				printf("\n| Actividades | Hora  |\n");
            	printf("%c",195);
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c\n",180);
				MostrarHora(inicio,hora,horafin); //Mostrar intervalo
            	printf("%c",192);
	          	for(int l=0;l<21;l++)
	          		printf("%c",196);
	    		printf("%c\n",217);
            }
            break;
    }
  }
  return 0;
}

//Función que agrega un elemento a la lista
void Insertar(struct nodo **inicio, struct nodo **anterior, char *actividad, char *hora){
    printf("Agregando %s...\n",actividad);
    //Apuntador a un nuevo nodo
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    //Copiar el dato al nuevo nodo
    strcpy(nuevoNodo->actividad,actividad);
    strcpy(nuevoNodo->hora,hora);
    if(*anterior==NULL){ //Insertar al inicio de la lista
        nuevoNodo->siguiente = (*inicio); //Hacer que el nuevo nodo apunte al inicio
        (*inicio) = nuevoNodo;
    }
    else{ //Insertar en medio o al final de la lista
        nuevoNodo->siguiente = (*anterior)->siguiente;
        (*anterior)->siguiente = nuevoNodo;
    }
}

void EliminarActividad(struct nodo **inicio, char *actividad){
    if(!(vacia(*inicio))){//Si la lista NO esta vacía
        struct nodo *actual = (*inicio);
        struct nodo *anterior = NULL;
        int encontrado = 1;
        //Buscar el nodo a eliminar
        while((actual!=NULL)&&(encontrado)){
            encontrado = strcmp(actividad,actual->actividad);
            printf("El valor de comparar %s con %s es: %d\n",actividad,actual->actividad,encontrado);
            if(encontrado){
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        if(actual!=NULL){ //Si encontramos el nodo con la actividad
            printf("Retirando %s...\n",actual->actividad);
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

void EliminarHora(struct nodo **inicio, char *horaini, char *horafin){
    if(!(vacia(*inicio))){//Si la lista NO esta vacía
        struct nodo *actual = (*inicio);
        struct nodo *anterior = NULL;
        int encontrado = 1;
        //Buscar el nodo a eliminar
        while((actual!=NULL)&&(encontrado>0)){
            encontrado = strcmp(horaini,actual->hora);
            if(encontrado>0){
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        encontrado = strcmp(horafin,actual->hora);
        while(actual!=NULL&&encontrado>=0){
            printf("Retirando %s...\n",actual->actividad);
            //Inicio apunta a siguiente
            if(actual == (*inicio)){
                (*inicio) = actual->siguiente;
                free(actual);
                actual = (*inicio);
            }
            else{
                anterior->siguiente = actual-> siguiente;
            	//liberar memoria
            	free(actual);
            	actual = anterior->siguiente;
            }
            if(actual!=NULL){
            	encontrado = strcmp(horafin,actual->hora);
            }
        }
    }
    return;
}

struct nodo *Buscar(struct nodo *inicio, char *elemento){
    struct nodo *indice;
    for(indice=inicio;indice!=NULL;indice=indice->siguiente) //Se recorre la lista para buscar el dato
        if(!strcmp(elemento,indice->actividad)) //Se comparan las cadenas para ver si es el nodo que se busca
            return indice;
    return NULL;
}

struct nodo *BuscarHora(struct nodo *inicio, char *hora){
    struct nodo *indice;
    struct nodo *anterior = NULL;
    for(indice=inicio;indice!=NULL;indice=indice->siguiente){ //Se recorre la lista para buscar el dato
        if(strcmp(hora,indice->hora)<0) //Se comparan las cadenas para ver si es el nodo que se busca    	
            break;
        if(strcmp(hora,indice->hora)>0) //Se comparan las cadenas para ver si es el nodo que se busca    	
        	anterior = indice;
    }
    return anterior;
}

void Mostrar(struct nodo *inicio){
    struct nodo *indice;
    if(inicio==NULL){
        printf("|No hay actividades...|\n");
        return;
	}
    for(indice=inicio;indice!=NULL;indice=indice->siguiente) //Se recorre la lista para buscar el dato
        printf("| %11s | %s |\n",indice->actividad,indice->hora);
    return;
}

void MostrarHora(struct nodo *inicio, char *horaini, char *horafin){
    if(inicio==NULL){
        printf("|No hay actividades...|\n");
        return;
	}else{//Si la lista NO esta vacía	
        struct nodo *actual = inicio;
        int encontrado = 1;
        while((actual!=NULL)&&(encontrado>0)){
            encontrado = strcmp(horaini,actual->hora);
            //printf("%s - %s -> %d\n",horaini,actual->hora,encontrado);
            if(encontrado>0){
                actual = actual->siguiente;
            }
        }
        encontrado = strcmp(horafin,actual->hora);
        while(actual!=NULL&&encontrado>=0){
        	printf("| %11s | %s |\n",actual->actividad,actual->hora);
            //Inicio apunta a siguiente
            actual = actual->siguiente;
            if(actual!=NULL){
            	encontrado = strcmp(horafin,actual->hora);
            }
        }
    }
	return;
}

int vacia(struct nodo *lista){
    return lista==NULL;
}

void obtenerHora(const char *mensaje, char *hora){
	char hr[3], min[3];
	char horatmp[10];
	while(1){
		printf("%s",mensaje);
    	gets(hora);
    	if((strlen(hora)!=4&&strlen(hora)!=5)||(hora[2]!=':'&&hora[1]!=':')){
    		printf("La hora introducida es incorrecta, se espera formato de 24 hrs: HH:MM\nVuelva a intentarlo.\n");
	    	continue;
    	}else{
			if(strlen(hora)!=5){
        		strcpy(horatmp,hora);
        		strcpy(hora,"0");
        		strcat(hora,horatmp);
    		}
    		hr[0]=hora[0];
    		hr[1]=hora[1];
    		hr[2]='\0';
    		if(atoi(hr)<0||atoi(hr)>23){
	    		printf("La hora introducida es incorrecta, la hora debe estar entre 0 y 23 hrs\nVuelva a intentarlo.\n");
    			continue;
	    	}
	        min[0]=hora[3];
    		min[1]=hora[4];
    		min[2]='\0';
    		if(atoi(min)<0||atoi(min)>60){
    			printf("La hora introducida es incorrecta, los minutos deben estar entre 0 y 60\nVuelva a intentarlo.\n");
    			continue;
    		}
    		break;
    	}
    }
    return;
}

