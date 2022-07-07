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

##  Ejemplo 1, Calculadora

_Ahora lo que vamos a realizar no son más que optimizaciones_


## Expresiones de gratitud

Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) y estudiante de la licenciatura en matemáticas en la [UnADM](https://www.unadmexico.mx/), para quien sea que este interesado.