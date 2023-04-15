# Memoria dinámica

#### La memoria dinámica permite al programador solicitar memoria en _tiempo de ejecución_ al sistema operativo 🤯

![DM](/00.-Sources/Images/DM.png)

_"Regiones" de una memoria RAM_

La **[memoria dinámica](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/03-Memoria-Din%C3%A1mica.c)** permite al programador solicitar memoria en **tiempo de ejecución** al sistema operativo, esto es util para problemas en los que la cantidad de datos a almacenar es desconocido o no es fijo porque no se tiene idea del número de variables de entrada cómo es el caso de las **listas enlazadas**, pero para entender su importancia debes saber que es la memoria estática y la memoria pseudoestática, la **[memoria estática:](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/01-Memoria-Est%C3%A1tica.c)** es la que esta dada explícitamente en un programa, por ejemplo en un vector de tamaño `N = 50` no importa si estas usando 17 elementos del vector, esté siempre ocupará espacio en la memoria y la **[memoria pseudoestática:](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/02-Memoria-Pseudoest%C3%A1tica.c)** es en la que el usuario da el valor de `N` para el tamaño del vector, dicho esto deberías ocupar la memoría dinámica cuando tengas grandes vectores y/o no sabes el valor real de las variables de entrada y cuando tengas vectores pequeños no tiene sentido usar la memoria dinámica


## Regiones de memoria
_En la memoria principal se pueden distinguir dos regiones importantes: [Stack](#stack-automático) y el [Heap](#heap-dinámico-malloc-calloc-realloc-free)_

![RM](/00.-Sources/Images/RM.png)

### Stack (Automático)

- **Tiempo de vida** → Temporal, almacena variables locales durante llamadas a funciones
- **Funcionamiento** → Locación y deslocación automática de memoria más rápida que el Heap
- **Ventajas** → Fácil de usar para el programador y más rápida que el Heap
- **Tamaño** → Crece al llamar funciones anidadas
- **Acceso** → Solo desde la función que se creó
- **Liberación** → Al finalizar la función
- **Ejemplo** → Variables locales

![Stack](/00.-Sources/Images/Stack.png)

_En este ejemplo se aprecia como el sistema operativo automáticamente crea y destruye la variable `b` en cada una de las llamadas a la función, impidiendo imprimir una secuencia de números enteros positivos_


### Heap (Dinámico: [malloc](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/04-Malloc-y-Realloc.c), [calloc](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/05-Calloc-y-Free.c), [realloc](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/04-Malloc-y-Realloc.c), [free](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/05-Calloc-y-Free.c))	

- **Tiempo de vida** → A discreción del programador
- **Funcionamiento** → Se reserva memoria explícitamente usando la librería `stdlib.h`
- **Ventajas** → **Control directo de memoria por parte del programador** pero más lento que el Stack y menos productividad que el Stack
- **Tamaño** → A discreción del programador
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → A discreción del programador
- **Ejemplo** → función `malloc`

![](/00.-Sources/Images/Heap.png)

_En este ejemplo podemos ver en la linea 16 del código que cuando inicializamos malloc con la variable `ptr` apunta a una dirección de memoria de 4 bytes por ser un tipo de dato entero que es especificado por la función `sizeof(int)`, después en la función main hacemos uso de la función `fl` asignando el valor que retorna a la variable `ptr2`, imprimimos y al final liberamos la memoria solicitada_

#### Funciones de la librería `stdlib.h`

```C
vector = (int *) malloc(N * sizeof(int)); 
```
_Función **malloc** para asignar un tamaño al vector de N enteros_

```C
vector = (int *) calloc(N,  sizeof(int)); 
```
_Función **calloc** para asignar un tamaño al vector de N enteros y asignarle un valor inicial de 0_

```C
vector = (int *) realloc(vector, N * sizeof(int)); 
```
_Función **realloc** para redimensionar el vector conservando sus valores_

```C
free(vector);
```
_Función **free** para liberar la memoria solicitada_



### Static Data (Automático)

- **Tiempo de vida** → Toda la duración del programa
- **Funcionamiento** → Se reserva memoria automáticamente al inicio del programa
- **Ventajas** → Fácil de usar para el programador y sus valores se conservan entre llamadas a funciones
- **Tamaño** → Fijo / conocido en tiempo de compilación
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → Al finalizar el programa
- **Ejemplo** → Variables globales

![SD](/00.-Sources/Images/SD.png)

_En este ejemplo se aprecia el uso de una variable estática, es decir una variable con valor fijo que no puede sufrir cambios en tiempo de compilación_

## Algoritmos de ejemplo con este enfoque:

| # | Titulo | Implementación |
|---| ----- | -------- |
|001| Matrices dinámicas | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/Algoritmos/07-Matrices-din%C3%A1micas.c) |
|002| Estructuras de datos | [C](https://github.com/Jonas-Lara/IPN-CS/tree/master/11.-Estructuras-de-Datos-en-C) |
|003| Matrices dinámicas | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/03.-Memoria-din%C3%A1mica/07-Matrices-din%C3%A1micas.c) |

### Quizá al principio te cueste y no entiendas para que es útil el manejo de memoria, pero conforme avances en tú carrera lo entenderás y regresarás a este repositorio 🫢

## Referencias

_[Memoria dinámica en Medium por Jonas Lara](https://medium.com/@jonas_lara/memoria-din%C3%A1mica-en-c-55bdcad1fe71)_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_

