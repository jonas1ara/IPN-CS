# Cadenas

#### La librería "string.h" en C proporciona funciones para manipular y trabajar con cadenas de caracteres. Aquí hay una descripción de algunas de las funciones más importantes de esta librería y ejemplos de su uso:

![](/00.-Sources/Images/String.png)

_Las cadenas son en realidad matrices unidimensionales de caracteres que terminan en un carácter NULL '\0'. Por lo tanto, una cadena terminada en NULL contiene los caracteres que componen la cadena seguida de un NULL_

## strlen 

_La función strlen se utiliza para encontrar la longitud de una cadena de caracteres. Su sintaxis es la siguiente:_

```c
size_t strlen(const char *str);
```

Donde "str" es la cadena de caracteres de la que se quiere conocer su longitud. Esta función devuelve un valor de tipo size_t, que representa la longitud de la cadena. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char str[] = "Hola mundo";
    size_t len = strlen(str);
    printf("La longitud de la cadena es %zu\n", len);
    return 0;
}
```

Este programa imprimirá "La longitud de la cadena es 10", que es la longitud de la cadena "Hola mundo".

## strcpy

_La función strcpy se utiliza para copiar una cadena de caracteres en otra. Su sintaxis es la siguiente:_

```c
char *strcpy(char *dest, const char *src);
```

Donde "dest" es la cadena de caracteres de destino en la que se copiará "src", que es la cadena de caracteres de origen. Esta función devuelve un puntero a la cadena de destino. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char src[] = "Hola mundo";
    char dest[20];
    strcpy(dest, src);
    printf("La cadena de destino es %s\n", dest);
    return 0;
}
```

Este programa imprimirá "La cadena de destino es Hola mundo", que es la cadena de caracteres que se copió en la cadena de destino.

## strcat

_La función strcat se utiliza para concatenar una cadena de caracteres a otra. Su sintaxis es la siguiente:_

```c
char *strcat(char *dest, const char *src);
```

Donde "dest" es la cadena de caracteres de destino a la que se añadirá "src", que es la cadena de caracteres de origen. Esta función devuelve un puntero a la cadena de destino. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char dest[20] = "Hola ";
    char src[] = "mundo";
    strcat(dest, src);
    printf("La cadena concatenada es %s\n", dest);
    return 0;
}
```

Este programa imprimirá "La cadena concatenada es Hola mundo", que es la cadena de caracteres que se concatenó a la cadena de destino.

## strcmp

_La función strcmp se utiliza para comparar dos cadenas de caracteres. Su sintaxis es la siguiente:_

```c    
int strcmp(const char *str1, const char *str2);
```

Donde "str1" y "str2" son las cadenas de caracteres que se compararán. Esta función devuelve un valor entero que indica si las cadenas son iguales o no. Si las cadenas son iguales, la función devuelve 0. Si la primera cadena es menor que la segunda, la función devuelve un número negativo. Si la primera cadena es mayor que la segunda, la función devuelve un número positivo. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char str1[] = "Hola";
    char str2[] = "";
    char str3[] = "Hola mundo";

    int res1 = strcmp(str1, str2);

    if (res1 == 0) {
        printf("Las cadenas son iguales\n");
    } else if (res1 < 0) {
        printf("La primera cadena es menor que la segunda\n");
    } else {
        printf("La primera cadena es mayor que la segunda\n");
    }

    int res2 = strcmp(str1, str3);

    if (res2 == 0) {
        printf("Las cadenas son iguales\n");
    } else if (res2 < 0) {
        printf("La primera cadena es menor que la segunda\n");
    } else {
        printf("La primera cadena es mayor que la segunda\n");
    }

    return 0;
}
```

Este programa imprimirá "La primera cadena es menor que la segunda" y "La primera cadena es menor que la segunda", que es el resultado de comparar las cadenas "Hola" y "Hola mundo".

## strchr

_La función strchr se utiliza para encontrar la primera aparición de un carácter en una cadena de caracteres. Su sintaxis es la siguiente:_

```c
char *strchr(const char *str, int c);
```

