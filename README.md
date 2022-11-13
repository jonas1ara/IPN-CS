# Ipn.c

![](/00.-Sources/Ipn.svg)

[![Generic badge](https://img.shields.io/badge/Made%20with-C-rgb(1,143,204).svg)](https://shields.io/)

_Este es un repositorio del curso fundamentos de programación, el curso de algoritmos y estructuras de datos y del curso análisis y diseño de algoritmos de la  **Unidad Profesional Interdisciplinaria de Ingeniería campus Tlaxcala del IPN**, esta dirigido a estudiantes y profesionales que esten interesados en el desarrollo de sistemas, sistemas embebidos y en aprender algoritmos y estructuras de datos, **COMPLETAMENTE EN ESPAÑOL** para la mejor compresión y el gusto de los hispanohablantes_

## Requisitos 📋

_Herramientas que necesita para usar este repositorio y cómo instalarlo_

![alt text](/00.-Sources/vs.png)

```
Un compilador para C/C++ y el editor de texto de tu preferencia
```

_Si estas en Linux o MacOS ya tienes instalado un compilador para el lenguaje C, pero si estas en Windows te recomiendo seguir este [Tutorial](https://www.youtube.com/watch?v=v3ENcQpoA5A) de @FaztTech para descargar MinGW y usarlo con VS Code_

_ADVERTENCIA: Este repositorio no esta pensado en usarse con Windows por temas especificos que son el uso de Make, las aplicaciones de Consola usan Ncurses, el manejo de hilos es para sistemas posix por lo cuál no funciona en windows, las librerías de libcurl solo funcionan en Unix, el script para instalar las herramientas es un script de bash por lo tanto sólo funciona para un sistema Unix y por último la librería GTK es para crear aplicaciones gráficas del escritorio GNOME y es una sección para ayudar al escritorio de Linux🤷‍♂️ , si estas en windows y si te interesan esos temas te recomiendo usar WSL y WSLg_

## Como usar este repositorio 🔧

_Este repositorio esta enumerado por la jerarquía de temas que debes seguir para aprender C y un poco de su ecosistema (Linux, Gnome, Makefiles, Networking y Sistemas embebidos), todo el código esta comentado en **ESPAÑOL** así que por favor **LEE** antes de copiar y pegar, asegurate de saber que estás haciendo, si solo copias y pegas **el daño te lo haces a ti** y por último se escribieron post en su blog sobre temas más complejos de comprender, espero que te ayude para aprender y/o repasar algún tema_

## Índice del curso

**[00.- Sources](https://github.com/Jonas-Lara/IPN-CS/tree/master/00.-Sources)**
  - En esta carpeta encontraras las fuentes de las imagenes y gifs que se usan en el repositorio 

**[01.- Básicos del lenguaje C](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C)**
  -  [Hola mundo en C](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01-Hola-Mundo.c)
  - [Directivas del procesador](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/02-Directivas.c)
  - [Suma de variables](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03-Suma.c)
  - [Operaciones aritméticas](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04-Aritm%C3%A9tica.c)
  - [Variables y tipos de datos](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05-Variables.c)
  - [Conversión de datos en C](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/06-Convertir.c)
  - [Condicionales](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/07-Condicionales.c)
  - [Uso de casos en C](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/08-Casos.c)
  - [Break y Continue](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/09-Band.c)
  - [Vectores](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/10-Vector.c) 
  - [Matrices](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/11-Matriz.c)
  - [Bucles](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/12.-Bucles)
  - [Funciones](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/13.-Funciones)
  - [Estructuras](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/14.-Estructuras)
  - [Punteros](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/15.-Punteros)
  - [Cadenas](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/16.-Cadenas)


**[02.- Matemáticas básicas](https://github.com/Jonas-Lara/IPN-CS/tree/master/02.-Matem%C3%A1ticas-b%C3%A1sicas)**
  - [Fundamentos de la libería math.h](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/00-Fundamentos.c)
  - [Binario a decimal](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/01-Binario-a-decimal.c)
  - [Números primos](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/02-N%C3%BAmeros-Primos.c)
  - [Números narcicistas](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/03-N%C3%BAmero-narcicista.c)
  - [Número palindrome](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/03-N%C3%BAmero-narcicista.c)
  - [Triángulo de Pascal](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/05-Triangulo-de-Pascal.c)
  - [Grados a radianes](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/06-Convertir-grados-a-radianes.c)
  - [Radio y circunferencia](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/07-Radio-y-circunferencia.c)
  - [Distancia entre dos puntos](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/08-Distancia-entre-dos-puntos.c)
  - [Conjetura de Collatz](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/09-Conjetura-de-Collatz.c)
  - [Raíz cuadrada Newton](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/10-Ra%C3%ADz-cuadrada-Newton.c)
  - [Valor absoluto](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/11-Valor-absoluto.c)
  - [Suma de matrices](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/12-Suma-de-matrices.c)
  - [Resta de matrices](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/13-Resta-de-matrices.c)
  - [Multiplicación de matrices](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/14-Multiplicaci%C3%B3n-de-matrices.c)
  - [Matriz transpuesta](https://github.com/Jonas-Lara/IPN-CS/blob/master/02.-Matem%C3%A1ticas-b%C3%A1sicas/15-Matriz-transpuesta.c)


**[03.-Memoría dinámica](https://github.com/Jonas-Lara/IPN-CS/tree/master/03.-Memoria-din%C3%A1mica)**
  - If, elif y else 
  - Bucles
  
**[04.-Hilos en lenguaje C](https://github.com/Jonas-Lara/IPN-CS/tree/master/04.-Hilos-del-lenguaje-C)**
  - Pipelines

**[05.-How To (¿Cómo?)](https://github.com/Jonas-Lara/IPN-CS/tree/master/05.-HowTo)**
  - Enums
  - Structs
  - Colecciones
  - Listas
  - Tuplas
  - Record
  - Sequences
  - Maps
  - Generics

**7.- Programación con objetos** 
  - Objetos
  - Clases
  - Interfaces

**8.- Módulos**

**9.- Programación asíncrona**


## Construido con 🛠️

* [VS Code](https://code.visualstudio.com/) - Visual Studio Code.
* [Language C](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/ref=sr_1_1?dchild=1&keywords=language+c+dennis&qid=1618383287&sr=8-1) - El lenguaje C de Dennis Ritchie.
* [UPIIT](https://www.upiit.ipn.mx/) - Unidad Profesional Interdisciplinaria de Ingeniería campus Tlaxcala.

## Expresiones de gratitud

Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado.
