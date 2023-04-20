# Ncurses

## Instalar Ncurses en una distribución basada en Debian

_Instalación de la librería_

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

![Ncurses-PreWork](/00.-Sources/Gifs/preworkNcurses.gif)

## Usando Ncurses en Ubuntu 

_Una vez instalado necesitas probar que la librería  funciona, copia y pega en un archivo llamado Ncurses.c para crear el demo de la librería "Ncurses"_

```c
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
//Función principal
int main(void)
{
    initscr();

    addstr("-----------------\n| IPN-CS |\n| Ncurses Demo  |\n-----------------\n\n");
    refresh();

    addstr("\npresiona cualquier tecla para salir...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}
```

la función `initscr()` inicializa la pantalla, la función `addstr()` agrega una cadena de caracteres a la pantalla, la función `refresh()` actualiza la pantalla, la función `getch()` espera a que el usuario presione una tecla, la función `endwin()` termina la pantalla y la función `EXIT_SUCCESS` termina el programa

_Compila y ejecura; la librería Ncurses no esta definida en el estandar del compilador gcc, así que debes linkearla con -lncurses._

```
gcc Ncurses.c -o Ncurses -lncurses && ./Ncurses
```
![GTK-PreWork](/00.-Sources/Gifs/demoNcurses.gif)

## Referencias 📚

_Writing Programs with NCURSES. (s. f.). https://invisible-island.net/ncurses/ncurses-intro.html_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
