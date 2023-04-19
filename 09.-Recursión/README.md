# Recursión 🏃🏽🚶🏽🧑🏽‍🦯

_La **recursión** es una técnica que consiste en resolver un problema haciendo uso de una versión más sencilla del mismo_

![Recursión](/00.-Sources/Images/Recursion.png)

_Representación áurea_

La recursión es un concepto importante en la programación y se refiere a la capacidad de una función o procedimiento de llamarse a sí mismo dentro de su propia definición. Es decir, en lugar de resolver un problema mediante un enfoque lineal, se utiliza la técnica de "dividir y conquistar", en la que un problema se divide en subproblemas más pequeños que se resuelven mediante la misma función recursiva, hasta que se alcanza un caso base que se puede resolver de forma trivial, de manera concreta podemos decir que consta de dos partes fundamentales:

- **Caso base:** Es el caso más sencillo que se puede resolver sin necesidad de hacer uso de la recursión

- **Caso recursivo:** Es el caso en el que se llama a la función recursiva para resolver un problema más sencillo

**Supongamos que tenemos que obtener el inventario de un almacén, que tiene varios estantes y cada estante tiene varias cajas, para resolver este problema podemos hacer uso de la recursión:**

![CByCR](/00.-Sources/Images/Recursion1.png)


## ¿Para entender la recursión es necesario entender la recursión?

_Esto se dice mucho pero personalmente creo que es una broma de mal gusto_

Para comprender la recursión debes entender o por lo menos conocer el concepto de **stack** pero no solo como stack en el campo de las **estructuras de datos**, sino como el Stack en la **asignación de memoria**, las **llamadas al Stack** en el Stack Frame, y por último la recursión y el **Stack Overflow**(No el sitio web) que es lo que sucede cuando se llega al límite de memoria del stack y se produce un error

4 conceptos que se relacionan entre si y que son fundamentales para entender la recursión:

- Stack (Estructura de datos)
- Stack Allocation (Asignación de memoria)
- Stack Frame (Llamadas al Stack)
- Stack Overflow (Error)

## Stack (Estructura de datos)

El **Stack o Pila** es una estructura de datos que se caracteriza por ser un tipo de lista en la que el acceso a los elementos se realiza por un solo extremo, el cual se conoce como tope.

![Stack](/00.-Sources/Images/Pila.png)

_Ilustración del funcionamiento de una pila_

El **Stack o Pila** es una estructura de datos que se caracteriza por ser un tipo de lista en la que el acceso a los elementos se realiza por un solo extremo, el cual se conoce como tope. Este tipo de estructura se utiliza para almacenar datos de forma temporal, de manera que el último elemento en entrar es el primero en salir, también conocido cómo **last in first out (LIFO)**, cuando se añade un nuevo elemento a la pila, se le conoce como **push** y cuando se elimina un elemento se le conoce como **pop**

```c
struct Nodo {
    int dato;
    struct Nodo *next;
};
```
_Nodo de una pila en C_

## Stack Allocation (Asignación de memoria)

_La **asignación de memoria** se refiere a la forma en la que se pide y devuelve la memoria al ordenador_

![StackAllocation](/00.-Sources/Images/StackAllocation.png)

En C hay dos formas de asignar memoria a las variables; **Heap Allocation** en el Heap se administra memoria a discreción del programador y **Stack Allocation** en el que la asignación de memoria es manejada por el compilador

## Stack (Automático)

- **Tiempo de vida** → Temporal, almacena variables locales durante llamadas a funciones
- **Funcionamiento** → Locación y deslocación automática de memoria más rápida que el Heap
- **Ventajas** → Fácil de usar para el programador y más rápida que el Heap
- **Tamaño** → Crece al llamar funciones anidadas
- **Acceso** → Solo desde la función que se creó
- **Liberación** → Al finalizar la función
- **Ejemplo** → Variables locales

![Stack](/00.-Sources/Images/Stack.png)

_En este ejemplo se aprecia como el sistema operativo automáticamente crea y destruye la variable `b` en cada una de las llamadas a la función, impidiendo imprimir una secuencia de números enteros positivos_

## Stack Frame (Call Stack)

_Las **Call Stack** son las llamadas que se hacen a las funciones en el Stack y estas a su vez van formando el **Stack Frame**_

![StackFrame](/00.-Sources/Images/CallStack.jpg)

El **call stack** es una estructura de datos utilizada por la mayoría de los lenguajes de programación para realizar un seguimiento de las funciones que se han llamado y de dónde se encuentran en la ejecución del programa. En otras palabras, es una pila de funciones que se han llamado y que se están ejecutando actualmente.

El **stack frame**, o marco de pila, es un registro en el "call stack" que contiene información sobre la función actual que se está ejecutando, como por ejemplo la dirección de retorno, los argumentos de la función y las variables locales.

### El factorial de un número

Para ilustrar lo anterior vamos a ver un ejemplo de la recursión en el que se calcula el factorial de un número

![Factorial](/00.-Sources/Images/Factorial.png)

_Definición y ejemplo matemático de la función factorial_

**EL FACTORIAL DE UN ENTERO POSITIVO** es el producto de todos los enteros positivos hasta ese

```c
#include <stdio.h>

int factorial(int n)
{
	if( n < 2 )
		return 1;
	else
		return n * factorial(n-1);
}

int main()
{
	int resultado = factorial(5);

	printf("Resultado: %d\n", resultado);

	return 0;
}
```

