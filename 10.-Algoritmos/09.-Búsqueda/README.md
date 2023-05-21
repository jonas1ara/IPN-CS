# Algoritmos de búsqueda

![Ab](/01.-Sources/Images/Ab.png)

_Representación de algoritmos de búsqueda_

## Los algoritmos de búsqueda son métodos o procedimientos utilizados para encontrar un elemento específico dentro de una estructura de datos

Los algoritmos de búsqueda son métodos o procedimientos utilizados para encontrar un elemento específico dentro de una estructura de datos. Los algoritmos de búsqueda son ampliamente utilizados en ciencias de la computación y se aplican en una variedad de problemas

Existen diferentes tipos de algoritmos de búsqueda, cada uno con sus propias características y eficiencia en términos de tiempo de ejecución y uso de recursos. Algunos de los algoritmos de búsqueda más comunes son:

- Búsqueda lineal

- Búsqueda binaria

- Búsqueda por interpolación

- Búsqueda por tabla hash


### Ventajas

- Versatilidad: Los algoritmos de búsqueda son aplicables a una amplia gama de problemas y estructuras de datos. Pueden utilizarse para buscar elementos en arreglos, listas enlazadas, árboles, grafos y otras estructuras comunes de datos

- Eficiencia: Dependiendo del algoritmo de búsqueda utilizado y de la estructura de datos, estos algoritmos pueden ser eficientes y tener una complejidad temporal óptima. Por ejemplo, la búsqueda binaria en un arreglo ordenado tiene una complejidad temporal de O(log n), lo que es altamente eficiente

- Implementación sencilla: La mayoría de los algoritmos de búsqueda son fáciles de entender e implementar. No requieren de lógica compleja ni de estructuras de control elaboradas, lo que facilita su implementación y mantenimiento

### Desventajas

- Necesidad de estructuras ordenadas: Algunos algoritmos de búsqueda, como la búsqueda binaria, requieren que la estructura de datos esté ordenada de antemano. Esto puede requerir un tiempo y esfuerzo adicional para ordenar los datos antes de realizar la búsqueda

- Limitaciones en búsquedas complejas: Algunos problemas pueden requerir búsquedas más complejas que no se pueden resolver de manera eficiente con algoritmos de búsqueda básicos. En tales casos, se pueden requerir técnicas más avanzadas, como la búsqueda en grafos o la búsqueda heurística

- Dependencia del tamaño de los datos: La eficiencia de los algoritmos de búsqueda puede verse afectada por el tamaño de los datos a buscar. En algunos casos, especialmente cuando los datos son extremadamente grandes, pueden ser necesarios enfoques alternativos para realizar búsquedas eficientes

## Ejemplos

### Búsqueda lineal: Es un algoritmo simple que recorre secuencialmente una lista o arreglo de elementos hasta encontrar el elemento buscado. Es adecuado para listas no ordenadas, pero puede ser ineficiente para listas grandes

```c
// int arr[] = {2, 5, 7, 10, 14, 18, 20};
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 10;

int busquedaLineal(int arr[], int n, int target)
{
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == target)
      {
         return i; // Devuelve el índice donde se encontró el elemento
      }
   }
   return -1; // Devuelve -1 si el elemento no se encuentra
}
```

La función `busquedaLineal` recibe un arreglo `arr` de tamaño `n` y un elemento `target` a buscar. La función recorre el arreglo secuencialmente y compara cada elemento con el elemento buscado. Si el elemento buscado se encuentra en el arreglo, la función devuelve el índice donde se encontró. Si el elemento no se encuentra, la función devuelve -1.


### Búsqueda binaria: es un algoritmo eficiente para encontrar un elemento en una lista ordenada. La idea básica detrás de la búsqueda binaria es dividir repetidamente a la mitad la lista de búsqueda y descartar la mitad en la que sabemos que el elemento buscado no puede estar


```c
// int arr[] = {2, 5, 7, 10, 14, 18, 20};
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 10;

int busquedaBinaria(int arr[], int izq, int der, int target)
{
   if (der >= izq)
   {
      int mitad = izq + (der - izq) / 2;

      if (arr[mitad] == target)
      {
         return mitad;
      }

      if (arr[mitad] > target)
      {
         return busquedaBinaria(arr, izq, mitad - 1, target);
      }

      return busquedaBinaria(arr, mitad + 1, der, target);
   }

   return -1; // Elemento no encontrado
}
```

La función `busquedaBinaria` se llama recursivamente para buscar el elemento `target` en una porción del arreglo `arr` definida por los índices  `izq` y `der`. La función divide la porción en dos mitades y decide en qué mitad continuar la búsqueda hasta encontrar el elemento o determinar que no existe.

### Búsqueda por interpolación: es un algoritmo de búsqueda que utiliza interpolación para encontrar un elemento en una lista ordenada. La interpolación es una técnica de estimación que se utiliza para aproximar valores intermedios entre dos puntos de datos. La búsqueda por interpolación es similar a la búsqueda binaria, pero utiliza una fórmula diferente para calcular el punto medio de la lista de búsqueda
 