Donde "str" es la cadena de caracteres en la que se buscará el carácter "c". Esta función devuelve un puntero al carácter encontrado, o NULL si no se encuentra el carácter. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char haystack[] = "La casa es roja";
    char needle[] = "roja";
    char *ptr = strstr(haystack, needle);
    if (ptr != NULL) {
        printf("La subcadena se encontró en la posición %ld\n", ptr - haystack);
    } else {
        printf("La subcadena no se encontró\n");
    }
    return 0;
}
```

Este programa imprimirá "La subcadena se encontró en la posición 11", que es la posición de la primera ocurrencia de la subcadena "roja" dentro de la cadena de búsqueda.

## memset

_La función memset se utiliza para rellenar una región de memoria con un carácter. Su sintaxis es la siguiente:_

```c
void *memset(void *ptr, int value, size_t n);
```

Donde "ptr" es el puntero a la región de memoria que se rellenará, "value" es el carácter que se usará para rellenar la región de memoria y "n" es el número de bytes que se rellenarán. Esta función devuelve un puntero a la región de memoria rellenada. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char arr[10];
    memset(arr, 'A', 10);
    for (int i = 0; i < 10; i++) 
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

Este programa imprimirá "A A A A A A A A A A", que es el bloque de memoria de 10 bytes inicializado con el valor 'A'.

## strchr

_La función strchr se utiliza para encontrar la primera aparición de un carácter en una cadena de caracteres. Su sintaxis es la siguiente:_

```c
char *strchr(const char *str, int c);
```

Donde "str" es la cadena de caracteres en la que se buscará el carácter y "c" es el carácter que se desea buscar. Esta función devuelve un puntero a la primera ocurrencia del carácter dentro de la cadena. Si el carácter no se encuentra en la cadena, se devuelve un puntero nulo. Aquí hay un ejemplo de cómo se puede utilizar:
    
```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char str[] = "Hola mundo";
    char *ptr = strchr(str, 'm');
    if (ptr != NULL) {
        printf("El carácter se encontró en la posición %ld\n", ptr - str);
    } else {
        printf("El carácter no se encontró\n");
    }
    return 0;
}
```

Este programa imprimirá "El carácter se encontró en la posición 5", que es la posición del primer carácter 'm' dentro de la cadena de caracteres.

## strcmp

_La función strcmp se utiliza para comparar dos cadenas de caracteres. Su sintaxis es la siguiente:_

```c
int strcmp(const char *str1, const char *str2);
```

Donde "str1" y "str2" son las cadenas que se van a comparar. Esta función devuelve un entero negativo si "str1" es menor que "str2", un entero positivo si "str1" es mayor que "str2" o cero si ambas cadenas son iguales. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char str1[] = "Hola";
    char str2[] = "Mundo";
    int res = strcmp(str1, str2);
    if (res < 0) {
        printf("La cadena '%s' es menor que la cadena '%s'\n", str1, str2);
    } else if (res > 0) {
        printf("La cadena '%s' es mayor que la cadena '%s'\n", str1, str2);
    } else {
        printf("Las cadenas '%s' y '%s' son iguales\n", str1, str2);
    }
    return 0;
}
```

Este programa imprimirá "La cadena 'Hola' es menor que la cadena 'Mundo'", que es el resultado de comparar las cadenas "Hola" y "Mundo".

## strtok

_La función strtok se utiliza para dividir una cadena de caracteres en tokens. Su sintaxis es la siguiente:_

```c
char *strtok(char *str, const char *delim);
```

Donde "str" es la cadena que se va a dividir y "delim" es la cadena de caracteres que se utilizará como delimitador. Esta función devuelve un puntero a la primera parte de la cadena dividida. En las llamadas sucesivas a strtok con un valor nulo para el primer argumento, la función continúa desde donde se quedó en la cadena original. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char str[] = "Hola,mundo,cruel";
    char *token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}
```

Este programa imprimirá "Hola", "mundo" y "cruel", que son los tokens de la cadena de caracteres original.

## memcpy

_La función memcpy se utiliza para copiar una región de memoria a otra. Su sintaxis es la siguiente:_

```c
void *memcpy(void *dest, const void *src, size_t n);
```

Donde "dest" es un puntero a la ubicación de memoria de destino, "src" es un puntero a la ubicación de memoria de origen y "n" es el número de bytes que se van a copiar. Esta función devuelve un puntero al bloque de memoria de destino. Aquí hay un ejemplo de cómo se puede utilizar:

```c
#include <string.h>
#include <stdio.h>

int main() 
{
    char src[] = "Hola mundo";
    char dest[11];
    memcpy(dest, src, 11);
    printf("%s\n", dest);
    return
}
```

Este programa imprimirá "Hola mundo", que es la cadena de caracteres copiada desde la ubicación de memoria de origen a la ubicación de memoria de destino.

## Algoritmos de ejemplo con este enfoque:

| # | Titulo | Implementación |
|---| ----- | -------- |
|001| Shell | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/16.-Llamadas-al-Sistema/ConstruyeUnShell/main.c) |
|002| Gestor de tareas | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/12.-Algoritmos-DrEsa%C3%BA-2/Algoritmos/17-ETS-gestor-de-tareas.c) |

---
### En el área de la programación de sistemas que es dónde el lenguaje C tiene el trono, el manejo de strings es el pan de cada día 😉
---

### Referencias

[Strings para gente con prisa](https://medium.com/@jonas_lara/strings-para-gente-con-prisa)


### Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
