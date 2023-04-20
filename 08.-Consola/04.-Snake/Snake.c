#include <ncurses.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
#include <time.h>

// Tamaño de la ventana
#define MAXWIDTH 79
#define MAXHEIGHT 23

// Checa si la tecla fue pulsada o no
int kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&read_fd);
  FD_SET(0, &read_fd);

  if (select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;

  if (FD_ISSET(0, &read_fd))
    return 1;

  return 0;
}

// Checa si la serpiente choca con las paredes
int colliding(int *snakeArray, int snakeLength)
{
  int x = *snakeArray;
  int y = *(snakeArray + 1);

  if (x < 0 || x > MAXWIDTH)
  {
    return 1;
  }
  else if (y < 0 || y > MAXHEIGHT)
  {
    return 1;
  }

  for (size_t i = 2; i < snakeLength * 2 + 2; i += 2)
  {
    if (x == *(snakeArray + i) && y == *(snakeArray + i + 1))
    {
      return 1;
    }
  }
  return 0;
}

// Mueve la serpiente una posición en la dirección indicada y controla la velocidad del juego usando la función usleep
void moveSnake(int *snakeArray, int dirX, int dirY, int speed, int snakeLength)
{
  int oldX = 0;
  int oldY = 0;
  int curX = *snakeArray;
  int curY = *(snakeArray + 1);
  int newX = curX + dirX;
  int newY = curY + dirY;

  *(snakeArray) = newX;
  *(snakeArray + 1) = newY;
  mvprintw(newY, newX, "S");

  for (size_t i = 2; i < snakeLength * 2; i += 2)
  {
    oldX = curX;
    oldY = curY;
    curX = *(snakeArray + i);
    curY = *(snakeArray + i + 1);
    newX = oldX;
    newY = oldY;
    *(snakeArray + i) = newX;
    *(snakeArray + i + 1) = newY;

    mvprintw(newY, newX, "S");
  }

  if (dirY != 0)
  {
    usleep(500000 / speed);
  }

  usleep(1000000 / speed);
}

// Genera ubicación aleatoria de la manzana si se come la manzana, si no, imprime la manzana en ubicación anterior
void letThereBeApple(int *appleX, int *appleY, int *appleEaten)
{
  if (*appleEaten)
  {
    srand(time(0));
    *appleX = (rand() % MAXWIDTH) + 1;
    *appleY = (rand() % MAXHEIGHT) + 1;
    *appleEaten = 0;
  }

  mvprintw(*appleY, *appleX, "A");
}

// Si la serpiente encuentra la manzana, aumenta un punto, también establece appleEaten en verdadero e imprime snakeLength y la información de depuración
void eatApple(int *snakeArray, int appleX, int appleY,
              int *appleEaten, int *snakeLength)
{
  int x = *snakeArray;
  int y = *(snakeArray + 1);
  if (x == appleX && y == appleY)
  {
    *appleEaten = 1;
    *snakeLength += 1;
    int snakeLen = *snakeLength;
    int lastX = *(snakeArray + snakeLen * 2 - 2);
    int lastY = *(snakeArray + snakeLen * 2 - 2 + 1);
    *(snakeArray + snakeLen * 2) = lastX;
    *(snakeArray + snakeLen * 2 + 1) = lastY;
  }

  mvprintw(0, 0, " Largo de la serpiente: %d", *snakeLength);
}

int main()
{
  int snakeArray[100][2];
  for (size_t i = 0; i < 100; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      snakeArray[i][j] = 0;
    }
  }
  snakeArray[0][0] = 3;
  snakeArray[0][1] = 3;
  int keyPressed = 0; // Que tecla se presionó
  int dirX = 1;
  int dirY = 0;
  int speed = 20;       // Controla la velocidad de la serpiente
  int appleX = 0;       // Ubicación de la manzana en X
  int appleY = 0;       // Ubicación de la manzana en Y
  int appleEaten = 1;   // Si la manzana fue comida
  int snakeLength = 20; // Longitud de la serpiente

  // Inicia el modo ncurses
  initscr();
  curs_set(false);
  noecho();

  // Bucle principal
  while (!colliding(&snakeArray[0][0], snakeLength))
  {
    erase();

    letThereBeApple(&appleX, &appleY, &appleEaten);
    moveSnake(&snakeArray[0][0], dirX, dirY, speed, snakeLength);
    eatApple(&snakeArray[0][0], appleX, appleY, &appleEaten, &snakeLength);

    refresh();

    // Cambio de dirección
    if (kbhit())
    {
      keyPressed = getch();

      if (keyPressed == 'w' && !(dirY == 1 && dirX == 0))
      {
        dirY = -1;
        dirX = 0;
      }
      if (keyPressed == 's' && !(dirY == -1 && dirX == 0))
      {
        dirY = 1;
        dirX = 0;
      }
      if (keyPressed == 'a' && !(dirY == 0 && dirX == 1))
      {
        dirY = 0;
        dirX = -1;
      }
      if (keyPressed == 'd' && !(dirY == 0 && dirX == -1))
      {
        dirY = 0;
        dirX = 1;
      }
    }
  }
  erase();
  mvprintw(MAXHEIGHT / 2, MAXWIDTH / 4, "¡Juego terminado! - Tu puntuación fue: %d", snakeLength);
  refresh();
  getch();  // Espera a que el usuario presione una tecla
  endwin(); // Termina el modo curses

  return 0;
}
