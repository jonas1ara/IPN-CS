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

Y podemos acceder a los campos de la estructura con el operador `.`:

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



