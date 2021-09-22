# Ipn.c

_Este es un repositorio de lenguaje C, hecho por alumnos de Unidad Profesional Interdisciplinaria de Ingeniería Campus Tlaxcala_

## Iniciando 🚀

_Estas instrucciones le permitirán obtener una copia de trabajo del proyecto en su máquina local para fines de desarrollo y pruebas_



## Requisitos 📋

_Herramientas que necesita para usar este reposotorio y cómo instalarlo_

```
GCC (GNU Compiler Collection) pre-instalado en MacOS
```
```
MinGW (Minimalist GNU for Windows)
```
```
Un editor para hombres: VIM
```


## Instalando requisitos 🔧

_[C Compiler Online](https://www.programiz.com/c-programming/online-compiler/)_

_Se usa Windows porque la mayoría de universitarios en México lo usan y la verdad, ha mejorado muchisimo, a continuación mostramos los pasos para configurar tu máquina Windows y estoy tratando de que Microsoft apruebe el uso de MinGW con Winget..._

_Windows_

_Despues de descargar e instalar [MinGW](https://sourceforge.net/projects/mingw/)_



_Selecciona los paquetes que usaras, para este repositorio usaremos mingw32-base y mingw32-gcc-g++_

<img src=/Gifs/Instalation/2.png alt="#"/>

_Si quisieras usar un paquete especifico ve a All Packages y selecciona tus paquetes_

<img src=/Gifs/Instalation/3.png alt="#"/>

_Para habilitar el Debugger en tus programas necesitas Gdb, es el Debugger para C (y C++), Abre All Packages y selecciona mingw32-gdb y aplica los cambios_

<img src=/Gifs/Instalation/4.png alt="#"/>

_Copia la ruta C:\MinGW\bin a las variables de entorno_

```
C:\MinGW\bin
```

<img src=/Gifs/Instalation/6.png alt="#"/>

_Abre la [Terminal de Windows](https://www.microsoft.com/en-us/p/windows-terminal/9n0dx20hk701?activetab=pivot:overviewtab/) y comprueba la instalación con los siguientes comandos:_

```
gdb --version
```
```
gcc --version
```

<img src=/Gifs/Instalation/7.png alt="#"/>

_Si requieres [VIM](https://github.com/Jonas-Lara/Vimrc), basta con abrir una terminal y usar winget_

```
winget install vim
```

## Using the compiler ⚙️

### Windows

_Same commands but with extension .exe_

_Compiler_
```
vim helloworld.c
```
<img src=/Gifs/11.gif alt="#"/>

```
gcc helloworld.c -o helloworld.exe
```
<img src=/Gifs/12.gif alt="#"/>

```
.\helloworld.exe
```
<img src=/Gifs/13.gif alt="#"/>

_Assembler_
```
gcc -S helloworld.c
```
```
vim helloworld.s
```
<img src=/Gifs/14.gif alt="#"/>

_Debug_
```
gdb .\helloworld.exe
```
```
b main
```
```
run
```
```
n
```
```
quit
```
<img src=/Gifs/15.gif alt="#"/>

## Algoritmia 📦

_[Iniciante](https://www.vim.org/download.php)_

_[Intermedio](https://www.vim.org/download.php)_

_[Avanzados](https://www.vim.org/download.php)_

## Graduate en C 📦

_[Ping Pong](https://www.vim.org/download.php)_


## Construido con 🛠️

* [GCC](https://gcc.gnu.org/) - GNU Compiler Collection
* [MinGW](http://mingw-w64.org/doku.php) - Minimalist GNU for Windows
* [Vim](https://www.vim.org/) - El todo poderoso vim
* [VIM](https://github.com/Jonas-Lara/Vimrc) - Mi configuración de VIM
* [Language C](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/ref=sr_1_1?dchild=1&keywords=language+c+dennis&qid=1618383287&sr=8-1) - El lenguaje C de Dennis Ritchie
* [UPIIT](https://www.upiit.ipn.mx/) - Unidad Profesional Interdisciplinaria de Ingeniería Campus Tlaxcala

## Expresiones de gratitud


* Gracias a la maestra Silvia Sánchez Márquez - Matemáticas Discretas en UPIIT.
* Gracias al maestro Essau Escobar - Fundamentos de Programación en UPIIT.
* Gracias por revisar este tutorial 🤓
* Espero haberte ayudado

---
Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) colaborando para que el futuro capital humano de [UPIIT](https://www.upiit.ipn.mx/) detone la economía de este estado.
