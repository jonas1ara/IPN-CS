# Memoría dinámica

_La **memoria dinámica** permite al programdor solicitar memoria en **tiempo de ejecución** al sistema operativo, esto es util para problemas en los que la cantidad de datos a almacenar es desconocido o no es fijo porque no se tiene idea del número de variables de entrada cómo es el caso de las **listas enlazadas**, pero para entender su importancia debes saber que es la memoria estática y la memoria pseudoestática, la **memoria estática:** es la que esta dada explicitamente en un programa, por ejemplo en un vector de tamaño `N = 50` no importa si estas usando 17 elementos del vector, esté siempre ocupará espacio en la memoria y la **memoria pseudoestática:** es en la que el usuario da el valor de `N` para el tamaño del vector, dicho esto deberías ocupar la memoría dinámica cuando tengas grandes vectores y/o no sabes el valor real de las variables de entrada y cuando tengas vectores pequeños no tiene sentido usar la memoria dinámica_

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

- **Tiempo de vida** → Toda la duración del programa.
- **Funcionamiento** → Se reserva memoria automáticamente al inicio del programa
- **Ventajas** → Fácil de usar para el programador y sus valores se conservan entre llamadas a funciones
- **Tamaño** → Fijo / conocido en tiempo de compilación.
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → Al finalizar el programa
- **Ejemplo** → Variables globales

![SD](/00.-Sources/Images/SD.png)

_En este ejemplo se aprecia el uso de una variable estática, es decir una variable con valor fijo que no puede sufrir cambios en tiempo de compilación_

## Punteros y paso por referencia

### Punteros

_Un puntero es solo una variable que tiene una dirección de memoria 🎈 , un puntero doble es un puntero que guarda la dirección de otro apuntador 🎈🎈 y ambos apuntadores sirven para manipular, cambiar o realizar alguna operación_

![P](/00.-Sources/Images/Ptr.png)

### Parámetro de dirección

_Cuándo usamos el símbolo `&` estamos indicando la dirección, la **dirección de memoria es el lugar donde se guarda el dato**, entonces cuando escribimos `&x` estamos diciendo la dirección de la variable x_

![PD](/00.-Sources/Images/PD.png)

### Parámetro de indirección

_Cuand usamos el símbolo `*` estamos indicando el **valor que hay en la dirección**, no la dirección de memoria y este solo **señala** el valor de la dirección de memoria, usualmente usada para el paso por referencia en las funciones_

![PI](/00.-Sources/Images/PI.png)

