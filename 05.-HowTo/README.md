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

_Programa para medir el tiempo de ejecución de un algoritmo_

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

La librería `time.h` nos proporciona un nuevo tipo de dato `clock_t` que es de tipo `long int` y  la función `clock()` que nos permite medir el tiempo de ejecución de un algoritmo. La función `clock()` nos devuelve el tiempo en milisegundos que tarda en ejecutarse el algoritmo, para convertirlo a segundos, debemos dividirlo entre `CLOCKS_PER_SEC` que es una constante que nos proporciona la librería `time.h` y que nos indica el número de milisegundos que hay en un segundo, eso lo guardamos en la variable `cpu_time_used` y la imprimimos en pantalla al final

### Generar números aleatorios

_Programa para generar números aleatorios_

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000000
#define NUMS_TO_GENERATE 1000
 
int main() 
{

    int numeros[NUMS_TO_GENERATE] = { 0 }, N ; //Declara arreglo vacio del tamaño que tome NUMS_TO_GENERATE 
 
    srand(time(NULL)); 
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX; 
 		
    	printf("%d.- %d\n",i, N); //Se imprime variable i que es el número de iteración (opcional) y N que es el número generado

	 }

    exit(EXIT_SUCCESS);
}
```

En la constante `MAX` definimos el tamaño máximo de los números a generar, en la constante `NUMS_TO_GENERATE` definimos el número de números a generar. La función `srand()` nos permite generar números pseudo aleatorios, para ello, le pasamos como parámetro la función `time()` que nos devuelve el tiempo en milisegundos que ha transcurrido desde el 1 de enero de 1970 hasta el momento en que se ejecuta el programa. La función `rand()` nos devuelve un número pseudo aleatorio entre 0 y el número que le pasemos como parámetro, en este caso, le pasamos como parámetro la constante `MAX` que es 1000000, por lo tanto, la función `rand()` nos devolverá un número entre 0 y 1000000. La función `rand()` nos devuelve un número entero, por lo tanto, para que nos devuelva un número decimal, lo dividimos entre `MAX` que es 1000000 y lo guardamos en la variable `N` que es de tipo `int` y la imprimimos en pantalla

