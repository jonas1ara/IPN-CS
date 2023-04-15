# Estructuras

#### Las estructuras son una forma de agrupar tipos de datos abstractos

![](/00.-Sources/Images/NC.jpg)

_Números complejos son un ejemplo de tipos de datos abstractos_

Las estructuras son una forma de agrupar tipos de datos abstractos. Por ejemplo, si queremos guardar información de una persona, podemos hacerlo de la siguiente forma:

```c
char nombre[20];
int edad;
```

Pero si queremos guardar información de varias personas, tendremos que escribir el código varias veces. Para evitar esto, podemos crear una estructura que guarde la información de una persona:

```c
struct persona {
    char nombre[20];
    int edad;
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `struct persona`:

```c
struct persona juan;
```

Y podemos acceder a los campos de la estructura con el operador  apuntador `.`:

```c
juan.nombre = "Juan";
juan.edad = 20;
```

## Estructuras anidadas

Las estructuras pueden contener otras estructuras. Por ejemplo, si queremos guardar información de una persona y su dirección, podemos hacerlo de la siguiente forma:

```c
struct direccion {
    char calle[20];
    int numero;
};

struct persona {
    char nombre[20];
    int edad;
    struct direccion direccion;
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `struct persona`:

```c
struct persona juan;
```

Y podemos acceder a los campos de la estructura con el operador `.`:

```c
juan.nombre = "Juan";
juan.edad = 20;
juan.direccion.calle = "Calle Falsa";
juan.direccion.numero = 123;
```

## Estructuras con punteros

Las estructuras pueden contener punteros. Por ejemplo, si queremos guardar información de una persona y su dirección, podemos hacerlo de la siguiente forma:

```c
struct direccion {
    char calle[20];
    int numero;
};

struct persona {
    char nombre[20];
    int edad;
    struct direccion *direccion;
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `struct persona`:

```c
struct persona juan;
```

Y podemos acceder a los campos de la estructura con el operador `.`:

```c
juan.nombre = "Juan";
juan.edad = 20;
juan.direccion->calle = "Calle Falsa";
juan.direccion->numero = 123;
```

## Estructuras con punteros a funciones

Las estructuras pueden contener punteros a funciones. Por ejemplo, si queremos guardar información de una persona y su dirección, podemos hacerlo de la siguiente forma:

```c
struct direccion {
    char calle[20];
    int numero;
};

struct persona {
    char nombre[20];
    int edad;
    struct direccion *direccion;
    void (*saludar)();
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `struct persona`:

```c
struct persona juan;
```

Y podemos acceder a los campos de la estructura con el operador `->`:

```c
juan.nombre = "Juan";
juan.edad = 20;
juan.direccion->calle = "Calle Falsa";
juan.direccion->numero = 123;
juan.saludar = saludar;
```

La principal diferencia entre el operador "->" y el "." es que el primero se utiliza para acceder a los miembros de un objeto a través de un puntero a ese objeto, mientras que el segundo se utiliza para acceder a los miembros de un objeto directamente.

## Typedef

El tipo de una estructura se puede guardar en una variable de tipo `typedef`, para poder usarla más fácilmente, renombrando el tipo de la estructura. Por ejemplo, si queremos guardar información de una persona, podemos hacerlo de la siguiente forma:

```c
typedef struct persona {
    char nombre[20];
    int edad;
} persona_t;
```

Ahora, para declarar una variable de tipo `persona_t`, podemos hacerlo de la siguiente forma:

```c
persona_t juan;
```

Es útil para renombrar tipos de datos, por ejemplo, para renombrar `struct persona` a `persona_t`, pero puede ser peligroso, ya que ensucias el espacio de nombres global.

## Uniones

Las uniones son una forma de agrupar tipos de datos abstractos, semejantes a las estructuras, pero con la diferencia de que todos los campos comparten una unidad de memoria. Por ejemplo, si queremos guardar información de una persona, podemos hacerlo de la siguiente forma:

```c
char nombre[20];
int edad;
```

Pero si queremos guardar información de varias personas, tendremos que escribir el código varias veces. Para evitar esto, podemos crear una unión que guarde la información de una persona:

```c
union persona {
    char nombre[20];
    int edad;
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `union persona`:

```c
union persona juan;
```

Y podemos acceder a los campos de la unión con el operador  apuntador `.`:

```c
juan.nombre = "Juan";
juan.edad = 20;
```

Las uniones son útiles para sistemas embebidos, donde se necesita ahorrar memoria y también para construir números complejos.

## Enumeraciones

Las enumeraciones son una forma de agrupar tipos de datos abstractos, nos permiten asignar constantes a lo bestia, por ejemplo, podemos construir un enum para simular los días de la semana:

```c
enum diasemana{
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};
```

y podemos usarlo de la siguiente forma:

```c
int main{
    enum diasemana dia = LUNES;
    printf("El día es: %d", dia);
    return 0;
}
```

A tener en cuenta que los enum son variables constantes declaradas de una forma bonita, ya que si se busca imprimir el valor de LUNES, se imprimirá 0, ya que es el valor que se le asigna a la primera variable del enum. 

## Algoritmos de ejemplo con este enfoque:

| # | Titulo | Implementación |
|---| ----- | -------- |
|001|Números racionales| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/06.-Algoritmos-DrEsa%C3%BA-1/Algoritmos/015.-Numeros-Racionales/15-Numeros-Racionales.c) |
|002| Pilas dinámica | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/11.-Estructuras-de-Datos-en-C/01.-Pilas/02-Pila-dinamica.c) |
|003|  Colas dinámica | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/11.-Estructuras-de-Datos-en-C/02.-Colas/02-Cola-dinamica.c) |
|004| Lista enlazada simple | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/11.-Estructuras-de-Datos-en-C/03.-Listas-Enlazadas/01-Lista-enlazada-simple.c) |

### Todo el rollo de las estructuras es para poder agrupar tipos de datos abstractos a convenencia, para poder hacer programas más legibles y ordenados, ya que si no se agrupan los tipos de datos, se tendría que escribir el código varias veces, lo que haría el programa más difícil de leer y de mantener 😉

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_


