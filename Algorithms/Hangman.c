/*Descripción: 
Este ejercicio funciona como un juego del ahorcado.El jugador 1 ingresa una palabra o
frase y una pista para que el jugador 2 intente adivinarla.
Cada jugada tiene su valor de puntos en caso de adivinar una letra.
Además se le muestra al usuario el estado actual del juego
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50 //maximo de letras para adivinar
int main()
{
	//DECLARACIÓN DE VARIABLES
	char palabras[MAX + 1];							   //Palabra o frase para adivinar. Reservamos una posición pra el caracter nulo
	unsigned short i;								   //variable contadora para el ciclo for
	unsigned short puntos = 0, fallos = 0, logros = 0; //puntos acumulados, fallos totales y letras adivinadas
	unsigned char intento;							   //letra que ingresa el usuario para adivinar
	unsigned short bandera;							   //bandera nos indicará si el usuario adivinó alguna letra o no
	unsigned char pista[MAX + 1];
	unsigned char reinicio[3] = {'s', 'i', '\0'}; //respuesta para otra partida o salir del juego
	unsigned short num_espacios = 0;			  //variable acumuladora, numero de espacios de la frase ingresada

	//INTERFAZ DE ENTRADA
	while (strcmp(reinicio, "si") == 0)
	{

		printf(">>BIENVENIDO AL JUEGO<<\n\n");
		printf("Usted es el jugador 1. Le toca retar al jugador 2");

		//BLOQUE DE INSTRUCCIONES
		printf("\nIngrese una palabra o frase con ENTER para empezar a jugar. No debe sobrepasar las %d letras.\n", MAX);
		printf("Todas las letras ingresadas deben ser mayusculas o todas minusculas\n");
		gets(palabras);							 //guardamos la frase a adivinar
		unsigned char elegida[strlen(palabras)]; //creamos otra cadena del mismo tamaño que la cadena ingresada
		strcpy(elegida, palabras);				 //copiamos la cadena en "elegida". Ahora cuenta con posiciones exactas

		unsigned char oculta[strlen(elegida)]; //esta palabra será la elegida pero con guiones bajos para ocultarla y mostrar solo las que adivine el usuario
		for (i = 0; i < strlen(elegida); i++)
		{					 //ciclo for para llenar a oculta de guiones bajo hasta la ultima posición antes del caracter nulo
			oculta[i] = '_'; //oculta queda semejante a: "_ _ _ _ _"
		}

		for (i = 0; i < strlen(elegida); i++)
		{ //ciclo para colocar espacios en caso de que la cadena "elegida" contenga más de una palabra
			if (elegida[i] == ' ')
			{
				oculta[i] = ' '; //colocamos ese espacio en la palabra "oculta".
				num_espacios++;
			}
		}

		printf("\nIngrese una pista para su companero (por ejemplo: pelicula, serie, color, etc.)\n");
		gets(pista);
		system("cls"); //limpiar pantalla

		//Interfaz para Jugador 2
		printf("\nSe ha seleccionado una palabra para jugar a adivinarla");
		printf("\n\n>>BIENVENIDO AL JUEGO<<\n\n");
		printf("Jugador 1 ha ingresado una frase. Le toca adivinarla letra por letra antes de acumular ocho fallos\n");
		printf("Cada ronda tiene su valor de puntos\n");
		printf("Buena suerte :) \n");

		printf("Tu oponente te dio la siguiente pista: ");
		puts(pista);

		while (fallos < 8 && logros < (strlen(oculta) - num_espacios)) //este ciclo se repite mientras tenga menos de 8 fallos y no haya adivinado todas las letras de "elegida" sin contar espacios en blanco
		{

			bandera = 0; //cada repetición del ciclo while, bandera reinicia su valor. Si la letra no es correcta, se mantiene en 0

			printf("\n\nIngrese una letra:   "); //intento de adivinar una letra
			scanf("%c", &intento);
			system("cls");

			for (i = 0; i < strlen(elegida); i++)
			{
				if (intento == elegida[i] && intento != oculta[i])
				{						 //si el intento existe en la palabra elegida, se pone esa letra en "oculta"
					bandera = 1;		 // 1 significa que la letra fue encontrada en "elegida"
					oculta[i] = intento; //reemplazamos el guión bajo de oculta por la letra adivinada
					logros = logros + 1;

					{
						if (i >= 0 && i < 10)
						{ //Condicional para puntos. Segun la posición de i, asiganmos puntos a la ronda. Esto es para hacerlo "al azar"
							puntos = puntos + ((i + 1) * 1000);
						} //i+1 porque el primer valor de i es cero, acumulando sería 0 puntos
						else
							puntos = puntos + ((i + 1) * 700);
					}

					//buscando a nemo=elegida
					//b_______ _ ____= oculta
				}
			}
			if (bandera == 0)
			{ //en caso de no encontrarse la letra en "elegida",sumamos un fallo
				fallos = fallos + 1;
				printf("\nLa letra no se encuentra");
			}

			printf("\nNumero de fallos: %d", fallos); //tras cada intento mostramos el estado actual del juego
			printf("\nPuntos:           %d", puntos);
			printf("\nletras adivinadas:  %s", oculta);
			fflush(stdin); //limpiamos el buffer de entrada para poder ingresar otro intento
		}

		//mostramos el resultado de la partida
		if (fallos == 8)
		{ //si tuvo los 8 fallos, le indicamos que perdió la partida
			system("cls");
			printf("\n\nHas perdido el juego. Sigue intentando en otra partida :)");
			printf("\nRESULTADOS DE LA PARTIDA:\n");
			printf("Score final:         %d", puntos);
			printf("\nLetras adivinadas: %s", oculta);
		}
		if (logros == strlen(elegida))
			;
		{ //si tuvo todas las letras logradas, le mostramos que ganó el juego
			system("cls");
			printf("\n\nFELICIDADES, has ganado el juego :) \n");
			printf("\nRESULTADOS DE LA PARTIDA:\n");
			printf("Fallos:              %d", fallos);
			printf("\nScore final:       %d", puntos);
			printf("\nFrase adivinada: %s", oculta);
		}

		printf("\n\nDeseas jugar de nuevo?\n");
		scanf("%s", &reinicio);
		fflush(stdin);
		system("cls");
	}

	//INTERFAZ DE SALIDA
	printf("\nPulse ENTER para salir");
	fflush(stdin);
	getchar();

	return 0;
}
