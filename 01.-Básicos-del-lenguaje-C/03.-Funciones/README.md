# Funciones

Las funciones son un bloque de código que se ejecuta cuando es llamado. Las funciones son muy útiles para evitar repetir código. Por ejemplo, si queremos imprimir un mensaje en pantalla, podemos hacerlo de la siguiente forma:

```c
printf("Hola mundo");
```

Pero si queremos imprimir el mismo mensaje varias veces, tendremos que escribir el código varias veces. Para evitar esto, podemos crear una función que imprima el mensaje:

```c
void imprimir_mensaje() {
    printf("Hola mundo");
}
```

Ahora, para imprimir el mensaje, podemos llamar a la función:

```c
imprimir_mensaje();
```

## Parámetros

Las funciones pueden recibir parámetros. Por ejemplo, si queremos imprimir un mensaje con un nombre, podemos hacerlo de la siguiente forma:

```c
void imprimir_mensaje_con_nombre(char *nombre) {
    printf("Hola %s", nombre);
}
```

Ahora, para imprimir el mensaje, podemos llamar a la función:

```c
imprimir_mensaje_con_nombre("Juan");
```

## Retorno

Las funciones pueden retornar un valor. Por ejemplo, si queremos sumar dos números, podemos hacerlo de la siguiente forma:

```c
int sumar(int a, int b) {
    return a + b;
}
```

Ahora, para sumar dos números, podemos llamar a la función:

```c
int resultado = sumar(2, 3);
```

## Funciones predefinidas

C cuenta con varias funciones predefinidas. Por ejemplo, la función `printf` que ya vimos. Otras funciones predefinidas son:

- `scanf`: Lee un valor desde la entrada estándar.
- `strlen`: Calcula la longitud de una cadena.
- `strcmp`: Compara dos cadenas.
- `strcpy`: Copia una cadena en otra.
- `strcat`: Concatena dos cadenas.
- `malloc`: Reserva memoria en el heap.
- `free`: Libera memoria reservada en el heap.
- `rand`: Genera un número aleatorio.
- `srand`: Inicializa la función `rand`.
- `time`: Obtiene la hora actual.
- `exit`: Finaliza el programa.

## Ejercicios

1. Escribir una función que reciba un número y devuelva el doble de ese número.
2. Escribir una función que reciba un número y devuelva el cuadrado de ese número.

## Ejercicios avanzados

1. Escribir una función que reciba un número y devuelva el factorial de ese número.
2. Escribir una función que reciba un número y devuelva si es primo o no.
3. Escribir una función que reciba un número y devuelva si es par o no.
4. Escribir una función que reciba un número y devuelva si es impar o no.
5. Escribir una función que reciba un número y devuelva si es positivo o no.

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado_