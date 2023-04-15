# Modularidad

![](/00.-Sources/Images/Mod.png)

_Proyecto dividido en modulos_

En este capítulo vamos a ver cómo podemos dividir nuestro programa en módulos, para que sea más fácil de entender y de mantener.

## ¿Cómo estructurar un proyecto en multiples archivos?

Para poder dividir nuestro programa en módulos, vamos a necesitar crear varios archivos. Para ello, vamos a crear una carpeta llamada `src` (que significa "source", o "fuente") y dentro de ella vamos a crear un archivo llamado `main.c` para nuestra función principal y otros 2 llamados `prueba.c` y `prueba.h` que van a contener el código de nuestro módulo

En el archivo `prueba.h` vamos a definir la cabecera de la función `prueba`, de esta manera otros archivos van a poder utilizar la función `prueba` que es publica:

```c
void prueba(int *x);
```

En el archivo `prueba.c` vamos a definir la función `prueba`, esta función es parte de nuestro modulo:

```c
#include "prueba.h"

void prueba(int *x)
{
    *x += 10;
}
```

En el archivo `main.c` vamos a utilizar la función `prueba` que es publica, pasandole el valor de `x` por referencia:

```c
#include <stdio.h>
#include "prueba.h"

int main()
{
    int x = 5;

    prueba (&x);

    printf("El valor de x es %d\n", x);

    return 0;
}
```

Claro que si tenemos una función publica, también podemos tener una privada, por ejemplo, una función que solo se va a utilizar dentro del módulo, en este caso, vamos a crear una función privada llamada `prueba2` dentro de nuestro módulo `prueba`:

```c
#include "prueba.h"

static void prueba2(int *x)
{
    *x += 10;
}

void prueba(int *x)
{
    *x += 10;
}
```

Hace exactamente lo mismo que la función `prueba`, pero esta vez, solo se puede utilizar dentro del módulo `prueba`, si tratamos de llamar a la función `prueba2` desde el archivo `main.c` nos va a dar un error:

```c
#include <stdio.h>
#include "prueba.h"

int main()
{
    int x = 5;

    prueba (&x);

    prueba2 (&x); // Error

    printf("El valor de x es %d\n", x);

    return 0;
}
```

Esto no se puede, porque la función `prueba2` es privada, solo se puede utilizar dentro del módulo `prueba`. Cuándo Dennis Ritchie creó el lenguaje C, pensó que era importante que los módulos fueran independientes, por eso, no se puede acceder a las variables privadas de un módulo desde otro módulo

Si queremos usarla sería de esta manera:

```c
#include "prueba.h"

static void prueba2(int *x)
{
    *x += 10;
}

void prueba(int *x)
{
    *x += 10;
    prueba2 (x); 
}
```

_Cuándo le quitamos el *x, estamos pasando la dirección de memoria de x y no el valor de x, como si lo llamaramos con desde el main_

Con esto vemos que una función privada solo puede ser usada desde otras funciones del mismo módulo y siempre tienen que estar encima de las funciones que las publicas

## ¿Cómo compilar un proyecto en multiples archivos?

Para compilar un proyecto en multiples archivos, vamos a necesitar un archivo llamado `Makefile`, que es un archivo de texto que contiene las instrucciones para compilar nuestro programa. En este archivo vamos a definir las reglas para compilar nuestro programa, en este caso, si quieres aprender más sobre `Makefile`, puedes leer el capítulo [Makefile](https://github.com/Jonas-Lara/IPN-CS/tree/master/07.-Make)

```makefile
# Regla principal, que se ejecutará si no ocurre nada
all:main

# Esta regla compila el programa principal
main: prueba.o main.o 
	gcc -o main prueba.o main.o 

prueba.o: prueba.c prueba.h
	gcc -c prueba.c

main.o: main.c prueba.h
	gcc -c main.c

# Regla ficticia
clean:
	rm -f main *.o
```

## Algoritmos de ejemplo con este enfoque:

| # | Titulo | Implementación |
|---| ----- | -------- |
|001| Make | [C](https://github.com/Jonas-Lara/IPN-CS/tree/master/07.-Make) |
|002| Matriz | [C](https://github.com/Jonas-Lara/IPN-CS/tree/master/08.-Consola/05.-Matrix) |


### En resumen la modularidad nos ayuda a compartir las declaraciones de funciones y variables entre archivos, y a separar el código en módulos, para que sea más fácil de entender y de mantener nuestro proyecto  🤓

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_









