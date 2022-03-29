/*
  ____          _____               _ _           _       
 |  _ \        |  __ \             (_) |         | |      
 | |_) |_   _  | |__) |_ _ _ __ _____| |__  _   _| |_ ___ 
 |  _ <| | | | |  ___/ _` | '__|_  / | '_ \| | | | __/ _ \
 | |_) | |_| | | |  | (_| | |   / /| | |_) | |_| | ||  __/
 |____/ \__, | |_|   \__,_|_|  /___|_|_.__/ \__, |\__\___|
         __/ |                               __/ |        
        |___/                               |___/         
    
____________________________________
/ Si necesitas ayuda, contáctame en \
\ https://parzibyte.me               /
 ------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
Creado por Parzibyte (https://parzibyte.me).
------------------------------------------------------------------------------------------------
Si el código es útil para ti, puedes agradecerme siguiéndome: https://parzibyte.me/blog/sigueme/
Y compartiendo mi blog con tus amigos
También tengo canal de YouTube: https://www.youtube.com/channel/UCroP4BTWjfM0CkGB6AFUoBg?sub_confirmation=1
O PayPal: https://paypal.me/LuisCabreraBenito
------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FILAS 3
#define COLUMNAS 3
#define TAMANIO_MATRIZ FILAS *COLUMNAS
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define JUGADOR_CPU_X JUGADOR_X
#define JUGADOR_CPU_O JUGADOR_O
#define ESPACIO_VACIO ' '
#define CONTEO_PARA_GANAR 3
// Modos de juego
#define JUGADOR_JUGADOR 1
#define JUGADOR_CPU 2
#define CPU_CPU 3
#define SALIR 4

// Clona la matriz. Útil para las simulaciones que se hacen, así no se modifica el tablero original
void clonarMatriz(char tableroOriginal[FILAS][COLUMNAS], char destino[FILAS][COLUMNAS])
{
    memcpy(destino, tableroOriginal, TAMANIO_MATRIZ);
}

// Establece todo el tablero en espacios vacíos
// Pd: quién te conoce memset
void limpiarTablero(char tablero[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            tablero[y][x] = ESPACIO_VACIO;
        }
    }
}

// Imprime el tablero de juego
void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    printf("\n");
    int y;
    int x;
    // Imprimir encabezado
    printf("| ");
    for (x = 0; x < COLUMNAS; x++)
    {
        printf("|%d", x + 1);
    }
    printf("|\n");
    for (y = 0; y < FILAS; y++)
    {
        printf("|%d", y + 1);
        for (x = 0; x < COLUMNAS; x++)
        {
            printf("|%c", tablero[y][x]);
        }
        printf("|\n");
    }
}

// Indica si el tablero está vacío en las coordenadas indicadas
int coordenadasVacias(int y, int x, char tablero[FILAS][COLUMNAS])
{
    return tablero[y][x] == ESPACIO_VACIO;
}

// Coloca la X o O en las coordenadas especificadas
void colocarPieza(int y, int x, char pieza, char tablero[FILAS][COLUMNAS])
{
    if (y < 0 || y >= FILAS)
    {
        printf("Fila incorrecta");
        return;
    }

    if (x < 0 || x >= COLUMNAS)
    {
        printf("Columna incorrecta");
        return;
    }
    if (pieza != JUGADOR_O && pieza != JUGADOR_X)
    {
        printf("La pieza debe ser %c o %c", JUGADOR_O, JUGADOR_X);
        return;
    }
    if (!coordenadasVacias(y, x, tablero))
    {
        printf("Coordenadas ya ocupadas");
        return;
    }
    tablero[y][x] = pieza;
}
/*
Funciones de conteo. Simplemente cuentan cuántas piezas del mismo jugador están
alineadas
*/

int contarHaciaArriba(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int yInicio = (y - CONTEO_PARA_GANAR >= 0) ? y - CONTEO_PARA_GANAR + 1 : 0;
    int contador = 0;
    for (; yInicio <= y; yInicio++)
    {
        if (tablero[yInicio][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int contarHaciaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int contador = 0;
    for (; x <= xFin; x++)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int contarHaciaArribaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int yInicio = (y - CONTEO_PARA_GANAR >= 0) ? y - CONTEO_PARA_GANAR + 1 : 0;
    int contador = 0;
    while (x <= xFin && yInicio <= y)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y--;
    }
    return contador;
}

int contarHaciaAbajoDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int yFin = (y + CONTEO_PARA_GANAR < FILAS) ? y + CONTEO_PARA_GANAR - 1 : FILAS - 1;
    int contador = 0;
    while (x <= xFin && y <= yFin)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y++;
    }
    return contador;
}

