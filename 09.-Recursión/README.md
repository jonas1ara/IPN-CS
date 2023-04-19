# Recursión

_La recursión es una técnica que consiste en resolver un problema haciendo uso de una versión más sencilla del mismo_

## ¿Qué es la recursión?

![Recursión](/00.-Sources/Images/Recursion.png)

La recursión es un concepto importante en la programación y se refiere a la capacidad de una función o procedimiento de llamarse a sí mismo dentro de su propia definición. Es decir, en lugar de resolver un problema mediante un enfoque lineal, se utiliza la técnica de "dividir y conquistar", en la que un problema se divide en subproblemas más pequeños que se resuelven mediante la misma función recursiva, hasta que se alcanza un caso base que se puede resolver de forma trivial, de manera concreta podemos decir que consta de dos partes fundamentales:

- **Caso base:** Es el caso más sencillo que se puede resolver sin necesidad de hacer uso de la recursión

- **Caso recursivo:** Es el caso en el que se llama a la función recursiva para resolver un problema más sencillo

**Supongamos que tenemos que obtener el inventario de un almacen, que tiene varios estantes y cada estante tiene varias cajas, para resolver este problema podemos hacer uso de la recursión:**

![CByCR](/00.-Sources/Images/Recursion1.png)


## ¿Para entender la recursión es necesario entender la recursión?

_Esto se dice mucho pero personalmento creo que es una broma de mal gusto_

Para comprender la recursión debes entender o por lo menos conocer el concepto de **stack** pero no solo como stack en el campo de las **estructuras de datos**, sino como el Stack en la **asignación de memoria**, las **llamadas al Stack** en el Stack Frame, y por último la recursión y el **Stack Overflow**(No el página web) que es lo que sucede cuando se llega al límite de memoria del stack y se produce un error

4 conceptos que se relacionan entre si y que son fundamentales para entender la recursión:

- Stack (Estructura de datos)
- Stack Allocation (Asignación de memoria)
- Stack Frame (Llamadas al Stack)
- Stack Overflow (Error)

### Stack (Estructura de datos)

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

### Stack Allocation (Asignación de memoria)

_La **asignación de memoria** se refiere a la forma en la que se asigna la memoria a las variables_

![StackAllocation](/00.-Sources/Images/StackAllocation.png)

En C hay dos formas de asignar memoria a las variables; **Heap Allocation** en el Heap se administra memoria a discreción del programador y **Stack Allocation** en el que la asignación de memoria es manejada por el compilador

#### Stack (Automático)

- **Tiempo de vida** → Temporal, almacena variables locales durante llamadas a funciones
- **Funcionamiento** → Locación y deslocación automática de memoria más rápida que el Heap
- **Ventajas** → Fácil de usar para el programador y más rápida que el Heap
- **Tamaño** → Crece al llamar funciones anidadas
- **Acceso** → Solo desde la función que se creó
- **Liberación** → Al finalizar la función
- **Ejemplo** → Variables locales

![Stack](/00.-Sources/Images/Stack.png)

_En este ejemplo se aprecia como el sistema operativo automáticamente crea y destruye la variable `b` en cada una de las llamadas a la función, impidiendo imprimir una secuencia de números enteros positivos_

### Stack Frame (Call Stack)

_Las **Call Stack** son las llamadas que se hacen a las funciones en el Stack y estas a su vez van formando el **Stack Frame**_

![StackFrame](/00.-Sources/Images/CallStack.jpg)

El **call stack** es una estructura de datos utilizada por la mayoría de los lenguajes de programación para realizar un seguimiento de las funciones que se han llamado y de dónde se encuentran en la ejecución del programa. En otras palabras, es una pila de funciones que se han llamado y que se están ejecutando actualmente.

El **stack frame**, o marco de pila, es un registro en el "call stack" que contiene información sobre la función actual que se está ejecutando, como por ejemplo la dirección de retorno, los argumentos de la función y las variables locales.

### El factorial de un número

Para ilustrar lo anterior vamos a ver un ejemplo de la recursión en el que se calcula el factorial de un número

![Factorial](/00.-Sources/Images/Factorial.png)

_Ejemplo matemático de la función factorial_

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
	int result = factorial(5);

	printf("Result: %d\n", result);

    //Result: 120

	return 0;
}
```

_Ejemplo de la función factorial en C_

![Factorial](/00.-Sources/Images/CallStack-StackFrame.png)

_De izquierda a derecha ejecución de la función factorial paso a paso_

Podemos observar que la función `factorial` se llama a si misma hasta que se llega al caso base, en el que se devuelve el valor `1` y se empieza a devolver los valores de las llamadas recursivas, puesto que la función `factorial` es una función que devuelve un valor, cada vez que se llama a la función se crea un nuevo **Stack Frame** donde estamos invocando otra función diferente del mismo código que vive aparte de las otras ejecuciones donde se almacena el valor de retorno de la función, en este caso el valor de `n * factorial(n-1)` y así hasta resolver el caso recursivo

### Analizar operaciones de la recursión



### Stack Overflow (Error)

**Stack Overflow** o **desbordamiento de pila** ocurre cuando la cantidad de memoria asignada al "call stack" de un programa se llena y no hay suficiente espacio para almacenar nuevos "stack frames"

![StackOverflow](/00.-Sources/Images/StackOverflow.png)

_Sitio web Stack Overflow_

**Stack Overflow** o **desbordamiento de pila** ocurre cuando la cantidad de memoria asignada al "call stack" de un programa se llena y no hay suficiente espacio para almacenar nuevos `stack frames`. Esto  sucede cuando se anida una gran cantidad de llamadas a funciones recursivas, lo que causa que el "call stack" crezca hasta que se agote la memoria disponible

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

_Captura de pantalla del programa dónde se corrompe memoria al llenar el Stack_

#### ¿El desboda de pila se puede solucionar?

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

_Ejecución del programa dónde NO se corrompe memoria al no llenar el Stack_


---

### Con esto puedes darte una idea de como funciona la recursión en C e inferir que este es el tema más importante porque es usada en los procesos algorítmicos más eficientes y en las estructuras de datos no lineales como los árboles y grafos 😌

---

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_



