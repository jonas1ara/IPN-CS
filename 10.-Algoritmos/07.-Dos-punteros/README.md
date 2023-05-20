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

### Encontrar todos los números primos en un rango dado

```c
// rangoInicial = dado por el usuario
// rangoFinal = dado por el usuario

void encontrarPrimos(int rangoInicial, int rangoFinal) 
{
    printf("Números primos en el rango [%d, %d]:\n", rangoInicial, rangoFinal);
    
    for (int num = rangoInicial; num <= rangoFinal; num++) 
    {
        if (esPrimo(num)) 
        {
            printf("%d ", num);
        }
    }
    
    printf("\n");
}

int esPrimo(int num) 
{
    if (num <= 1) 
    {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            return 0;
        }
    }
    
    return 1;
}
```

En este ejemplo, hemos creado una función llamada `esPrimo` que determina si un número dado es primo o no. Esta función realiza una verificación exhaustiva dividiendo el número entre todos los enteros desde 2 hasta la raíz cuadrada del número.

La función `encontrarPrimos` toma un rango inicial y final, y busca todos los números primos dentro de ese rango. Utiliza un bucle `for` para iterar sobre todos los números dentro del rango y llama a la función `esPrimo` para verificar si cada número es primo o no. Si un número es primo, se imprime en la pantalla.

Esta implementación utiliza la **estrategia de fuerza bruta** porque prueba exhaustivamente todos los números en el rango dado para determinar si son primos o no. Si el rango es grande, la ejecución puede llevar mucho tiempo, ya que no se aplican optimizaciones adicionales para reducir el número de pruebas.


### Two Sum: dado un array de números enteros y un objetivo, encontrar los índices de los dos números en el array cuya suma sea igual al objetivo.

```c
// int nums[] = {2, 7, 11, 15};
// int target = 9;
// int result[2];

void twoSum(int nums[], int numsSize, int target, int* result) 
{
    for (int i = 0; i < numsSize; i++) 
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}
```

En este ejemplo, la función `twoSum` recibe el array de números `nums`, su tamaño `numsSize`, el objetivo `target` y un array `result` donde almacenaremos los índices de los dos números que suman el objetivo.

La función utiliza dos bucles `for` anidados para probar todas las combinaciones posibles de números en el array. Comienza con el primer número en el índice `i` y busca el segundo número en el índice`j` (siempre mayor que `i`). Si la suma de estos dos números es igual al objetivo, almacenamos los índices `i` y `j` en el array `result` y salimos de la función.

Es importante destacar que esta solución tiene una complejidad temporal de **O(n²)** debido a los bucles anidados, donde n es el tamaño del array `nums`. Si el tamaño del array es muy grande, esta solución puede volverse ineficiente.

## Conclusión

_Esta estrategia nos ofrece ventajas en términos de eficiencia, uso limitado de espacio adicional, flexibilidad y simplicidad de implementación. Sin embargo, pueden tener limitaciones en problemas complejos, depender de la estructura de datos y no ser aplicables a todos los problemas. Es importante evaluar cuidadosamente el problema en cuestión y considerar si esta estrategia es la mejor opción para abordarlo_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_