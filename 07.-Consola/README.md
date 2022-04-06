# Ncurses

## Instalar GTK4 en una distribución basada en Debian

_Para instalar el paquete binario_

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

![GTK-PreWork](/00.-Sources/preworkNcurses.gif)

## Usando Ncurses en Ubuntu 

_Una vez instalado necesitas probar que los paquetes funcionan, copia y pega en un archivo llamado Hola-mundo.c el código de un tradicional "Hola mundo" en GTK4_

```c
#include <stdio.h>
#include <ncurses.h>

int main()
{
  printf("Hello");

  return 0;
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
![GTK-PreWork](/00.-Sources/Ncurses.gif)
