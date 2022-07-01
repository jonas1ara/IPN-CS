//Bloque 6.3: Vectores de Estructuras y Ejemplo de Traductor Ingles/Español.
#include <stdio.h>
#include <string.h>
#define N 50 //Constante para el vector de caracteres

typedef struct {
 char eng[N]; 
 char esp[N];
 int lleno;
}traductor; //Declaración de la estructura de tipo traductor

traductor trad[N]; //Declaración de un vector de 50 estructuras de tipo traductor

//Prototipado de las funciones
void vacio();
void anadir();
void traducir();
void tradu(int op);
void cambio (char palabra[N]);

int main() 
{
 int op;
 char key;
 
 vacio();
 void anadir();
 
 do //Primer ciclo do while para las opciones 1(Añadir) y 2 (Buscar) 
 {
    do //Segundo ciclo do while para elegir si quieres realizar otra operación
    {
        printf ("Elige que deseas hacer:\n");
        printf ("(1) Anadir palabras al traductor.\n");
        printf ("(2) Buscar traduccion de la palabra en el traductor.\n");
        scanf ("%i", &op);
    } while (op < 1 || op > 2);
 
    switch (op) 
    {
        case 1:
            anadir();
        break;
        case 2:
            traducir();
        break;
    }
 
    printf ("Introduce si deseas realizar otra operacion. (S/N)");
    scanf ("%c", &key);
 } while(key == 'S' || key == 's');
 
 return 0;
}

//Función para poner todas las variables lleno de todas las estructuras del vector trad a 0 
void vacio() 
{
    for (int i=0 ; i<N ; i++) 
    {
    trad[i].lleno = 0; //trad[0]. lleno = 0, trad[1]. lleno = 0, ..., trad[49]. lleno = 0
    }
} 

//Función para añadir palabras al vector trad
void anadir() 
{
    int aux = 0; //auxiliar para ruta de escape
 
    //Recorrer cada vector trad e introducir palabras a cada vector de estructuras, hasta que se alcance el total de vectores
    for (int i=0 ; i<N && aux == 0 ; i++) 
    {
        //Para meter palabras en el vector trad, si la estructura esta vacia, se mete la palabra y se pone lleno a 1
        if (trad[i].lleno == 0) 
        {
        printf ("Introduce la palabra en ingles.\n");
        fflush(stdin); //Para que no se quede en el buffer la palabra introducida
        fgets (trad[i].eng,N,stdin); //fgets para INTRODUCTIR LA PALABRA en el vector trad[i].eng, N es la longitud del vector char eng[N]; , stdin es el flujo de entrada(entrada estandar del teclado)
        cambio (trad[i].eng); 
        printf ("Introduce la palabra en espanol.\n");
        fflush(stdin);
        fgets (trad[i].esp,N,stdin);
        cambio (trad[i].esp);
        trad[i].lleno = 1;
        aux = 1;
        }
    }
}
//Función para elegir en que idioma quiere traducir
void traducir() 
{
 int op;
 
 do //Ciclo do while para elegir una de las dos opciones
 {
      printf ("Elige que deseas hacer:\n");
      printf ("(1) Traducir de Ingles a Espanol.\n");
      printf ("(2) Traducir de Espanol a Ingles.\n");
      scanf ("%i", &op);    
  } while (op < 1 || op > 2);
 
 switch (op) 
 {
  case 1:
   tradu(op);
  break;
  case 2:
    tradu(op);
  break;
 }
}

//Función encargada de buscar la palabra en el vector trad, comparandola e intercarmbiandolas 
void tradu(int op) 
{
 int i, j, temp = 0; //Temporal para salir del ciclo for 
 char aux[N]; //Vector auxiliar para intercambiar palabras
 
 printf ("Introduce la palabra que desea buscar: \n");
 fflush(stdin); //Para que no se quede en el buffer la palabra introducida
 fgets (aux,N,stdin); //Guardar la palabra en el vector auxiliar
 cambio (aux);
 //Si op es 1, se busca la palabra en el vector trad[i].eng. Inglés a Espanol.
 if (op == 1) 
 {
  for (i=0 ; i<N && temp==0 ; i++)  //Recorrer el vector hasta N y si tempo auxiliar para hacer una sola vez
  {
    //Función para comparar palabras, comparar palabra por palabra de los vectores trad[i].eng con la dada por el usuario en aux[]
   j = strcmp (aux, trad[i].eng); //Si ambos son iguales, j = 0. Si no, j != 0.
   if (j == 0) 
   {
    printf ("La traduccion de %s es %s.\n", trad[i].eng, trad[i].esp); //Doy por hecho que la palabra a buscar esta en el mismo indice en ambos vectores
    temp = 1;
   }
  }
 } //Si op es 2, se busca la palabra en el vector trad[i].esp. Español a inglés.
 else {
   for (i=0 ; i<N && temp==0 ; i++) {
   j = strcmp (aux, trad[i].esp);
   if (j == 0) {
    printf ("La traduccion de %s es %s.\n", trad[i].esp, trad[i].eng);
    temp = 1;
   }
  }
 }
}

//Función para cambiar \n por \0
void cambio (char palabra[N]) //Le pasamos el vector de la palabra obtenido
{
 for (int i=0 ; i<N ; i++) //Recorrer la palabra hasta encontrar \n
 {
  if (palabra[i] == '\n') 
  {
   palabra[i] = '\0';
  }
 }
}