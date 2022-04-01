/*

_de_Hanoi_parte_2
 24/01/2012
 
 Escribe un programa (se recomienda que sea recursivo) que dé solución al problema de las torres de Hanoi.
 El enunciado es el siguiente: Se dispone de una torre formada por varios discos de diferentes diámetros denominada torre O (origen),
 donde cada disco es de diámetro inferior a todos los que están por debajo. Se dispone de otras dos torres para dejar discos, una denominada torre A (auxiliar) y otra torre D (destino).
 El problema consiste en pasar todos los discos de la torre O a la torre D respetando dos normas muy simples:
 
 Los discos se pasan de una torre a otra de uno en uno.
 Nunca un disco de mayor diámetro puede estar sobre otro de menor diámetro.
 Se preguntará al inicio del programa por el tamaño de la torre O (entendiendo que tendrá el número de discos indicados, con algún límite preestablecido).
 Las torres A y D estarán inicialmente vacías.
 Se debe ofrecer la solución que da el programa a este problema paso a paso, mostrando el resultado de una forma gráfica. El inicio podría ser algo así:
 
 *
    ***
   *****
 *******
 *********
    ===========		==========		==========
 O				A				D
*/
/*
 Formula para calcular movimientos mínimos necesarios:
 m = 2^n -1
 
 http://www.rodoval.com/heureka/hanoi/
*/
 
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
 
void imprime( int *tab, int fil, int col, int ultNum )
{
 /*
 Precondición:
 *tab	Puntero a una matriz de tipo entero.
 fil		Entero que indica el numero de filas de la matriz.
 col		Entero que indica el numero de columnas de la matriz.
 disc	Parámetro de tipo entero que indica el numero de discos usados.
 ultNum	Entero que indica el numero que esta usando el disco mas grande.
*/
 
 
 int f, c;
 int i, esp;
 
 
 for( c=col-1; c >= 0; c-- )
 {
 for( f=0; f < fil; f++ )
 {
 esp = ( ultNum - tab[col*f+c] )/2;
 
 // Espacios a la izquierda
 for( i=0; i < esp; i++ )
 printf( " " );
 
 // Imprime los comodines
 for( i=0; i < tab[col*f+c]; i++ )
 printf( "*" );
 
 // Espacios a la derecha
 for( i=0; i < esp; i++ )
 printf( " " );
 
 printf( "\t" );
 };
 
 printf( "\n" );
 };
 
 
};
 
 
void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
 /*
 Precondición:
 *tab	Puntero a una matriz de tipo entero.
 fil		Entero que indica el numero de filas de la matriz.
 col		Entero que indica el numero de columnas de la matriz.
 disc	Parámetro de tipo entero que indica el numero de discos usados.
 ultNum	Entero que indica el numero que esta usando el disco mas grande.
 filOrig	Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
 filDest	Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
 Poscondición:
 Se mueve el disco y se llama a la función que imprime el tablero.
 */
 
 
 int cO=col-1, cD=col-1;
 
 
 // Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
 while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
 {
 cO--;
 };
 if( cO < 0 )
 cO = 0;
 
 // Ahora se calcula cual es la posición libre mas arriba de la fila de destino
 while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
 {
 cD--;
 };
 
 // Se mueve el disco de la fila de origen a la de destino:
 tab[col*filDest+cD+1] = tab[col*filOrig+cO];
 tab[col*filOrig+cO] = 0;
 
 // Se imprime el tablero:
 imprime( tab, fil, col, ultNum );
};
 
 
void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
/*
Precondición:
 *tab	Puntero a una matriz de tipo entero.
 fil		Entero que indica el numero de filas de la matriz.
 col		Entero que indica el numero de columnas de la matriz.
 disc	Parámetro de tipo entero que indica el numero de discos usados.
 ultNum	Entero que indica el numero que esta usando el disco mas grande.
 O,A,D	Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
Poscondición:
 Se llama recursivamente a hanoi hasta resolver el tablero.
*/
 
 
 if( disc==1 )
 {
 // Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
 system("clear");
 mueveDisco( tab, fil, col, ultNum, O, D );
 if(col<=5) system("sleep 0.8"); else if(col<=10) system("sleep 0.3"); else if(col<=15) system("sleep 0.06"); else if(col>15) system("sleep 0.02");
 }
 else
 {
 hanoi( tab, fil, col, disc-1, ultNum, O, D, A );
 
 system("clear");
 mueveDisco( tab, fil, col, ultNum, O, D );
 if(col<=5) system("sleep 0.8"); else if(col<=10) system("sleep 0.3"); else if(col<=15) system("sleep 0.06"); else if(col>15) system("sleep 0.02");
 
 hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
 };
 
};
 
 
int main()
{
 int fil=3, col, *tablero = NULL;
 int f, c, disc=1, ultNum;
 
 
 printf( "Indique el numero de discos: " );
 scanf( "%i", &col );
 
 
 tablero = (int *)malloc( sizeof(int)*fil*col );
 
 
 // Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
 for( f=0; f < fil; f++ )
 for( c=col-1; c >= 0; c-- )
 if( f==0 )
 {
 tablero[col*f+c] = disc;
 disc+=2;
 }
 else
 tablero[col*f+c] = 0;
 
 ultNum = disc;
 
 // Se imprime el tablero antes de iniciar ningún movimiento:
 system("clear");
 imprime( tablero, fil, col, ultNum );
 system("sleep 1");
 
 
 // Se llama a hanoi para comenzar "la partida":
 hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
};
