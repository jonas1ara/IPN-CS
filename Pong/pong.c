/*
	Nombre del programa: Ping Pong
	Autores: Fatima Avila ><, Aranza Gutierrez, Kevin Rodriguez y Jonas Lara.
	Fecha: 21 / 06 / 2021
	Descripción breve del programa: Ping pong a que te suena Rey
*/

#include <stdio.h> //Libreria de entradas y salidas estandar
#include <windows.h> //Libreria de C para windows (Uso de memoria, ventanas y procesador)
#include <conio.h> //E/S de datos para funciones MS-DOS
/*Constantes para las dimensiones de nuestro mesa*/
#define V 21 //Constante vertical para la altura de la matriz
#define H 75 //Constante Horizontal para el largo de la matriz

/*
Prototipos de las FUNCIONES
Recuerda que los prototipos le sirven al compilador para verificar las llamadas a las funciones
ya que le indican el tipo de dato que retorna la funcion, el numero, tipo y orden de parametros que recibe la misma.
*/
//
void inicio (char[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU);
//
void borde (char mesa[V][H]);
void raquetaJugador (char mesa[V][H], int inicioJugador, int finJugador);
void raquetaCPU (char mesa[V][H], int inicioCPU, int finCPU);
void pelota (char mesa[V][H], int pelotaX, int pelotaY);
void leer (char mesa[V][H]);
void gameloop(char mesa[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU, int modX, int modY, int modCPU);
void draw (char mesa[V][H]);
void input (char mesa[V][H], int *pelotaX, int *pelotaY, int *inicioJugador, int *finJugador, int *inicioCPU, int *finCPU, int *modX, int *modY, int *modCPU, int *gol);
void update (char mesa[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU);

int main(){
	
	/*Comienza inicializaci?n de variables*/
	
	//Declararemos el primer grupo; POSICI�N
	int pelotaX, pelotaY, inicioJugador, finJugador, inicioCPU, finCPU; //Declaramos variables de POSICI?N
		/*
		pelotaX = La posici?n en X de la pelota
		pelotaY = La posici?n en Y de la pelota
		inicioJugador = La posici?n de inicio de la raqueta
		finJugador = La posici?n final de la raqueta
		inicioCPU = La posici?n de inico de la raqueta de la CPU
		finCPU = La posici?n findal de la raqueta de la CPU
		*/
	//Declararemos el segundo grupo; MODIFICADO
	int modX, modY, modCPU; //Declaramos variables de MODIFICACI�N
		/*
		modX = Modificara la a posici?n en X de la pelota
		modY = Modificara la posici?n en Y de la pelota
		modCPU = Modificara la a posici?n de la raqueta de la CPU
		*/
	//Declaramos la MATRIZ MESA, para delimitar el espacio de juego
	char mesa[V][H];
		/*
		V = Posici�n VERTICAL(Alto) de la mesa
		H = Posici�n HORIZONTAL(Largo) de la mesa
 		*/
	char eleccion;
	/*Asignamos el valor de las variables de POSICI�N*/

	//Asignamos el VALOR de las variables de posici�n de la PELOTA
	pelotaX = 37; //La mitad de la mesa en X u Horizontal, no se utilizan 37.5 para evitar poner variables flotantes
	pelotaY = 10; //La mitad de la mesa en Y o Vertical, no se utilizan 10.5 para evitar poner variables flotantes
	
	//Asignamos el VALOR de las variables de posici�n de la RAQUETA DEL JUGADOR
	inicioJugador = 8; //Se comienza en 8 porque si la mitad de la mesa esta en diez(aproximandamente), nuestra raqueta va a ser de 4 casillas
	finJugador = 12;//Para cumplir que la raqueta sea de 4 casillas
	
	//Asignamos el VALOR de las variables de posici�n de la RAQUETA DE IA
	inicioCPU = 8; //Se comienza en 8 porque si la mitad de la mesa esta en diez(aproximandamente), nuestra raqueta va a ser de 4 casillas
	finCPU = 12;//Para cumplir que la raqueta ses de 4 casillas

	//Asignamos el VALOR de las variables de modificaci�n de la PELOTA y la CPU
	modX = -1; //Si alternamos estos valores el inicio de la pelota sera izquierda si negativo y derecha si es positivo
	modY = -1; //Si alternamos estos valores el inicio de la pelota sera izquierda si negativo y derecha si es positivo
	modCPU = -1;

	/*Termina asignaci�n de variables*/
	/*Termina inicializaci?n de variables*/
	
	/*Comienza uso de FUNCIONES*/
	printf("Bienvenido, estas apunto de enfrentarte con tu computadora, Crees poder vencerla?\n\n");
	printf("Esto es muy sencillo, debes ganarle a tu computadora en un juego de ping pong\n\n");
	printf("Mueve tu raqueta con las teclas (W para arriba y S para abajo)\n\n");
	printf("Listo?, escribe 's' para 'si' o escribe cualquier otra tecla si tienes miedo\n\n");
	scanf(" %c", &eleccion);
	if(eleccion=='s'){
		//Llamamos a la FUNCION de nombre INICIO que va recoger los valores de las variables de POSICI?N dentro de la MATRIZ MESA
		inicio(mesa, pelotaX, pelotaY, inicioJugador, finJugador, inicioCPU, finCPU); //En la llamada pasamos todos los elementos
	
		//Llamamos a una FUNCION del bucle del juego
		gameloop(mesa, pelotaX, pelotaY, inicioJugador, finJugador, inicioCPU, finCPU, modX, modY, modCPU);
	
		//system("pause"); //Comando EXCLUSIVO DE WINDOWS, indica al SO que realice una pausa para esperar una acci?n antes de cerrar la terminal
	}
	else if(eleccion!='s'){
		printf("/nMiedoso, de seguro le va al america, bye :v");
	}
	return 0;
	
}

/*Inician FUNCIONES para Interfaz de Usuario*/
/*Aqui comienza la FUNCI�N inicio*/
//Creamos una FUNCI�N llamada inicio y le pasamos los TIPOS DE DATOS, llamamos a los ELEMENTOS de la funci?n igual que los ELEMENTOS de fuera de la funci?n, para evitar declarar m?s variables y tener m?s nombres.
void inicio (char mesa[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU)
{
	//Dentro de esta FUNCI?N vamos a hacer una llamadas a las 4 FUNCIONES con las que construimos nuestros 4 elementos abstractos
	
	/*Inicia llamado de FUNCIONES*/
	borde(mesa); //Funci?n borde; nos sirve para delimitar el tama?o de la matriz y simular una mesa de Pong
	raquetaJugador(mesa, inicioJugador, finJugador); //Funci?n raquetaJugador; nos sirve para crear la raqueta del jugador dentro de la matriz mesa.
	raquetaCPU(mesa, inicioCPU, finCPU); //Funci?n raquetaCPU; nos sirve para crear la raqueta de la CPU dentro de la matriz mesa.
	pelota(mesa, pelotaX, pelotaY); //Funci?n pelota; nos sirve para crear la raqueta del jugador dentro de la matriz mesa.
	
	/*Finaliza llamado de FUNCIONES*/
}
/*Aqu? termina la funci?n inicio*/


/*Aqu? comienza la FUNCI?N para ESCRIBIR los limites de la matriz dentro de la terminal*/
//Creamos la FUNCI?N borde y le pasamos la matriz mesa, esta FUNCI?N nos ayudara escribir dentro de una matriz
void borde(char mesa[V][H]) 
{
	
	//Para escribir dentro de la matriz campo se necesitan dos Loops y se inicializan las variables enteras i para Vertical y j para Horizontal
	int i,j;
	
	for(i=0; i < V; i++) //Este ciclo crea las lineas Verticales de la mesa de Ping Pong
	{
	
		for(j=0; j < H; j++)
		{
			//Si i se encuentra en la coordenada 0 ? si i se encuentra en VERTICAL - 1 es decir la coordenada 20 va a pintar guiones en j hasta el limite de HORIZONTAL
			if (i == 0 || i == V-1) 
			{
				mesa[i][j] = '-';
			} 
			//Si j se encuentra en la coordenada 0 ? si j se encuentra HORIZONTAL - 1 es decir la coordenada 74 va a pintar guiones en i hasta el limite de VERTICAL
			else if (j == 0 || j == H-1)
			{
				mesa[i][j] = '|';
			}
			//De lo contrario se pintaran espacios dentro de la matriz
			else
			{
				mesa[i][j] = ' '; //Se pintan espacios en lo que resta de la matriz
			}			
		}
	}
}
/*Aquí finaliza la FUNCI?N para ESCRIBIR los limites de la matriz dentro de la terminal*/


/*Aqu? comienza la FUNCI?N para la RAQUETA del jugador*/
//Creamos una FUNCI?N llamada raquetaJugador y le pasamos los TIPOS DE DATOS que declaramos para la RAQUETA DEL JUGADOR.
void raquetaJugador (char mesa[V][H], int inicioJugador, int finJugador)
{
	//Recuerda que vamos a RECORRER una matriz y para eso necesitamos dos bucles. 
	//i es Vertical y j es Horizontal
	int i, j;
	
	//Nuestro proposito es que las raquetas inicien en el medio por eso NO vamos a iniciar i en 0 sino en inicioJugador
	//Nuestro proposito es que las raquetas inicien en el medio por eso NO vamos a finalizar i en 21 sino en finJugador
	for(i=inicioJugador; i <= finJugador; i++)
	{
		//Vamos a comenzar a pintar en j = 2 porque la l?nea que DELIMITA la mesa est?n en 0 y finalizamos una coordenada adelante
		for(j=2; j <= 3; j++)
		{
			mesa[i][j] = 'X';
		}
	}
}
/*Aqu? finzaliza la FUNCI?N para la RAQUETA del jugador*/


/*Aqu? comienza la FUNCI?N para la RAQUETA de la CPU*/
//Creamos una FUNCI?N llamada raquetaCPU y le pasamos los TIPOS DE DATOS que declaramos para la RAQUETA DE LA CPU
void raquetaCPU (char mesa[V][H], int inicioCPU, int finCPU)
{
	//Recuerda que vamos a RECORRER una matriz y para eso necesitamos dos bucles
	//i es Vertical y j es Horizontal
	int i, j;
	
	//Nuestro proposito es que las raquetas inicien en el medio por eso NO vamos a iniciar i en 0 sino en inicioJugador
	//Nuestro proposito es que las raquetas inicien en el medio por eso NO vamos a finalizar i en 21 sino en finJugador
	for(i=inicioCPU; i <= finCPU; i++)
	{
		//Vamos a comenzar a pintar en j = Horizontal -3  porque partimos de la l?nea que DELIMITA la mesa es decir la coordenada 75 y finalizamos una coordenada atras
		for(j=H-4; j <= H-3; j++)
		{
			mesa[i][j] = 'X';
		}
	}
}
/*Aqu? finzaliza la FUNCI?N para la RAQUETA de la CPU*/


/*Aqu? comienza la FUNCI?N para la PELOTA*/
//Creamos una FUNCI?N llamada pelota y le pasamos los TIPOS DE DATOS que declaramos para la PELOTA
void pelota (char mesa[V][H], int pelotaX, int pelotaY)
{
	//Esta FUNCI?N es la m?s facil de todas y que como solo tiene un solo car?cter y sabemos la posici?n que queremos que ocupe dentro de la matriz, solo le pasamos el valor al arreglo mesa 
	//Porque recuerda que ya est? declarada al inicio arriba como pelpelotaX = 37 y pelotaY = 10, esas coordenadas la posicionan a la MITAD de la matriz
	mesa[pelotaY][pelotaX] = 'O';
}
/*Aqu? finzaliza la FUNCI?N para la RAQUETA de la CPU*/


/*Aqu? comienza la FUNCI?N para imprimir la matriz*/
//Creamos una FUNCI?N llamada pelota y le pasamos los TIPOS DE DATOS que declaramos para la PELOTA

void leer (char mesa[V][H])
{
	//Esta FUNCI?N es la m?s facil de todas y que como solo tiene un solo car?cter y sabemos la posici?n que queremos que ocupe dentro de la matriz, solo le pasamos el valor al arreglo mesa 
	int i, j;
	
	for(i=0; i<V; i++)
	{
		for(j=0;j<H; j++)
		{
			printf ("%c",mesa[i][j]);
		}
		printf("\n");
	}
}
/*Aqui finzaliza la FUNCI�N para imprimir la matriz*/
/*Terminan funciones para Interfaz de Usuario*/

/*Aqui comienza la FUNCI�N para el bucle del juego*/
void gameloop(char mesa[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU, int modX, int modY, int modCPU)
{

	int gol;
	gol = 0; //Esta variable va a definir el juego y se necesita para la FUNCI�N POR PASO DE REFERENCIA, para que se modifique el valor y termine el ciclo

	do
	{
		draw(mesa); //Llamada a FUNCI�N draw para dibujar en pantalla
		input(mesa, &pelotaX, &pelotaY, &inicioJugador, &finJugador, &inicioCPU, &finCPU, &modX, &modY, &modCPU, &gol); 
		/*
		Input es una llamada a FUNCI�N a la funci�n input por PASO DE REFERENCIA para verificar y modificar las posiciones
		Necesitamos que lo que se modifique dentro de input, se modifique tambien fuera de la funci�n, es decir un paso por referencia de parametros
		Como sabes el PASO POR REFERENCIA DE PARAMETROS de una matriz, es poner el simbolo ampersand(por ser tipo entero) y el nombre
		Si no se coloca el ampersand no se realizaria un paso por parametros, sino un paso por valor y no se modificar�a el valor de la variable
		No olvides colocar la nueva variabel gol
		*/
		update(mesa, pelotaX, pelotaY, inicioJugador, finJugador, inicioCPU, finCPU); //Llamada a FUNCI�N update actualizar la matriz mesa}
		Sleep(.9999999999); //Usamos la FUNCI�N Sleep para dormir al procesador durante 100 milisegundos para que no se ejecute demasiado r�pido y podamos ver lo que ocurre en la pantalla
	} while (gol == 0);
}
/*Aqui finzaliza la FUNCION para el bucle del juego*/

/*Aqui comienza la FUNCI�N draw*/
void draw (char mesa[V][H]){
	system("cls"); //FUNCI�N para limpiar la terminal en Windows, si estas en Linux cambialo por system("clear")
	leer (mesa); ////Llamamos a la FUNCION leer para imprimir la mesa
}
/*Aqui finzaliza la FUNCION draw*/

/*Aqui comienza la FUNCI�N input*/
//Creamos la FUNCI�N input y le pasamos la matriz mesa y  los TIPOS DE DATOS pero como PUNTEROS para que se produzca el paso por referencia
//No olvides colocar la nueva variable gol
void input (char mesa[V][H], int *pelotaX, int *pelotaY, int *inicioJugador, int *finJugador, int *inicioCPU, int *finCPU, int *modX, int *modY, int *modCPU, int *gol)
{
	int i;
	char key;

	/*Comienza la l�gica del juego*/

	//Verificar en que posici�n se encuentra la pelota.
	//Bandas Horizontales
	if (*pelotaY == 1 || *pelotaY == V-2) //Si pelotaY esta en 1(No en 0 porque no queremos que se sobreescriban) o en 19 el modificador de Y se multiplicara por -1 para hacer uso de la ley de los signos
	{
		*modY *= -1; //De esta manera se invierte su direcci�n en vertical(Y) y mantiene la direcci�n en horizontal(X) 
	}
	//Bandas Verticales
	if (*pelotaX == 1 || *pelotaX == H-2) //Si pelotaX esta en 1(No en 0 porque no queremos que se sobreescriban)
	{
		*gol = 1; //Termina el juego
	}
	//Raqueta jugador
	if (*pelotaX == 4) //Se coloca 4 porque la raqueta de jugador termina en 3 y se desplaza 1 m�s para evitar sobreescribir
	{
		//Para hacer el rebote en la raqueta de jugador
		for(i = (*inicioJugador); i <= (*finJugador); i++) //i es igual al 8  y mientras  i sea menor o igual a 12, es decir 4 el tama�o de la raqueta,  aumentara i en 1
		{
			if(i==(*pelotaY)) //Esto quiere decir que i toma el valor de la raqueta y pelotaY es el movimiento de la pelota, y significa que la posicion d ela pelota en V sera la misma que una X de la raqueta
			{
				*modX *= -1; //Con esto hacemos que la pelota cambie de trayector�a, pero ahora en el eje X.
			}
		}
	}
	//Para hacer el rebote en la raqueta de la CPU
	if (*pelotaX == H-5) //Se coloca -5 para que comience en 70 en Horizontal y evitar sobreescribir
	{
		for(i = (*inicioCPU); i <= (*finCPU); i++) //i es igual al 8  y mientras i sea menor o igual a 12, es decir 4 el tama�o de la raqueta, aumentara i en 1
		{
			if(i==(*pelotaY)) //Esto quiere decir que i toma el valor de la raqueta y pelotaY es el movimiento de la pelota, y significa que la posicion d ela pelota en V sera la misma que una X de la raqueta
			{
				*modX*= -1;  //Con esto hacemos que la pelota cambie de trayector�a, pero ahora en el eje X.
			}
		}
	}
	//Para hacer que la raqueta de la CPU se mantenga en limite de la mesa
	if (*inicioCPU == 1 || *finCPU ==V-1) //Si inicio CPU esta en 1(No en 0 porque no queremos que se sobreescriban) o en 19 el modificador de Y se multiplicara por -1 para hacer uso de la ley de los signos
	{
		*modCPU *= -1; //Con esto hacemos que la pelota cambie de trayector�a, pero ahora en el eje y.
	}

	//Modificacion
	if (*gol == 0) 
	{
		//Movimiento de pelota
		*pelotaX += (*modX) ; //Al valor de pelotaX 37, le vamos a sumar el modificador de X que es -1
		*pelotaY += (*modY) ; //Al valor de pelotaY 10, le vamos a sumar el modificador de X que es -1

		//Raqueta de la IA
		*inicioCPU -= (*modCPU); //Menos es igual a ir para arriba
		*finCPU -= (*modCPU) ; //Se coloca en ambos para que mantengan la posición

		//Raqueta Jugador:
		if (kbhit() == 1)//kbhit es una función que se utiliza para comprobar si se presiona una tecla o no
		{ 
			key = getch() ;//Lo mismo que scanf solo que no hay que pulsar intro
				if (key == 'w' ) //Tecla para ir hacia arriba
				{
					if (*inicioJugador != 1) 
					{
						*inicioJugador -=1; //Menos es igual a ir para arriba
						*finJugador -=1; //Se coloca en ambos para que mantengan la posición
					}
				}
				if (key == 's')  //Tecla para ir hacia arriba
				{
					if (*finJugador != V-2)
					{
						*inicioJugador += 1;//Mas es igual a ir para arriba
						*finJugador += 1;//Se coloca en ambos para que mantengan la posición
					}
				}
		}
	}
}
/*Aqui finzaliza la FUNCI�N input*/


/*Aqui inicia la FUNCI�N update*/
void update (char mesa[V][H], int pelotaX, int pelotaY, int inicioJugador, int finJugador, int inicioCPU, int finCPU)
{
	borde(mesa); //Funci�n borde; nos sirve para delimitar el tama�o de la matriz y simular una mesa de Pong
	raquetaJugador(mesa, inicioJugador, finJugador); //Funci�n raquetaJugador; nos sirve para crear la raqueta del jugador dentro de la matriz mesa.
	raquetaCPU(mesa, inicioCPU, finCPU); //Funci�n raquetaCPU; nos sirve para crear la raqueta de la CPU dentro de la matriz mesa.
	pelota(mesa, pelotaX, pelotaY);
}

/*Aqui finzaliza la FUNCI�N update*/


