# Estructuras

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

Y podemos acceder a los campos de la estructura con el operador `->`:

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

## Uniones

Las uniones son una forma de agrupar tipos de datos abstractos. Por ejemplo, si queremos guardar información de una persona, podemos hacerlo de la siguiente forma:

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



## Enumeraciones

Las enumeraciones son una forma de agrupar tipos de datos abstractos. Por ejemplo, si queremos guardar información de una persona, podemos hacerlo de la siguiente forma:

```c
char nombre[20];
int edad;
```

Pero si queremos guardar información de varias personas, tendremos que escribir el código varias veces. Para evitar esto, podemos crear una enumeración que guarde la información de una persona:

```c
enum persona {
    NOMBRE,
    EDAD
};
```

Ahora, para guardar la información de una persona, podemos declarar una variable de tipo `enum persona`:

```c
enum persona juan;
```

Y podemos acceder a los campos de la enumeración con el operador  apuntador `.`:

```c
juan.NOMBRE = "Juan";
juan.EDAD = 20;
```

enum es util para guardar valores de un tipo de dato, por ejemplo, guardar los días de la semana.


## Ejercicios

1. Crea una estructura que guarde la información de una persona.
2. Crea una estructura que guarde la información de una persona y su dirección.
3. Crea una estructura que guarde la información de una persona y su dirección, usando punteros.
4. Crea una estructura que guarde la información de una persona y su dirección, usando punteros a funciones.

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado_