_Ejemplo de la función factorial en C_

![Factorial](/00.-Sources/Images/CallStack-StackFrame.png)

_De izquierda a derecha ejecución de la función factorial paso a paso_

Podemos observar que la función `factorial` se llama a si misma hasta que se llega al caso base, en el que se devuelve el valor `1` y se empieza a devolver los valores de las llamadas recursivas, puesto que la función `factorial` es una función que devuelve un valor, cada vez que se llama a la función se crea un nuevo **Stack Frame** donde estamos invocando otra función diferente del mismo código que vive aparte de las otras ejecuciones donde se almacena el valor de retorno de la función, en este caso el valor de `n * factorial(n-1)` y así hasta resolver el caso recursivo

### Análisis asintótico de la función del factorial

Para analizar la complejidad de la función `factorial` vamos a utilizar el método de **Big O Notation** que nos permite analizar la complejidad de un algoritmo en función de su entrada, este principio de llegar al caso base tiene su fundamento en el principio de inducción matemática

![](/00.-Sources/Images/1.png)

_**T(n)** nos indica el número operaciones que se realizan en la **n** factorial_ 

![](/00.-Sources/Images/2.png)

_En cada llamada vamos a evaluar que **T(n)** va a estar dado por las operaciones constantes **O(1)** de la función factorial `if n < 2` y `return n * ` , decimos que son constantes porque no dependen de la entrada, es decir, no importa el tamaño de la entrada, siempre se van a realizar las mismas operaciones, mas **T(n-1)** que es `factorial(n-1)` que es la llamada recursiva_

![](/00.-Sources/Images/3.png)

_En **T(n-1)** + **O(1)**, donde se invierten los términos por comodidad_

![](/00.-Sources/Images/4.png)

_La siguiente llamada recursiva sería **T(n-2)** + **O(1)** + **O(1)**, porque se toma en cuenta la primera entrada de **T(n-1)** y la primera entrada de **O(1)**_

![](/00.-Sources/Images/5.png)

_En la siguiente llamada recursiva sería **T(n-3)** + **O(1)** + **O(1)** + **O(1)**, porque se toma en cuenta las entradas anteriores de **T(n-1)** y las dos primeras entradas de **O(1)**_

![](/00.-Sources/Images/6.png)

_Y así sucesivamente hasta llegar al caso base, donde se devuelve el valor `1` mas un número de operaciones constantes **O(1)** igual al número de llamadas recursivas_

![](/00.-Sources/Images/7.png)

_En el caso base se tiene que **T(1)** = **O(1)**, por lo que se puede decir que **T(n)** = **O(n)** o de complejidad lineal, es decir, el número de operaciones que se realizan en la función factorial es proporcional al tamaño de la entrada_

## Stack overflow (Error)

**Stack overflow** o **desbordamiento de pila** ocurre cuando la cantidad de memoria asignada al "call stack" de un programa se llena y no hay suficiente espacio para almacenar nuevos "stack frames"

![StackOverflow](/00.-Sources/Images/StackOverflow.png)

_Sitio web Stack overflow_

**Stack overflow** o **desbordamiento de pila** ocurre cuando la cantidad de memoria asignada al "call stack" de un programa se llena y no hay suficiente espacio para almacenar nuevos `stack frames`. Esto  sucede cuando se anida una gran cantidad de llamadas a funciones recursivas, lo que causa que el "call stack" crezca hasta que se agote la memoria disponible

Un ejemplo común de esto es el **conteo regresivo** en el que se llama a la función recursivamente hasta llegar a cero:


```c
#include <stdio.h>

static int n = 1000000;

void ConteoRegresivo(int n)
{
    if (0 > n--) return;

    printf("%d\n", n);
    
    ConteoRegresivo(n);
}

int main()
{
    ConteoRegresivo(n);
    
    return 0;
}
```

_Conteo regresivo con recursión_

![ConteoRecursion](/00.-Sources/Images/crr.png)

_Captura de pantalla del programa dónde se corrompe memoria al llenar el stack_

### ¿El desbordamiento de pila se puede solucionar?

Si, si hacemos la implementación de manera iterativa, no se genera el desbordamiento de pila:

```c
#include <stdio.h>
#include <stdbool.h>

static int n = 1000000;

void ConteoRegresivo(int n)
{
    while(true)
    {
        switch(n)
        {
            case 0:
                return;
            default:
                printf("%d\n", n);
                n--;
        }
    }
}

int main()
{
    ConteoRegresivo(n);
    printf("Terminado\n");

	return 0;
}
```

_Conteo regresivo con iteración_


![ConteoIteracion](/00.-Sources/Gifs/cri.gif)

_Ejecución del programa dónde **NO** se corrompe memoria al no llenar el Stack_

---
### Con esto puedes darte una idea de como funciona la recursión en C e inferir que este es el tema más importante porque es usada en los procesos algorítmicos más eficientes y en las estructuras de datos no lineales como los árboles y grafos 😌, es importante darte cuenta que no necesariamente un algoritmo recursivo es más eficiente que uno iterativo, es decir,  es más sencillo entender para el programador y las iterativas tienen un mejor rendimiento en términos de tiempo de ejecución, pero en términos de espacio de memoria ocupado, las recursivas son más eficientes, por lo que es importante saber cuando usar cada una de ellas pues no hay solución perfecta
---

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_



