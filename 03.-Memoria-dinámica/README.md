# Memoría dinámica

- [Regiones de memoria](#regiones-de-memoria)
- [Punteros y paso por referencia](#punteros-y-paso-por-referencia)

![DM](/00.-Sources/Images/DM.png)

## Regiones de memoria

![RM](/00.-Sources/Images/RM.png)

### Stack (Automático)

- **Lifetime** → Temporal, almacena variables locales durante llamadas a funciones.
- **Size** → Crece al llamar funciones anidadas.

![Stack](/00.-Sources/Images/Stack.png)


### Heap (Dinámico: malloc, calloc, realloc, free)	

- **Lifetime** → A discreción del programador.
- **Size** → A discreción del programador.

![](/00.-Sources/Images/Malloc.png)

![](/00.-Sources/Images/Free.png)

### Static Data (Automático)

- **Lifetime** → Toda la duración del programa.
- **Size** → Fijo / conocido en tiempo de compilación.

![SD](/00.-Sources/Images/SD.png)