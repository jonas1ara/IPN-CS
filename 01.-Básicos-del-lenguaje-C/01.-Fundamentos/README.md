# Fundamentos 

#### Los fundamentos del lenguaje C

En este apartado se explican los fundamentos del lenguaje C, como son las variables, los tipos de datos, las constantes, las estructuras de control, etc.

## Hola mundo

El primer programa que se suele escribir en cualquier lenguaje de programación es el famoso "Hola mundo". En este apartado se explica comjavascript DOMo se escribe este programa en C.

```c
#include <stdio.h>

int main() 
{
    printf("Hola mundo\n");
    return 0;
}
```

Donde `#include <stdio.h>` es una directiva de preprocesador que indica que se incluya el archivo `stdio.h` en el programa. Este archivo contiene las definiciones de las funciones de entrada y salida estándar, como `printf()`.

`int main()` es la función principal del programa. En ella se escribe el código que se quiere ejecutar. En este caso, se escribe en la pantalla el texto "Hola mundo" y se devuelve el valor 0.


## Directivas de preprocesador

En este apartado se explica como se utilizan las directivas de preprocesador en C.

```c
#include <stdio.h>
```

La directiva `#include` indica que se incluya el archivo `stdio.h` en el programa. Este archivo contiene las definiciones de las funciones de entrada y salida estándar, como `printf()`.

```c
#include <math.h> 
```