```c
// int arr[] = {2, 5, 7, 10, 14, 18, 20};
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 10;

int busquedaInterpolacion(int arr[], int n, int target)
{
   int inicio = 0;
   int fin = n - 1;

   while (inicio <= fin && target >= arr[inicio] && target <= arr[fin])
   {
      if (inicio == fin)
      {
         if (arr[inicio] == target)
         {
            return inicio;
         }
         return -1;
      }

      // Cálculo de la posición estimada por interpolación
      int posicion = inicio + ((target - arr[inicio]) * (fin - inicio)) / (arr[fin] - arr[inicio]);

      if (arr[posicion] == target)
      {
         return posicion;
      }

      if (arr[posicion] < target)
      {
         inicio = posicion + 1;
      }
      else
      {
         fin = posicion - 1;
      }
   }

   return -1;
}
```

La función `busquedaInterpolacion` recibe un arreglo `arr` de tamaño `n` y un elemento `target` a buscar. La función inicializa los índices `inicio` y `fin` al principio y al final del arreglo, respectivamente. **Luego, la función calcula la posición estimada del elemento `target` utilizando la fórmula de interpolación.** Si el elemento buscado se encuentra en la posición estimada, la función devuelve el índice donde se encontró. Si el elemento no se encuentra, la función devuelve -1.


### Búsqueda Hash: La búsqueda hash utiliza una función hash para mapear claves a direcciones en una tabla hash

La búsqueda hash utiliza una función hash para mapear claves a direcciones en una tabla hash. La tabla hash es una estructura de datos que almacena claves y valores en una matriz asociativa. La función hash toma una clave como entrada y devuelve una dirección en la tabla hash donde se puede encontrar el valor asociado a esa clave. La búsqueda hash es una forma eficiente de buscar elementos en una tabla hash, pero requiere que la tabla hash se construya de antemano. Hay dos tipos de búsqueda hash: 

1) 


```c
#include <stdio.h>

#define SIZE 10

struct Nodo
{
    int clave;
    int valor;
    struct Nodo *siguiente;
};

void inicializarTabla(struct Nodo *tabla[])
{
    for (int i = 0; i < SIZE; i++)
    {
        tabla[i] = NULL;
    }
}

int funcionHash(int clave)
{
    return clave % SIZE;
}

void insertar(struct Nodo *tabla[], int clave, int valor)
{
    int indice = funcionHash(clave);

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->clave = clave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (tabla[indice] == NULL)
    {
        tabla[indice] = nuevoNodo;
    }
    else
    {
        struct Nodo *actual = tabla[indice];
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

int buscar(struct Nodo *tabla[], int clave)
{
    int indice = funcionHash(clave);

    struct Nodo *actual = tabla[indice];
    while (actual != NULL)
    {
        if (actual->clave == clave)
        {
            return actual->valor;
        }
        actual = actual->siguiente;
    }

    return -1;
}

int main()
{
    struct Nodo *tabla[SIZE];
    inicializarTabla(tabla);

    insertar(tabla, 10, 100);
    insertar(tabla, 20, 200);
    insertar(tabla, 30, 300);

    int resultado = buscar(tabla, 20);
    if (resultado == -1)
    {
        printf("El elemento no se encuentra en la tabla hash.\n");
    }
    else
    {
        printf("El valor asociado a la clave es %d.\n", resultado);
    }

    return 0;
}
```

En este ejemplo, la tabla hash se implementa como una matriz de punteros a nodos. Cada posición contiene una lista ligada para manejar colisiones. Los elementos se insertan al final de la lista en la posición determinada por la función hash.

### Sondeo lineal y sondeo cuadrático:

Cuando se produce una colisión en la búsqueda hash, es decir, cuando dos claves diferentes se asignan a la misma posición en la tabla de hash, es necesario resolverla utilizando técnicas de sondeo. El sondeo lineal y el sondeo cuadrático son dos métodos comunes de resolución de colisiones.

La elección entre el sondeo lineal y el sondeo cuadrático depende de varios factores, como el tamaño de la tabla hash, la distribución de las claves y la carga de la tabla (es decir, la cantidad de elementos almacenados en relación con el tamaño total de la tabla). No hay una respuesta definitiva sobre cuál método es "peor" en todos los casos, ya que cada uno tiene sus propias ventajas y desventajas.

- El sondeo lineal tiende a generar más agrupamiento primario, lo que significa que las colisiones tienden a agruparse y formar clústeres. Esto puede resultar en un fenómeno conocido como "efecto de avalancha" o "efecto de clustering", donde se crean secuencias largas de colisiones consecutivas. Esto puede afectar negativamente el rendimiento de la búsqueda y aumentar la probabilidad de más colisiones en esas secuencias.

