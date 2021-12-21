/*
-----Creado por neob
-----Juego de ping-pong.
-----Compilar con gcc -o pong pong.c -lncurses -lpthread .
-----Controles:
-- W - Mover la paleta hacia arriba.
-- S - Mover la paleta hacia abajo.
-- A - Mover la paleta hacia la izquierda.
-- D - Mover la paleta hacia la derecha.
*/
 
 
#include <stdio.h> //Simple constumbre....
#include <ncurses.h> //Utilizar ncurses.
#include <math.h> //Funciones para la obtención de números aleatorios ( rand() ).
#include <pthread.h> //Ejecución con varios hilos.
#include <time.h> //Proporciona time() que nos devuelve la hora.
 
/*******************************/
int salir_ncurses(); //Cierra el modo ncurses.
void dibujar_marco(); //Dibuja el marco.
void *hiloposiciones(); //Se encarga de mover la paleta y dibujar la paleta y la pelota.
void *hilomoverpelota(); //Se encarga de mover la pelota.
void dibujar_pelota(); //Dibuja la pelota en una posición aleatoria (la primera vez).
void pintar_paleta(); //Dibuja la paleta (la primera vez).
void direc_aleatoria(); //Una dirección aleatoria para la bola (la primera vez).
void escojer_dificultad(); //Se encarga de la dificultad del juego.
/*******************************/
 
 
/******   VARIABLES   *******/
int x_pelota, y_pelota, x_paleta, y_paleta, dpx_pelota, dpy_pelota, dificultad;
char key; //Guarda la tecla que pulsamos.
/*** Variables para los hilos ***/
pthread_t idhiloposiciones; //Identificador del hilo hiloposiciones
pthread_t idhilomoverpelota; //Identificador del hilo hilomoverpelota.
int error_hilo1, error_hilo2; //Para comprobar que no ha habido errores en los hilos.
/****************************/
 
 
int main()
{
	initscr(); //Entramos en ncurses.
	noecho(); //Que no salgan las teclas pulsadas.
 
        dibujar_marco(); //Dibujamos las paredes.
	pintar_paleta(); //Pintamos la paleta.
        dibujar_pelota();  //Dibujamos la pelota.
	direc_aleatoria(); //Para que se mueva la pelota por primera vez (Solo la llamamos aquí).
	escojer_dificultad(); //Le preguntamos al jugador la dificultad que quiere que tenga el juego (irá en función de la velocidad de la bola).
 
	srand( time(NULL) ); //Cambiamos la semilla de rand.
 
	error_hilo1 = pthread_create(&idhiloposiciones, NULL, hiloposiciones, NULL); //Lo creamos.
	error_hilo2 = pthread_create(&idhilomoverpelota, NULL, hilomoverpelota, NULL); //Lo creamos.
 
	if (error_hilo1 != 0 && error_hilo2 != 0) //Si ha habido error, no podemos seguir adelante.
	{
		clear();
		move(LINES/2,COLS/2);
		printw("ERROR AL CREAR HILOS DE EJECUCIÓN.");
		return -1;	
	} 
 
	while( key != 'e' && key != 'E' )//Si pulsamos E, nos vamos.
	{
		key = getch();
		if (key == 'w' || key == 'W') { x_paleta = x_paleta - 1; }
		if (key == 's' || key == 'S') { x_paleta = x_paleta + 1; }
		if (key == 'a' || key == 'A') { y_paleta = y_paleta - 1; }
		if (key == 'd' || key == 'D') { y_paleta = y_paleta + 1; }
	}
 
	salir_ncurses(); kill(&idhiloposiciones); kill(&hilomoverpelota); return 0; //Hemos salido pulsando E, salimos de ncurses, matamos los hilos y nos vamos.
 
}
 
void *hiloposiciones()
{
	for(;;) 
	{
	    int i; //Para contar.
 
	    clear(); //Borramos la pantalla para renovar todas las posiciones.
	    dibujar_marco(); //Volvemos a dibujar el marco.
 
            /*************** PALETAS ***********/
            if (y_paleta != 0 && y_paleta <= COLS -1 && x_paleta != 0 && (x_paleta - 3) != LINES - 1) //No vas a atravesar el marco, no¿?
	    {
	    	for( i=0; i<4; i++ )
	        {
			move(x_paleta + i, y_paleta);
			printw("#");
	        }
	    } else 
	     {
                   if (y_paleta <= 0) 
		   {
			y_paleta = 1; //Volvemos a ajustarla a 1 (para que no pueda salir del marco por la izquierda).
		   	for( i=0; i<4; i++ )
	                {
				move(x_paleta + i, y_paleta);
				printw("#");
	           	}	
		   }
 
            	   if (y_paleta >= COLS - 1)
		   { 
		   	y_paleta = COLS - 2; //Volvemos a ajustarla a COLS - 2 (para que no pueda salir del marco, pero esta vez por la derecha).
		   	for( i=0; i<4; i++ )
	               	{
				move(x_paleta + i, y_paleta);
				printw("#");
           	 	}
		   }
 
            	   if (x_paleta <= 0) //Para que no se salga por arriba.
		   { 
		   	x_paleta = 1;
		   	for( i=0; i<4; i++ )
	               	{
				move(x_paleta + i, y_paleta);
				printw("#");
           	 	}
		   }
 
		   if ( (x_paleta + 3) >= LINES - 1) //Para que no se salga por debajo.
		   { 
		   	x_paleta = LINES - 4;
		   	for( i=0; i<4; i++ )
	               	{
				move(x_paleta + i, y_paleta);
				printw("#");
           	 	}
		   }
	      }	
 
	     /***************** PELOTA ******************/
	     move(x_pelota, y_pelota); //Segun las posiciones marcadas por el hilo hilomoverpelota...
	     printw("O"); // ...pintamos las pelota.
 
/*	     //----LO UTILIZO PARA VER LOS ERRORES EN LAS VARIABLES Y EN LAS POSICIONES.
	     move(3,3); 
	     printw("-DEBUG: dpx_pelota=%d; dpy_pelota=%d; x_pelota=%d; y_pelota=%d; x_paleta=%d; y_paleta=%d;", dpx_pelota, dpy_pelota, x_pelota, y_pelota, x_paleta, y_paleta); //DEBUG
*/
 
	     if (y_pelota <= 0) //Significa que no ha parado la pelota, se acaba el juego.
	     {
	  	    kill(idhiloposiciones); kill(idhilomoverpelota);
		    clear();
	  	    move(LINES/2,COLS/2);
	  	    printw("FIN DEL JUEGO!");
	     }
 
	     if ( (y_pelota == y_paleta) && ((x_pelota == x_paleta) || (x_pelota == x_paleta + 1) || (x_pelota == x_paleta + 2)  || (x_pelota == x_paleta + 3)) ) 
	     {
  	     	   dpy_pelota = - dpy_pelota; //Si rebota contra la pala, tenemos que cambiar su sentido.
	     	   y_pelota = y_pelota + dpy_pelota; //Después de cambiar su sentido hay que volver a actualizar la posición de la pelota.
	     }
 
	     usleep(20*1000); //sleep() trabaja con segundos, por eso usamos usleep(), que trabaja con milisegundos.
	     refresh(); //Mostramos los cambios en las posiciones.
 
	}
}
 
/*************************** MOVIMIENTO PELOTA ***************************/
void *hilomoverpelota()
{
	for(;;)
	{
	     if (!( (y_pelota == y_paleta) && ((x_pelota == x_paleta) || (x_pelota == x_paleta + 1) || (x_pelota == x_paleta + 2)  || (x_pelota == x_paleta + 3))) )
	     {   
                     x_pelota = x_pelota + dpx_pelota; //Si no está rebotando con la pala, tiene que continuar su camino, por lo que sigue por su camino.
		     y_pelota = y_pelota + dpy_pelota;
	     }
 
	     if (x_pelota <= 1) //Para que la pelota rebote contra la pared.
	     {
	     	 dpx_pelota = - dpx_pelota;
	     }
 
	     if (x_pelota >= LINES - 1) //Para que la pelota rebote contra la pared.
	     {
	     	 dpx_pelota = - dpx_pelota;     
	     }
 
	     if (y_pelota >= COLS - 1) //Para que la pelota rebote contra la pared.
	     {
	     	 dpy_pelota = - dpy_pelota;     
	     }
 
	     usleep( dificultad*1000 );
	}
}
 
 
 
 
 
/************ Funciones secundarias como dibujar objetos, salir de ncurses, ... ******************/
 
int salir_ncurses()
{
	endwin();
	return 0;
}
 
void dibujar_marco()
{
	int i;
        for(i=0;i<LINES;i++) //Pintamos las paredes: LINES indica el numero de lineas de la terminal y COLS el de columnas (proporcionados por la librería ncurses).
        {
        	move(i,0);
        	printw("|");
        	move(i,COLS - 1);
        	printw("|");
        }
 
	for(i=0;i<COLS-1;i++)
	{
		move(0,i);
		printw("_");
		move(LINES -1,i);
		printw("_");
	}
}
 
void dibujar_pelota() //Dibujamos la pelota (en una posicion aleatoria dentro de un margen).
{
	x_pelota = (int) ( rand() % ((LINES/2+4)-(LINES/2-4)+1) + (LINES/2 - 4) ); //Escojemos un numero aleatorio con rand().
	y_pelota = (int) ( rand() % ( (((COLS-1) - COLS/9) + 4)-(((COLS-1) - COLS/9) - 4)+1 ) + (((COLS-1) - COLS/9) - 4) );
	move(x_pelota, y_pelota);
	printw("O");	
}
 
 
void pintar_paleta() //Pintamos la paleta.
{
	int i;
	y_paleta = 3; // Eje y > columnas
	x_paleta = LINES/2 - 3; // Eje x >> líneas
 
	for( i=0; i<4; i++ )
	{
		move(x_paleta + i, y_paleta);
		printw("#");
	}
}
 
void direc_aleatoria() //Elejimos una primera dirección aleatoria para la pelota.
{
	dpx_pelota = ( rand() % (+1 - (-1) +1) + (-1) );
	dpy_pelota = -1;
 
}
 
 
void escojer_dificultad() //Escojemos la dificultad del juego.
{
	char d;
	clear();
	move(3,3);
	printw("\n-Creado por Juan Escudero Pedrosa.\n"
	       "-Indique el nivel de dificultad:\n"
	       "\t1 - Fácil.\n"
	       "\t2 - Medio.\n"
	       "\t3 - Difícil.\n\n"
	       "\t(Los controles son W,S,A y D)");
	d = getch();
	switch(d)
	{
		case '1': dificultad = 200; break;
		case '2': dificultad = 100; break;
		case '3': dificultad = 50; break; 
		default: 
			clear(); 
			move(3,3); 
			printw("No se ha seleccionado ningún nivel de dificultad, se tomará por defecto el nivel 2 (Medio). Pulse una tecla para continuar.");
	                dificultad = 100;
			getch();
		break;
	}
 
}

