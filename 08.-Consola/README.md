# Ncurses

## Instalar Ncurses en una distribución basada en Debian

_Para instalar la librería_

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

_Compila usando el siguiente comando_
```
gcc Ncurses.c -o Ncurses -lncurses
```

_La librería Ncurses no esta definida en el estandar del compilador gcc, así que debes linkearla con -lncurses._

_Todo esto nos crea un ejecutable llamado Ncurses, ejecutalo de la siguiente manera_

```
./Ncurses
```
![GTK-PreWork](/00.-Sources/Gifs/demoNcurses.gif)

## Referencias 📚

_Writing Programs with NCURSES. (s. f.). https://invisible-island.net/ncurses/ncurses-intro.html_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
