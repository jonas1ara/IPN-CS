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

![StackFrame](/00.-Sources/Images/StackFrame.png)

El **call stack** es una estructura de datos utilizada por la mayoría de los lenguajes de programación para realizar un seguimiento de las funciones que se han llamado y de dónde se encuentran en la ejecución del programa. En otras palabras, es una pila de funciones que se han llamado y que se están ejecutando actualmente.

El **stack frame**, o marco de pila, es un registro en el "call stack" que contiene información sobre la función actual que se está ejecutando, como por ejemplo la dirección de retorno, los argumentos de la función y las variables locales.

### El factorial de un número

**EL FACTORIAL DE UN ENTERO POSITIVO** es el producto de todos los enteros positivos hasta ese

![Factorial](/00.-Sources/Images/Factorial.png)

_Ejemplo matemático de la función factorial_

Para ilustrar lo anterior vamos a ver un ejemplo de la recursión en el que se calcula el factorial de un número

```c
#include <stdio.h>

int fact(int n)
{
	if( n < 2 )
		return 1;
	else
		return n * fact(n-1);
}

int main()
{
	int result = fact(5);

	printf("Result: %d\n", result);

	return 0;
}
```

![Factorial](/00.-Sources/Images/CallStack-StackFrame.png)