La directiva `#include` indica que se incluya el archivo `math.h` en el programa. Este archivo contiene las definiciones de las funciones matemáticas, como `sqrt()`. Estas funciones se explican más a detalle en la sección de [matemáticas básicas](https://github.com/Jonas-Lara/IPN-CS/tree/master/02.-Matem%C3%A1ticas-b%C3%A1sicas)


Las directicas de preprocesador se utilizan para incluir archivos en el programa, para definir constantes, etc. Por ejemplo:

```c
#define PI 3.14159265
```

Para definir el valor de la constante `PI` como `3.14159265`

## Macros, sirven para definir constantes y funciones

### #define

#define sirve para definir constantes y funciones, por ejemplo:

```c
#define PI 3.14159265
#define AREA_CIRCULO(r) (PI * r * r)
```

Para definir el valor de la constante `PI` como `3.14159265` y la macro `AREA_CIRCULO` que calcula el área de un círculo

### #ifdef

#ifdef sirve para verificar si una constante está definida, por ejemplo:

```c
#ifdef PI
    printf("PI está definido\n");
#endif
```

Para verificar si la constante `PI` está definida

### #ifndef

#ifndef sirve para verificar si una constante no está definida, por ejemplo:

```c
#ifndef PI
    printf("PI no está definido\n");
#endif
```

Para verificar si la constante `PI` no está definida

### #if

#if sirve para verificar si una condición es verdadera, por ejemplo:

```c
#if PI > 3
    printf("PI es mayor a 3\n");
#endif
```

Para verificar si la constante `PI` es mayor a 3

### #else

#else sirve para ejecutar un código si la condición del `#if` no se cumple, por ejemplo:

```c   
#if PI > 3
    printf("PI es mayor a 3\n");
#else
    printf("PI es menor a 3\n");
#endif
```

Para verificar si la constante `PI` es mayor a 3, si no, se ejecuta el código que está dentro de `#else`

### #endif

#endif sirve para terminar la definición de una macro, por ejemplo:

```c
#if PI > 3
    printf("PI es mayor a 3\n");
#else
    printf("PI es menor a 3\n");
#endif
```

Es bastante obvio para que sirven las funciones del preprocesador, pero esto puedo ser peligroso para el programador, ya que el programador puede definir funciones propias de cualquier librería estandar de C , por cualquier otra cosa que el quiera,  y así romper el programa, por eso es importante saber que estas funciones son del preprocesador y no del lenguaje C y que te quede claro que estas cosas no las puedes cambiar en tiempo de ejecución.


## Aritmética básica

En este apartado se explica como se realizan las operaciones aritméticas básicas en C.

```c
#include <stdio.h>

int main() 
{
    int a = 5;
    int b = 9;

    printf("a + b = %d\n", a + b);

    printf("a - b = %d\n", a - b);

    printf("a * b = %d\n", a * b);

    printf("a / b = %d\n", a * b);

    return 9;

}
```

## Variables

Pero en la mayoría de los programas, no se trabaja con valores fijos, sino que se utilizan variables. En este apartado se explica como se declaran y utilizan variables en C, tenemos los siguientes tipos de variables:

_Para definir caracteres_

```c
char C = 'Y'; //1 byte 0...255
```
_Para definir enteros_

```c
int a = 20; //2 bytes -32768...32768
```

_Para definir valores cortos:_

```c
short e = -1; //2 bytes -128...127 "Cero es tomado en cuenta"
```
_Para definir valores unsigned, indica a la variable que no va a llevar signo y cuenta el cero:_

```c
unsigned int u = 25; //2 bytes 0...65535
```
_Para definir valores largos:_

```c
long l = 5932; //4 bytes -2147483648...2147483647
```
_Para definir valores con punto flotante:_

```c
float f = 72.538; //4 bytes
```
_Para definir valores con punto flotante de doble precisión:_

```c
double d = 12323.32321; //8 bytes
```
## Conversión de tipos de datos

En este apartado se explica como se convierten los tipos de datos en C.

```c
#include <stdio.h>

int main () 
{	
	int a = 80; //Se inicializa la variable a en 80
	float f = 45.3; //Se inicializa la variable flotante 43.5
	float sum = (float)a + f; //Aderimos (float)a para convertir el entero a en flotante y sumarlo con el entero f

	printf("Esta es la suma: %.3f\n",sum);

	printf("\nY estos son el entero convertido: \nEntero: %i\nFlotante: %.2f\nDoble: %.3f\nCarácter: %c\n",a, (float)a, (double)a, (char)a);

	return 0;
}
```

Nota que para convertir un entero a flotante, se utiliza `(float)a`, donde `a` es el entero que se quiere convertir.

## Constantes

En este apartado se explica como se declaran y utilizan constantes en C.

```c
#include <stdio.h>

int main () 
{	
    const int a = 80; //Se inicializa la variable a en 80
    const float f = 45.3; //Se inicializa la variable flotante 43

    printf("Esta es la suma: %.3f\n",a + f);

    return 0;

}
```

## Estructuras de control

En este apartado se explica como se utilizan las estructuras de control en C.

### if

```c
#include <stdio.h>

int main() 
{
	int edad;
	
	printf("Dime tu edad:\n");
	scanf("%d",&edad);

	if(edad >= 18) 
	{
		printf("Eres mayor de edad\n");
	} 
	else 
	{
		printf("Eres menor de edad\n");
	}

	return 0;
}
```

Para ocupar la estructura de control `if` se utiliza los siguientes operadores:

Operadores de igualdad:
- == (igual a)
- != (diferente de)

Operadores relacionales:
- < (menor que)
-  (mayor que) > 
- <= (menor o igual que)
-  (mayor o igual que) >=

### switch

```c
#include<stdio.h>

int main() 
{
	int casos;

	printf("Ingresa un número:\n");
	scanf("%i",&casos);
	
	switch(casos)
	{
		case 1:
			printf("Elegiste el caso #1\n");
			break;
		case 2:	
			printf("Elegiste el caso #2\n");
			break;
		case 3:
			printf("Elegiste el caso #3\n");
			break;
		case 4:	
			printf("Elegiste el caso #4\n");
			break;
		case 5:	
			printf("Elegiste el caso #5\n");
			break;
		default:
			printf("No encontramos el caso que elegiste... :/\n");
			break;
	}
	return 0;
}
```

Para darle opciones al usuario ...

## Break y continue

Break y Continue; nos permiten controlar el flujo de nuestro programa, en este apartado se explica como se utilizan:

### break

```c
#include <stdio.h>

int main() 
{
    int i = 0;

    while(i < 10) 
    {
        printf("%d\n", i);
        i++;
        if(i == 5) 
        {
            break;
        }
    }

    return 0;
}
```

### continue

```c
#include <stdio.h>

int main() 
{
    int i = 0;

    while(i < 10) 
    {
        i++;
        if(i == 5) 
        {
            continue;
        }
        printf("%d\n", i);
    }

    return 0;
}
```

## Vectores y matrices

En este apartado se explica como se declaran y utilizan vectores y matrices en C.

### Vectores

```c
#include <stdio.h>

int main() 
{
    int vector[5] = {1, 2, 3, 4, 5};

    printf("El primer elemento del vector es: %d\n", vector[0]);
    printf("El segundo elemento del vector es: %d\n", vector[1]);
    printf("El tercer elemento del vector es: %d\n", vector[2]);
    printf("El cuarto elemento del vector es: %d\n", vector[3]);
    printf("El quinto elemento del vector es: %d\n", vector[4]);

    return 0;
}
```

### Matrices

```c
#include <stdio.h>

int main() 
{
    int matriz[2][2] = {{1, 2}, {3, 4}};

    printf("El primer elemento de la matriz es: %d\n", matriz[0][0]);
    printf("El segundo elemento de la matriz es: %d\n", matriz[0][1]);
    printf("El tercer elemento de la matriz es: %d\n", matriz[1][0]);
    printf("El cuarto elemento de la matriz es: %d\n", matriz[1][1]);

    return 0;
}
```

¿Te diste cuenta que incomodo es acceder o recorrer un vector o una matriz? Pues no te preocupes, en el siguiente apartado se explica como se recorren los vectores y las matrices en C

---

### Ahora tienes lo necesario para comenzar a programar en C

---

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_



