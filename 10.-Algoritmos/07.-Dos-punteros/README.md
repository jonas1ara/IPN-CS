# Dos punteros

![DP](/01.-Sources/Images/DP.png)

_Representación de la estrategia de dos punteros_

## Esta estrategia utiliza dos punteros que se mueven a través de la lista o array para encontrar una solución en tiempo lineal

La estrategia algorítmica de "Dos punteros" (Two pointers) es una técnica utilizada en algoritmos para resolver problemas que involucran listas o arrays ordenados. Esta estrategia utiliza dos punteros que se mueven a través de la lista o array para encontrar una **solución en tiempo lineal**. Los dos punteros se mueven simultáneamente a través de la lista o array con diferentes velocidades o en diferentes direcciones, y se utilizan para encontrar un patrón o propiedad en la lista o array.

Los algoritmos de "Dos punteros" se pueden aplicar a una amplia variedad de problemas, como encontrar pares que sumen un objetivo, determinar la existencia de una secuencia o patrón en un arreglo, eliminar duplicados en una lista, entre otros. Esta flexibilidad los hace útiles en diferentes dominios y escenarios.

Para implementar esta estrategia en C, generalmente se usan dos índices (enteros) que apuntan a diferentes elementos de la lista o array. Estos índices se incrementan o disminuyen en función de las condiciones del problema que se está resolviendo.

La complejidad asintótica de la estrategia "Dos punteros" depende del problema que se está resolviendo, pero generalmente se encuentra entre O(N) y O(N log N), donde N es el tamaño de la lista o array.

### Ventajas

- Eficiencia: Los algoritmos de Two Pointers pueden ser muy eficientes, ya que evitan la necesidad de realizar múltiples pasadas sobre los datos

- Espacio adicional limitado: Los algoritmos de Two Pointers suelen requerir un espacio adicional constante o lineal, dependiendo de la cantidad de punteros utilizados y las variables auxiliares requeridas. **Esto los hace adecuados para problemas en los que el espacio adicional es un factor importante a considerar** como el algoritmo de [ordenamiento de burbuja](www.geeksforgeeks.org/bubble-sort/)


- Simplicidad de implementación: En comparación con otros enfoques más complejos, los algoritmos de Two Pointers suelen tener una implementación más simple y comprensible. La idea de utilizar dos punteros que avanzan a través de los datos es intuitiva y fácil de seguir, lo que facilita su implementación y depuración


### Desventajas

- Limitaciones en problemas complejos: Aunque los algoritmos de "Dos punteros" son eficientes en muchos casos, pueden tener limitaciones en **problemas más complejos**

- Dependencia de la estructura de datos: La efectividad de los algoritmos de "Dos punteros" depende en gran medida de la estructura de datos subyacente y de cómo se pueden recorrer o comparar los elementos. En algunos casos, puede ser necesario adaptar o ajustar el enfoque para adaptarse a la estructura de datos específica

- No aplicable a todos los problemas: Aunque los algoritmos de "Dos punteros" son versátiles, no son aplicables a todos los problemas

## Ejemplos

### Encontrar Par: Buscar un par de elementos en una lista ordenada que suman un número específico - O(n)

```c
// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 11; 

void encontrarPar(int arr[], int n, int target)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            printf("Par encontrado: (%d, %d)\n", arr[i], arr[j]);
            return;
        }
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }
    printf("No se encontró ningún par\n");
}
```

En este ejemplo, la función `encontrarPar` recibe el arreglo `arr`, su tamaño `n` y la suma objetivo `target`. La función busca un par de elementos en el arreglo que sumen `target`. Si se encuentra un par, se muestra en la consola. Si no se encuentra ningún par, se muestra un mensaje indicando que no se encontró ningún par.


### Encontrar la subsecuencia más larga: Encontrar la subsecuencia más larga de números consecutivos que suman una cantidad específica de una lista desordenada - O(n)

```c
// int arr[] = {2, 1, 5, 1, 3, 2};
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 8; 

int encontrarSubsecuencia(int arr[], int n, int target)
{
    int i = 0, j = 0, suma = 0, longitud_max = 0;
    while (j < n)
    {
        suma += arr[j];
        while (suma > target)
        {
            suma -= arr[i];
            i++;
        }
        if (suma == target && (j - i + 1) > longitud_max)
        {
            longitud_max = j - i + 1;
        }
        j++;
    }
    return longitud_max;
}
```
En este ejemplo, la función `encontrarSubsecuencia` recibe el arreglo `arr`, su tamaño `n` y la suma objetivo `target`. La función encuentra la subsecuencia más larga de números consecutivos en el arreglo que suman `target` y devuelve su longitud. Si no se encuentra ninguna subsecuencia, devuelve 0.

## Conclusión

_Esta estrategia nos ofrece ventajas en términos de eficiencia, uso limitado de espacio adicional, flexibilidad y simplicidad de implementación. Sin embargo, pueden tener limitaciones en problemas complejos, depender de la estructura de datos y no ser aplicables a todos los problemas. Es importante evaluar cuidadosamente el problema en cuestión y considerar si esta estrategia es la mejor opción para abordarlo_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_