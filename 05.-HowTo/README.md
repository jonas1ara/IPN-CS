# How To

_Impletaciones de sofware para hacer tareas especificas_

![](/00.-Sources/Images/HowTo.jpeg)

Supon que quieres medir el tiempo que tarda en ejecutarse el algoritmo de `ordenamiento por inserción` en un array de 1000000 elementos. Para ello, tendrías que hacer lo siguiente:

- Crear un array de 1000000 elementos
- Generar 1000000 números aleatorios
- Programar el algoritmo de `ordenamiento por insercción`
- Medir el tiempo que tarda en ejecutarse

Te puedes dar cuenta que para realizar esa tarea debes tener conocimiento de cómo crear y recorrer un arreglo de 1000000 elementos, conocer la función `srand()` y `rand()` para generar números aleatorios, conocer el algoritmo de `ordenamiento por insercción` y por último, conocer la función `time()` para medir el tiempo que tarda en ejecutarse el algoritmo

_La programación es saber cómo unir piezas de código para realizar una tarea específica_

## Contenido

### Medir tiempo de ejecución

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Código a medir
    printf("Midiendo ...\n");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución: %f\n", cpu_time_used);

    return 0;
}
```

