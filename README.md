# IPN-CS

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

_ADVERTENCIA: Este repositorio no esta pensado en usarse con Windows por temas especificos que son el uso de Make, las aplicaciones de Consola usan Ncurses, el manejo de hilos es para sistemas posix por lo cuál no funciona en windows, las librerías de libcurl solo funcionan en Unix, el script para instalar las herramientas es un script de bash por lo tanto sólo funciona para un sistema Unix, por último la librería GTK es para crear aplicaciones gráficas del escritorio GNOME y es una sección para ayudar al escritorio de Linux🤷‍♂️ , si estas en windows y si te interesan esos temas te recomiendo usar WSL y WSLg_

## Como usar este repositorio 🔧

_Este repositorio esta enumerado por la jerarquía de temas que debes seguir para aprender C y un poco de su ecosistema (Makefiles, Redes y Unix), debido al poco alcance del repositorio y al surgiemiento de tecnologías como chatGPT me limito a solo comentar el codigo en **ESPAÑOL** y así lograr que sea autodocumentado, asegurate de saber que estás haciendo, si solo copias y pegas **el daño te lo haces a ti** y por último se escribieron post en mi blog sobre algunos temas más complejos de comprender, espero que te ayude para aprender y/o repasar algún tema:_

_Blog post:_
- _[Recursion](https://jonas1ara.github.io/posts/algorithms-and-complexity/) - [Español](https://github.com/jonas1ara/IPN-CS/tree/master/09.-Recursi%C3%B3n)_
- _[Algorithms and complexity](https://jonas1ara.github.io/posts/recursion/) - [Español](https://github.com/jonas1ara/IPN-CS/tree/master/10.-Algoritmos)_

## Indice 📖

```
|- Repositorio
    |- 01.- Básicos del lenguaje C
        |- Hola mundo en C
        |- Directivas del preprocesador
        |- Suma de variables
        |- Operaciones aritméticas
        |- Variables y tipos de datos
        |- Conversión de datos en C
        |- Condicionales
        |- Uso de casos en C
        |- Break y Continue
        |- Vectores
        |- Matrices
        |- Bucles
        |- Funciones
        |- Punteros
        |- Cadenas
    |- 02.- Matemáticas básicas
        |- Fundamentos de la librería math.h
        |- Binario a decimal
        |- Números primos
        |- Números narcicistas
        |- Número palindrome
        |- Triángulo de Pascal
        |- Grados a radianes
        |- Distancia entre dos puntos
        |- Conjetura de Collatz
        |- Raíz cuadrada por el método de Newton
        |- Valor absoluto
        |- Suma de matrices
        |- Resta de matrices
        |- Multiplicación de matrices
        |- Matriz transpuesta
    |- 03.- Memoría dinámica
        |- Memoría estática
        |- Memoría pseudo estática
        |- Memoría dinámica
        |- Malloc y Realloc
        |- Calloc y Free
        |- Cadenas dinámicas
        |- Matrices dinámicas
        |- Funciones dinámicas
        |- Estructuras dinámicas
    |- 04.- Hilos en C 
        |- Crear y unir hilos
        |- Pasar argumentos
        |- Problemas de seguridad y velocidad
    |- 05.- Hacks
        |- Medir tiempo de ejecución
        |- Generar números pseudoaleatorios
        |- Función para intercambiar valores
        |- Invertir números
        |- Invertir vector
        |- Invertir cadena
        |- Obtener el largo de una cadena
        |- Imprimir pirámide
        |- Imprimir círculo
    |- 06.- Algoritmos Dr. Esaú 1
        |- Sheldon.gif
    |- 07.- Make
        |- Hola mundo usando Make
        |- Calculadora usando Make
    |- 08.- Aplicaciones de consola
        |- Tic tac toe
        |- Torres de Hanoi
        |- Dona
        |- Snake
        |- Matrix
        |- Ping pong
    |- 09.- Recursión 
        |- Factorial
        |- Fibonacci
        |- Torres de Hanoi
    |- 10.- Algoritmos 
        |- Fuerza bruta
        |- Voraces
        |- Divide y conquista
        |- Programación dinámica
        |- Backtracking
        |- Ordenamiento
        |- Búsqueda
    |- 11.- Estructuras de datos 
        |- Pilas
            |- Pila estática
            |- Pila dinámica
            |- URL
        |- Colas
            |- Cola estática
            |- Cola dinámica
            |- DHL
        |- Listas 
            |- Lista enlazada simple
            |- Lista enlazada doble
            |- Lista enlazada circular
            |- Agenda
            |- Invertir lista enlazada
            |- Intercambiar elementos
            |- Ordenar lista enlazada (Merge sort)
            |- Ordenar lista enlazada (Quick sort)
        |- Tablas de Hash
            |- Tabla de hash
            |- Búsqueda hash
        |- Árboles
        |- Heaps
        |- Grafos
    |- 12.- Algoritmos Dr. Esaú 2
        |- Tiempo de ordenamiento
    |- 13.- Redes
        |- Cliente web
        |- Servidor web
        |- Dirección del cliente
        |- Issues
        |- Servidor multihilos
        |- Hilos escuchando socketts
        |- Libcurl
        |- Barra de progreso
        |- Red final
    |- 14.- Métodos numéricos
        |- Método de la bisección
    |- 15.- Llamadas al sistena 
        |- Librería unistd.h
        |- Shell
    |- 16.- Algoritmos de que deberías conocer 
        |- Básicos
            |- Algoritmo de Fibonacci
            |- Algoritmo de Euclides
            |- Algoritmo de intercambio de valores
        |- Arreglos
            |- Algoritmo de Kadane
            |- Algoritmo de Floyd
            |- Algoritmo de detección
            |- Algoritmo KMP
            |- Algoritmo Boyer-More
            |- Algoritmo para invertir arreglo
        |- Ordenamiento
            |- Ordenamiento burbuja
            |- Ordenamiento por selección
            |- Ordenamiento por insercción
            |- Ordenamiento por mezcla
            |- Ordenamiento rápido
            |- Ordenamiento shell
        |- Búsqueda
            |- Búsqueda binaria
            |- Búsqueda por interpolación
            |- Búsqueda hash
            |- Búsqueda en profundidad
            |- Búsqueda en anchura
        |- Grafos
            |- Algoritmo de Kruskal
            |- Algoritmo de Dijkstra
            |- Algoritmo de Floyd Warshall
            |- Ordenamiento topológico
            |- Encontrar componentes conexos

```


## Construido con 🛠️

* _[WSL](https://learn.microsoft.com/en-us/windows/wsl/install) - Opcional_
* _[Ubuntu](https://ubuntu.com/) - Opcional_
* _[Visual Studio Code](https://code.visualstudio.com/) - Opcional_

## Referencias 📚

_Kernighan, B. & Ritchie, D. (1988). [C Programming Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/ref=sr_1_1?dchild=1&keywords=language+c+dennis&qid=1618383287&sr=8-1) (2nd ed.). Pearson._

_Cormen, T. H., Leiserson, C. E., Rivest, R. L. & Stein, C. (2009). [Introduction to Algorithms](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844) (3rd ed.). MIT Press._

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
