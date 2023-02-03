/* Plantilla de programa en C para resolver el problema laberinto
   usando backtracking */
#include<stdio.h>

// Tamaño del laberinto
#define N 6

/* Función para imprimir la solución sol[N][N] */
void imprimirSolucion(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* Esta función resuelve el problema del laberinto usando backtracking.
   Devuelve falso si no hay un camino posible a la salida, de otra
   forma devuelve true con el camino solución marcado con 1s en la
   matriz sol*/
bool resolverLaberinto(int laberinto[N][N], int x, int y, int sol[N][N])
{
    // Si (x,y es la salida) return true
    
    // Revisar si la posición en el laberinto[x][y] es valida
        
		// marcar x,y como parte del camino solución
        
        // Mover en dirección derecha ->  a través de una recursión con x+1
        // Si no lleva a una solución mover hacia abajo a través de recursión con y+1
        // Si no lleva a una solución mover a la izquierda <- a través de recursión con x-1
        // Si no lleva a una solución mover hacia arriba a través de recursión con y-1
        
        // Si nungún movimiento lleva a una solución entonces hacer
		// Backtracking: desmarcar x,y como parte de la solución
        
    return false;
}

// Programa principal
int main()
{
    int laberinto[N][N]  =  { {1, 0, 1, 1, 0, 1},
        					{1, 1, 0, 1, 1, 1},
        					{0, 1, 0, 1, 0, 0},
	        				{1, 1, 0, 1, 1, 1},
    	    				{0, 1, 1, 1, 0, 1},
        					{1, 1, 0, 1, 0, 1}
    };

    int sol[N][N] = { {0, 0, 0, 0, 0, 0},
        			{0, 0, 0, 0, 0, 0},
        			{0, 0, 0, 0, 0, 0},
        			{0, 0, 0, 0, 0, 0},
        			{0, 0, 0, 0, 0, 0},
        			{0, 0, 0, 0, 0, 0}
    };
    
	if(resolverLaberinto(laberinto, 0, 0, sol) == false)
    {
        printf("No existe solucion");
        return 0;
    }

    imprimirSolucion(sol);
    return 0;
}

