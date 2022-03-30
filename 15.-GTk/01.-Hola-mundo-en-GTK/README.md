_Como instalar GTK4 para desarrollar desde Ubuntu_

_Para instalar el paquete binario_

```
sudo apt install libgtk-4-1
```
_Para instalar el paquete de desarrollo_

```
sudo apt install libgtk-4-dev
```

_Para instalar ejemplos(opcional)_

```
sudo apt install gtk-4-examples
```

![GTK-PreWork](/00.-Sources/gtkprework.gif)

_Una vez instalado necesitas probar que los paquetes funcionan, copia y pega el código del Hola mundo en GTK4 en un archivo llamado Hola-mundo.c, después compila usando el siguiente comando_

```
gcc $( pkg-config --cflags gtk4 ) -o Hola-mundo Hola-mundo.c $( pkg-config --libs gtk4 )
```

_gcc es el compilador que va a utilizar, etc._

_Esto nos crea un ejecutable llamado Hola-mundo, ejecutalo de la siguiente manera_

```
./Hola-mundo
```
![GTK-PreWork](/00.-Sources/ejecutable.gif)