# Make

_Make es una herramienta que sirve de apoyo a la hora de compilar programas de ordenador_

_Y antes de que algún inteligente diga pues te creas un shell script, si tuviese que compilar una solución donde la extiendo constantemente con más y menos archivos y son archivos no de 200 lineas sino de 5000, 50000 o más lineas de código, ¿estarías dispuesto a estar creando shell scripts constantemente? Además cuándo hace una compilación va a distinguir exactamente que se ha modificado y que no se ha modificado, para hacer una compilación menos exhaustiva_

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

_Objetivo nos va a decir que queremos hacer, por ejemplo queremos obtener un programa, queremos un archivo .o, eliminar programas, etc._

_Dependencias son esos archivos para lograr el Objetivo._

_Instrucciones, son las instrucciones de código que se tiene que ejecutar, por ejemplo, compila esto con gcc, enlaza aquello con ld, crear tal carpeta con mkdir, etc._

## Ejemplo 1, Hola Make

```Makefile
main: hellomake.o hellofunc.o 
	gcc -o main hellomake.o hellofunc.o 

hellomake.o: hellomake.c hellomake.h
	gcc -c hellomake.c

hellofunc.o: hellofunc.c hellomake.h
	gcc -c hellofunc.c

clean:
	rm -f main *.o
```
