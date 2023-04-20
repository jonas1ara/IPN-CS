// Este es el juego de Tic-Tac-Toe diseñado para principiantes.
// Este juego no contiene punteros o un uso avanzado de C
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Para la función toupper()
#include <time.h>

char board[3][3];
const char JUGADOR = 'X';
const char PC = 'O';

// Prototipado de funciones
void resetBoard();
void printBoard();
int espacioVacio();
void jugadorMove();
void pcMove();
char checkarGanador();
void printGanador(char);

int main()
{
   char ganador = ' ';
   char respuesta = ' ';

   do
   {
      ganador = ' ';
      respuesta = ' ';
      resetBoard();

      while (ganador == ' ' && espacioVacio() != 0)
      {
         printBoard();

         jugadorMove();
         ganador = checkarGanador();
         if (ganador != ' ' || espacioVacio() == 0)
         {
            break;
         }

         pcMove();
         ganador = checkarGanador();
         if (ganador != ' ' || espacioVacio() == 0)
         {
            break;
         }
      }

      printBoard();
      printGanador(ganador);

      printf("\n¿Te gustaría jugar otra vez? (S/n): ");
      scanf("%c", &respuesta);
      respuesta = toupper(respuesta);
   } while (respuesta == 'Y');

   printf("¡Gracias por jugar!\n");

   return 0;
}

void resetBoard()
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int espacioVacio()
{
   int freeSpaces = 9;

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void jugadorMove()
{
   int x;
   int y;

   do
   {
      printf("Ingresa la fia #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Ingresa la columna #(1-3): ");
      scanf("%d", &y);
      y--;

      if (board[x][y] != ' ')
      {
         printf("Movimiento invalido\n");
      }
      else
      {
         board[x][y] = JUGADOR;
         break;
      }
   } while (board[x][y] != ' ');
}
void pcMove()
{
   // Crea una semilla basada en la hora actual
   srand(time(0));
   int x;
   int y;

   if (espacioVacio() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = PC;
   }
   else
   {
      printGanador(' ');
   }
}
char checkarGanador()
{
   // Checar filas
   for (int i = 0; i < 3; i++)
   {
      if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   // Checar columnas
   for (int i = 0; i < 3; i++)
   {
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   // Checar diagonales
   if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
void printGanador(char ganador)
{
   if (ganador == JUGADOR)
   {
      printf("¡Ganaste!");
   }
   else if (ganador == PC)
   {
      printf("¡Perdiste :( !");
   }
   else
   {
      printf("¡Empate !");
   }
}
