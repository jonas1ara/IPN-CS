# Make

### Make es una herramienta que sirve de apoyo a la hora de compilar programas de ordenador.

_Y antes de que algún inteligente diga pues te creas un shell script, si tuviese que compilar una solución donde la extiendo constantemente con más y menos archivos y son archivos no de 200 lineas sino de 5000, 50000 o más lineas de código, ¿estarías dispuesto a estar creando shell scripts constantemente? Además cuándo Make hace una compilación distingue exactamente que se ha modificado y que no se ha modificado, para hacer una compilación menos exhaustiva_

## Instalación de make

_Para instalarlo en una distribución basada en Debian, tipea:_

```
sudo apt install build-essential 
```

_Después comprueba la instalación escribiendo make en la terminal, si recibes una salida como la siguiente, todo bien_

![](/00.-Sources/Images/Make.png)

## Estructura básica de un Makefile

```Makefile
objetivo: dependencias
    instrucciones

objetivo: dependencias
    instrucciones

objetivo:
    instrucciones
```

_**Objetivo** nos va a decir que queremos hacer, por ejemplo queremos obtener un programa, queremos un archivo .o, eliminar programas, etc._

_**Dependencias** son esos archivos para lograr el ojetivo._

_**Instrucciones** son las instrucciones de código que se tiene que ejecutar, por ejemplo, compila esto con gcc, enlaza aquello con ld, crear tal carpeta con mkdir, etc._

_Objetivo, dependencias e instrucciones en conjunto se les llama **regla**._

## Ejemplo 1, Hola Make

_En la carpeta Ejemplo1-Make, se encuentra los archivos para realizar un tipico Hola mundo_

```Makefile
# Regla principal, que se ejecutará si no ocurre nada
all: main

# Esta regla compila el programa principal
main: hola-make.o func-hola.o 
	gcc -o main hola-make.o func-hola.o 

# Esta regla obtiene en código objeto de hola-make.c, que depende de hola-make.c y hola-make.h
hola-make.o: hola-make.c hola-make.h
	gcc -c hola-make.c

# Esta regla obtiene el código objeto de func-hola.c, que depende func-hola.c y hola-make.h
func-hola.o: func-hola.c hola-make.h
	gcc -c func-hola.c

# Esta regla elimina el ejecutable y el código objeto, es una regla que no tiene dependencias
clean:
	rm -f main *.o
```
_Ahora escribe en tu terminal make y la regla que quieres ejecutar, si no colocas una regla, make ejecutará la primera regla que se encuentre._

```
make
```

![](/00.-Sources/Gifs/Make.gif)

##  Ejemplo 2, Calculadora

_Ahora lo que vamos a realizar no son más que optimizaciones._

_**Variables:** es una forma de tener líneas de códio más flexibles, básicamente una forma de asignarle un nombre a un valor para después utilizar ese nombre para referirnos a cualquier valor._

```Makefile
# Variable OBJS, que contiene todos los archivos .o
OBJS = main.o salida.o calculadora.o 

# Variable para el nombre del programa
BINARY = main

# Variables que utiliza el compilador
CFLAGS = -g -Wall

all: main

# Se añaden las variables en las instrucciones
main: $(OBJS)
	gcc -o $(BINARY) $(OBJS) $(CFLAGS)

main.o: main.c funciones.h
	gcc $(CFLAGS) -c main.c

sailda.o: salida.c funciones.h
	gcc $(CFLAGS) -c salida.c

calculadora.o: calculadora.o funciones.h
	gcc $(CFLAGS) -c calculadora.c

clean:
	rm -f main $(BINARY) $(OBJS)
```

_**Reglas implicitas:** nos evita tener que escribir muchas lineas de código, porque ya sabe como compilar algunos tipos especiales de archivo, por ejemplo como compilar un .c en un .o, enlazar archivos, etc. Soporta la compilación de C/C++, Pascal, Fortran, etc._

```Makefile

OBJS = main.o salida.o calculadora.o 
BINARY = main

# Como regla implicita Make usa gcc con el sinonimo CC, pero le podemos indicar que use el compilador que queramos
CC = clang

CFLAGS = -g -Wall

all: main

main: $(OBJS)
	gcc -o $(BINARY) $(OBJS) $(CFLAGS)

# Simplemente le espcificamos las dependencias
main.o: main.c funciones.h
# Se elimina la instrucción porque el make ya sabe que instrucciones seguir

sailda.o: salida.c funciones.h
# Se elimina la instrucción porque el make ya sabe que instrucciones seguir

calculadora.o: calculadora.o funciones.h
# Se elimina la instrucción porque el make ya sabe que instrucciones seguir

clean:
	rm -f main $(BINARY) $(OBJS)
```

_**Recompilando dependencias:** make hace uso de la hora de la última modificación de un archivo para saber los cambios generados y si es buen momento para compilar algo o no._

![](/00.-Sources/Gifs/LSl.gif)

```Makefile
OBJS = main.o salida.o calculadora.o 
BINARY = main
CC = clang
CFLAGS = -g -Wall

all: main

main: $(OBJS)
	gcc -o $(BINARY) $(OBJS) $(CFLAGS)

main.o: main.c funciones.h

sailda.o: salida.c funciones.h

calculadora.o: calculadora.c funciones.h

clean:
	rm -f main $(BINARY) $(OBJS)
```
_**Patrones y variables automáticas:** los patrones nos permiten usar de manera más flexible las reglas, por ejemplo usar una común a cualquier archivo que  sea .o y las variables automáticas para obtener propiedades particulares sobre nuestras reglas, por ejemplo como se llama la regla, el archivo que se esta compilando, como se llama el objetivo, etc._

```Makefile
OBJS = main.o salida.o calculadora.o 
BINARY = main
CC = clang
CFLAGS = -g -Wall

all: main

main: $(OBJS)
	$(CC) -o $(BINARY) $(OBJS) $(CFLAGS)

# El operador % un operador que se remplaza por uno o más carácteres, es decir en este caso a partir de mi archivo .c genero mi archivo .o
%.o: %.c
    $(CC) $(CFLAGS) -c $? -o$@ 
# Variables auomáticas: $< para obtener el primer archivo .o , $? para obtener la lista completos y $@ para que se remplace por el nombre de la regla, salida.o --> salida
# -c nombre del archivo .c --> -o nombre del destino .o

clean:
	rm -f main $(BINARY) $(OBJS)
```

_**Múltiples archivos:** trabajar con múltiples archivos Makefile._

```Makefile
# \ Salto de linea, cuándo tenemos muchisimos archivos
OBJS = main.o \
salida.o \ 
calculadora.o

# include para incluir múltiples archivos, útil para cuándo tenemos Makefiles para diferentes OS

include src/Makefile windows/Makefile mac/Makefile

BINARY = main
CC = clang
CFLAGS = -g -Wall

all: main

main: $(OBJS)
	$(CC) -o $(BINARY) $(OBJS) $(CFLAGS)

*%.o: %.c
    $(CC) $(CFLAGS) -c $? -o$@

clean:
	rm -f main $(BINARY) $(OBJS)
```

## Expresiones de gratitud

Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado.
