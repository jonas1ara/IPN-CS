# Memoría dinámica

_La **memoria dinámica** permite al programdor solicitar memoria en **tiempo de ejecución** al sistema operativo, esto es util para problemas en los que la cantidad de datos a almacenar es desconocido o no es fijo porque no se tiene idea del número de variables de entrada cómo es el caso de las **listas enlazadas**_

![DM](/00.-Sources/Images/DM.png)

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


### Heap (Dinámico: malloc, calloc, realloc, free)	

- **Tiempo de vida** → A discreción del programador
- **Funcionamiento** → Se reserva memoria explícitamente usando la librería `stdlib.h`
- **Ventajas** → **Control directo de memoria por parte del programador** pero más lento que el Stack y menos productividad que el Stack
- **Tamaño** → A discreción del programador
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → A discreción del programador
- **Ejemplo** → función `malloc`

```C
vector = (int *) malloc(N * sizeof(int)); //Función malloc para asignar un tamaño al vector de N enteros
```

```C
vector = (int *) calloc(N,  sizeof(int)); //Función calloc para asignar un tamaño al vector de N enteros y asignarle un valor inicial de 0 
```

```C
vector = (int *) realloc(vector, N * sizeof(int)); //Función realloc para redimensionar el vector conservando sus valores 
```

```C
free(vector); //Función free para liberar la memoria
```

![](/00.-Sources/Images/Free.png)

_En este ejemplo podemos ver en la linea 16 del código que cuando inicializamos malloc con la variable `ptr` apunta a una dirección de memoria de 4 bytes por ser un tipo de dato entero que es especificado por la función `sizeof(int)`, después en la función main hacemos uso de la función `fl` asignando el valor que retorna a la variable `ptr2`, imprimimos y al final liberamos la memoria solicitada_


### Static Data (Automático)

- **Tiempo de vida** → Toda la duración del programa.
- **Funcionamiento** → Se reserva memoria automáticamente al inicio del programa
- **Ventajas** → Fácil de usar para el programador y sus valores se conservan entre llamadas a funciones
- **Tamaño** → Fijo / conocido en tiempo de compilación.
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → Al finalizar el programa
- **Ejemplo** → Variables globales

![SD](/00.-Sources/Images/SD.png)

_En este ejemplo se aprecia el uso de una variable estática, es decir una variable con valor fijo que no puede sufrir cambios en tiempo de compilación_