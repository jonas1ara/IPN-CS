//Realizar un programa para controlar varia bibliotecas usando estructuras dentro de estructuras.

#include <stdio.h>
#include <string.h>
#define N 50

typedef struct{
	char nombre_lib[N];
	char autor[N];
	int lleno_lib;
}libro;


typedef struct{
	char nombre_bi[N];
	libro lib[10]; //Estructura libro con tamaño 10 dentro de estructura biblioteca
	int lleno_bi;
}biblioteca;

biblioteca bi[3];

void vacio ();
void cambio(char palabra[N]);
void anadebi ();
void anadelib();
void consulta ();

int main()
{
	int op;
	char key;
	
	vacio();
	
	do{	
		do{
			printf("Elige una opcion a realizar: \n");
			printf("(1) Anadir una nueva biblioteca.\n");
			printf("(2) Anadir un libro a tu coleccion.\n");
			printf("(3) Consultar un libro.\n");
			scanf("%i",&op);
			
		}while(op < 1 || op > 3);
		
		switch (op){
		    case 1:{
			 anadebi();
			 break;
		    }
		    case 2:{
			 anadelib();
			 break;
		    }
		    case 3:{
			 consulta();
			 break;
		    }
			
		}	
		printf ("Deseas realizar otra operacion: (S/N)\n");
		fflush (stdin);
		scanf("%c",&key);
	}while(key == 'S' || key == 's');
	
	return 0;
}

//Nuestra función vacio es para que nuestras bibliotecas y nuestros libros comiencen a 0
//Una estructuras dentro de otra, es algo así como una matriz de estructuras
void vacio ()
{
	for (int i = 0; i < 3; i++)
	{
		bi[i].lleno_bi = 0;
		for (int j = 0; j < 10; j++)
		{
			bi[i].lib[j].lleno_lib = 0;
		}
	}
}
//Función para quitar el salto de linea en una cadena de caracteres de fgets
void cambio (char palabra[N])
{
	for (int i = 0; i < N; i++)
	{
		if (palabra[i]== '\n')
		{
			palabra[i]= '\0';
		}
	}
}

//Función para anadir una biblioteca
void anadebi ()
{
	int i,aux;
	aux = 0;
	for (i = 0; i < 3 && aux == 0;i++)
	{
		if (bi[i].lleno_bi == 0) //Si la biblioteca está vacia la puedo usar.
		{
			printf ("Introduce un nombre para la biblioteca: ");
			fflush(stdin); //Antes de meter strings, limpio el buffer de entrada.
			fgets (bi[i].nombre_bi,N,stdin); //fgets para leer una cadena de caracteres de N caracteres y guardalo en la variable nombre_bi.
			cambio(bi[i].nombre_bi);
			
			bi[i].lleno_bi = 1;
			aux = 1;
		}
	}
	
	if (aux == 0)
	{
		printf ("No queda ningun hueco libre para una nueva biblioteca.\n");
	}
}

//Función para anadir un libro a una biblioteca
void anadelib()
{
	int i,op,aux;
	aux = 0;
	
	for (i = 0;i < 3; i++) //Bucle para ver a que biblioteca añadir
	{
		if (bi[i].lleno_bi == 1); //Si la biblioteca está llena la imprimo en pantalla
		printf("(%i) %s.\n",i,bi[i].nombre_bi);	//numero de biblioteca y nombre de biblioteca
	}
	scanf("%i",&op); //Recoger el número de biblioteca donde vamos a guardar el libro
	
	for(i = 0; i < 10 && aux == 0;i++)
	{
		if (bi[op].lib[i].lleno_lib == 0) //Accediendo a la biblioteca con bi[op] y con lib[i] accediendo a cada uno de los libros su estan a 0, están vacios 
		{
			//Guardar el nuevo libro en la biblioteca
			printf ("Introduce el nombre del libro: ");
			fflush(stdin);
			fgets(bi[op].lib[i].nombre_lib,N,stdin);
			cambio (bi[op].lib[i].nombre_lib);
			
			//Guardar el nuevo autor en el libro
			printf ("Introduce el nombre del autor: ");
			fflush(stdin);
			fgets(bi[op].lib[i].autor,N,stdin);
			cambio (bi[op].lib[i].autor);
			
			bi[op].lib[i].lleno_lib = 1;
			aux = 1;
		}
	}
}

//Función para consultar un libro con su nombre o autor
void consulta ()
{
	int i,j,op,aux;
	char buscar[N];
	aux = 1;
	
	do
	{
		printf ("Que quieres buscar, nombre libro o nombre autor: \n");
	    printf ("(1)Nombre libro.\n");
	    printf ("(2)Nombre autor. \n");
	    scanf ("%i",&op);
	}while(op < 1 || op > 2);
	
	switch(op)
	{
		case 1: {
			printf("Introduce el nombre del libro: ");
			fflush(stdin);
			fgets(buscar, N, stdin); //Se introduce el nombre del libro que queremos buscar 
			cambio(buscar); 
			
			for (i = 0; i < 3; i++)
			{
				aux = 1;
				for(j = 0;j < 10; j++) //Recorremos el titulo del libro 
				{
				    aux = strcmp(buscar,bi[i].lib[j].nombre_lib);//Compara el nombre del libro con el nombre que queremos buscar
					if (aux == 0 )
					{
						printf ("El libro %s se encuentra en la biblioteca %s.\n",buscar,bi[i].nombre_bi);
						printf ("El autor del libro es %s.\n",bi[i].lib[j].autor);
					}	
				}
			}
			break;
		}
		case 2:{
			printf("Introduce el nombre del autor: ");
			fflush(stdin);
			fgets(buscar, N, stdin);
			cambio(buscar);
			
			for (i = 0; i < 3; i++){
				aux = 1;
				for(j = 0;j < 10; j++)
				{
				    aux = strcmp(buscar,bi[i].lib[j].autor); //Compara el dato introducido con el nombre del autor del libro
					if (aux == 0 )
					{
						printf ("El libro %s se encuentra en la biblioteca %s.\n",bi[i].lib[j].nombre_lib,bi[i].nombre_bi);
						
					}	
				}
			}
			break;
		}
	}
}