- El sondeo cuadrático ayuda a reducir el agrupamiento primario y distribuir las colisiones de manera más uniforme. Esto se debe a que utiliza incrementos cuadráticos para encontrar la siguiente posición disponible en la tabla hash. Sin embargo, el sondeo cuadrático puede generar agrupamiento secundario, donde se forman secuencias de colisiones en posiciones adyacentes. Estos clústeres secundarios también pueden afectar el rendimiento de la búsqueda.

En resumen, tanto el sondeo lineal como el sondeo cuadrático tienen ventajas y desventajas. La elección entre ellos dependerá del contexto y las características del problema en particular. En algunos casos, el sondeo lineal puede ser más rápido y eficiente, mientras que en otros casos, el sondeo cuadrático puede ofrecer una mejor distribución de las colisiones. En general, es recomendable realizar pruebas y análisis empíricos para determinar cuál método es más adecuado para una situación específica.

#### Sondeo lineal: En el sondeo lineal, cuando se produce una colisión, se busca la siguiente posición disponible en la tabla hash de forma lineal, es decir, de uno en uno

```c
posicion = (posicion + 1) % tamaño_tabla
```

Donde `posicion` es la posición actual y `tamaño_tabla` es el tamaño total de la tabla de hash. Es una solución simple y fácil de implementar:


```c
void insertar(struct Nodo *tabla[], int clave, int valor)
{
    int indice = funcionHash(clave);

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->clave = clave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (tabla[indice] == NULL)
    {
        tabla[indice] = nuevoNodo;
    }
    else
    {
        int siguienteIndice = (indice + 1) % SIZE;
        while (tabla[siguienteIndice] != NULL)
        {
            siguienteIndice = (siguienteIndice + 1) % SIZE; //Sondeo lineal para insercción
        }
        tabla[siguienteIndice] = nuevoNodo;
    }
}

int buscar(struct Nodo *tabla[], int clave)
{
    int indice = funcionHash(clave);

    while (tabla[indice] != NULL)
    {
        if (tabla[indice]->clave == clave)
        {
            return tabla[indice]->valor;
        }
        indice = (indice + 1) % SIZE; //Sondeo lineal para búsqueda
    }

    return -1;
}

```

La función `insertar` utiliza el sondeo lineal para insertar un elemento en la tabla hash. Si la posición determinada por la función hash está ocupada, la función busca la siguiente posición disponible en la tabla hash de forma lineal hasta encontrar una posición vacía. La función `buscar` utiliza el sondeo lineal para buscar un elemento en la tabla hash. Si la posición determinada por la función hash está ocupada, la función busca la siguiente posición disponible en la tabla hash de forma lineal hasta encontrar el elemento buscado o determinar que no existe.


#### Sondeo cuadrático: En el sondeo cuadrático, cuando se produce una colisión, se busca la siguiente posición disponible en la tabla hash de forma cuadrática, es decir, aumentando el índice en 1, 4, 9, 16, etc. 

```c
posicion = (posicion + i²) % tamaño_tabla
```

Donde `posicion` es la posición actual, `i` es un contador que aumenta en cada iteración y `tamaño_tabla` es el tamaño total de la tabla de hash:

```c
void insertar(struct Nodo *tabla[], int clave, int valor)
{
    int indice = funcionHash(clave);
    int i = 1;

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->clave = clave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (tabla[indice] == NULL)
    {
        tabla[indice] = nuevoNodo;
    }
    else
    {
        int siguienteIndice = (indice + 1) % SIZE;
        while (tabla[siguienteIndice] != NULL)
        {
            siguienteIndice = (siguienteIndice + i * i) % SIZE;
            i++;
        }
        tabla[siguienteIndice] = nuevoNodo;
    }
}

int buscar(struct Nodo *tabla[], int clave)
{
    int indice = funcionHash(clave);
    int i = 1;

    while (tabla[indice] != NULL)
    {
        if (tabla[indice]->clave == clave)
        {
            return tabla[indice]->valor;
        }
        indice = (indice + i * i) % SIZE;
        i++;
    }

    return -1;
}
```

La función `insertar` utiliza el sondeo lineal para insertar un elemento en la tabla hash. Si la posición determinada por la función hash está ocupada, la función busca la siguiente posición disponible en la tabla hash de forma lineal hasta encontrar una posición vacía. La función `buscar` utiliza el sondeo lineal para buscar un elemento en la tabla hash. Si la posición determinada por la función hash está ocupada, la función busca la siguiente posición disponible en la tabla hash de forma lineal hasta encontrar el elemento buscado o determinar que no existe.

## Conclusión

_Los algoritmos de búsqueda son herramientas poderosas para buscar elementos en estructuras de datos. Aunque tienen algunas limitaciones y requisitos específicos, su versatilidad y eficiencia los convierten en una opción confiable para muchas aplicaciones. Trata de ocupar siempre el que mas se ajuste al problema que quieres resolver_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_