// Indica si el jugador gana
int comprobarSiGana(char jugador, char tablero[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            if (
                contarHaciaArriba(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaArribaDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaAbajoDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR)
            {
                return 1;
            }
        }
    }
    // Terminamos de recorrer y no conectó
    return 0;
}

// Devuelve el jugador contrario al que se le pasa. Es decir, le das un O y te devuelve el X
char oponenteDe(char jugador)
{
    if (jugador == JUGADOR_O)
    {
        return JUGADOR_X;
    }
    else
    {
        return JUGADOR_O;
    }
}

// Imprime algo que el CPU "dice"
void hablar(char *mensaje, char jugador)
{
    printf("\nCPU (%c) dice: %s\n\n", jugador, mensaje);
}

// Debería llamarse después de verificar si alguien gana
// Indica si hay un empate
int empate(char tableroOriginal[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            // Si hay al menos un espacio vacío se dice que no hay empate
            if (tableroOriginal[y][x] == ESPACIO_VACIO)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Devuelve un número aleatorio en un rango, incluyendo los límites
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Coloca dos coordenadas aleatorias y válidas en xDestino y yDestino
void obtenerCoordenadasAleatorias(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    int x, y;
    do
    {
        x = aleatorio_en_rango(0, COLUMNAS - 1);
        y = aleatorio_en_rango(0, FILAS - 1);
    } while (!coordenadasVacias(y, x, tableroOriginal));
    *yDestino = y;
    *xDestino = x;
}

// Coloca en yDestino y xDestino las coordenadas para que jugador gane en tableroOriginal.
// Si no puede ganar, colocará ambas coordenadas en -1
void coordenadasParaGanar(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    char copiaTablero[FILAS][COLUMNAS];
    int y, x;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            clonarMatriz(tableroOriginal, copiaTablero);
            if (coordenadasVacias(y, x, copiaTablero))
            {
                colocarPieza(y, x, jugador, copiaTablero);
                if (comprobarSiGana(jugador, copiaTablero))
                {
                    *yDestino = y;
                    *xDestino = x;
                    return;
                }
            }
        }
    }
    *yDestino = *xDestino = -1;
}

/*
Esta función cuenta y te dice el mayor puntaje, pero no te dice en cuál X ni cuál Y. Está pensada
para ser llamada desde otra función que lleva cuenta de X e Y
*/
int contarSinSaberCoordenadas(char jugador, char copiaTablero[FILAS][COLUMNAS])
{
    int conteoMayor = 0;
    int x, y;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            // Colocamos y contamos el puntaje
            int conteoTemporal;
            conteoTemporal = contarHaciaArriba(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }
            conteoTemporal = contarHaciaArribaDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }

            conteoTemporal = contarHaciaDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }

            conteoTemporal = contarHaciaAbajoDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }
        }
    }
    return conteoMayor;
}

/*
Esta función complementa a contarSinSaberCoordenadas. Te dice en qué X e Y el jugador [jugador]
obtendrá el mayor puntaje si pone ahí su pieza
*/
void coordenadasParaMayorPuntaje(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino, int *conteo)
{

    char copiaTablero[FILAS][COLUMNAS];
    int y, x;
    int conteoMayor = 0,
        xConteoMayor = -1,
        yConteoMayor = -1;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            clonarMatriz(tableroOriginal, copiaTablero);
            if (!coordenadasVacias(y, x, copiaTablero))
            {
                continue;
            }
            // Colocamos y contamos el puntaje
            colocarPieza(y, x, jugador, copiaTablero);
            int conteoTemporal = contarSinSaberCoordenadas(jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
                yConteoMayor = y;
                xConteoMayor = x;
            }
        }
    }
    *conteo = conteoMayor;
    *xDestino = xConteoMayor;
    *yDestino = yConteoMayor;
}

