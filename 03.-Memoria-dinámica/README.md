# Memoría dinámica

_La **memoria dinámica** permite al programdor solicitar memoria en **tiempo de ejecución** al sistema operativo, esto es util para problemas en los que la cantidad de datos a almacenar es desconocido o no es fijo porque no se tiene idea del número de variables de entrada cómo es el caso de las **listas enlazadas**_

![DM](/00.-Sources/Images/DM.png)

## Regiones de memoria
- [Stack](#stack-automático)
- [Heap](#heap-dinámico)
- [Static Data](#static-data)

![RM](/00.-Sources/Images/RM.png)


### Stack (Automático)

- **Tiempo de vida** → Temporal, almacena variables locales durante llamadas a funciones
- **Funcionamiento** → Locación y deslocación automática de memoria
- **Tamaño** → Crece al llamar funciones anidadas
- **Acceso** → Solo desde la función que se creó
- **Liberación** → Al finalizar la función
- **Ejemplo** → Variables locales

![Stack](/00.-Sources/Images/Stack.png)


### Heap (Dinámico: malloc, calloc, realloc, free)	

- **Tiempo de vida** → A discreción del programador
- **Funcionamiento** → Se reserva memoria explícitamente usando la librería `stdlib.h`
- **Tamaño** → A discreción del programador
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → A discreción del programador
- **Ejemplo** → función `malloc`


![](/00.-Sources/Images/Free.png)

### Static Data (Automático)

- **Tiempo de vida** → Toda la duración del programa.
- **Funcionamiento** → Se reserva memoria automáticamente al inicio del programa
- **Tamaño** → Fijo / conocido en tiempo de compilación.
- **Acceso** → Desde cualquier parte del programa
- **Liberación** → Al finalizar el programa
- **Ejemplo** → Variables globales

![SD](/00.-Sources/Images/SD.png)