// Hace que el CPU elija unas coordenadas para ganar
void elegirCoordenadasCpu(char jugador, char tablero[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    hablar("Estoy pensando...", jugador);
    /*
    El orden en el que el CPU infiere las coordenadas que toma es:
    1. Ganar si se puede
    2. Hacer perder al oponente si está a punto de ganar
    3. Tomar el mejor movimiento del oponente (en donde obtiene el mayor puntaje)
    4. Tomar mi mejor movimiento (en donde obtengo mayor puntaje)
    5. Elegir la de la esquina superior izquierda (0,0)
    6. Coordenadas aleatorias
    */
    int y, x, conteoJugador, conteoOponente;
    char oponente = oponenteDe(jugador);
    // 1
    coordenadasParaGanar(jugador, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        hablar("Ganar", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 2
    coordenadasParaGanar(oponente, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        hablar("Tomar victoria de oponente", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 3
    coordenadasParaMayorPuntaje(jugador, tablero, &y, &x, &conteoJugador);
    coordenadasParaMayorPuntaje(oponente, tablero, &y, &x, &conteoOponente);
    if (conteoOponente > conteoJugador)
    {
        hablar("Tomar puntaje mayor del oponente", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    else
    {
        hablar("Tomar mi mayor puntaje", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 4
    if (coordenadasVacias(0, 0, tablero))
    {
        hablar("Tomar columna superior izquierda", jugador);
        *yDestino = 0;
        *xDestino = 0;
        return;
    }
    // 5
    hablar("Coordenadas aleatorias", jugador);
    obtenerCoordenadasAleatorias(jugador, tablero, yDestino, xDestino);
}

// Devuelve un jugador aleatorio
char jugadorAleatorio()
{
    if (aleatorio_en_rango(0, 1) == 0)
    {
        return JUGADOR_O;
    }
    else
    {
        return JUGADOR_X;
    }
}

// Loop principal del juego
void iniciarJuego(int modo)
{
    if (modo != JUGADOR_JUGADOR && modo != JUGADOR_CPU && modo != CPU_CPU)
    {
        printf("Modo de juego no permitido");
        return;
    }

    // Para que salgan cosas aleatorias
    srand(getpid());
    // Iniciar tablero de juego
    char tablero[FILAS][COLUMNAS];
    // Y limpiarlo
    limpiarTablero(tablero);
    // Elegir jugador que inicia al azar
    char jugadorActual = jugadorAleatorio();
    printf("El jugador que inicia es: %c\n", jugadorActual);
    int x, y;
    // Y allá vamos
    while (1)
    {
        imprimirTablero(tablero);
        if (modo == JUGADOR_JUGADOR || (modo == JUGADOR_CPU && jugadorActual == JUGADOR_X))
        {
            printf("Jugador %c. Ingresa coordenadas (x,y) para colocar la pieza separadas por una coma. Por ejemplo: 5,5\n", jugadorActual);
            scanf("%d,%d", &x, &y);
            // Al usuario se le solicitan números comenzando a contar en 1, pero en los arreglos comenzamos desde el 0
            // así que necesitamos restar uno en ambas variables
            x--;
            y--;
        }
        else if (modo == CPU_CPU || (modo == JUGADOR_CPU && jugadorActual == JUGADOR_CPU_O))
        {
            // Si es modo CPU contra CPU o es el turno del CPU, dejamos que las coordenadas las elija
            // el programa
            elegirCoordenadasCpu(jugadorActual, tablero, &y, &x);
        }
        // Sin importar cuál modo haya sido, colocamos la pieza según las coordenadas elegidas
        colocarPieza(y, x, jugadorActual, tablero);
        // Puede que después de colocar la pieza el jugador gane o haya un empate, así que comprobamos
        if (comprobarSiGana(jugadorActual, tablero))
        {
            imprimirTablero(tablero);
            printf("El jugador %c gana\n", jugadorActual);
            return;
        }
        else if (empate(tablero))
        {
            imprimirTablero(tablero);
            printf("Empate");
            return;
        }
        // Si no, es turno del otro jugador
        jugadorActual = oponenteDe(jugadorActual);
    }
}

int main(int argc, char const *argv[])
{
    printf("================================================\n");
    printf("|   Tres en línea en ANSI C - By Parzibyte     |\n");
    printf("|           https://parzibyte.me/blog          |\n");
    printf("| (también conocido como tic tac toe o gatitos)|\n");
    printf("================================================\n");
    sleep(1);
    int modo;
    printf("1. Humano contra humano\n2. Humano contra CPU (El CPU juega como %c)\n3. CPU contra CPU\n4. Salir\nElige: ", JUGADOR_CPU_O);
    scanf("%d", &modo);
    if (modo == SALIR)
    {
        return 0;
    }
    iniciarJuego(modo);
    return 0;
}