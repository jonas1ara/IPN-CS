# Algoritmos de fuerza bruta

![PD](/01.-Sources/Images/PD.png)

_Representación de la estrategia de programación dinámica_

## Es un enfoque algorítmico para resolver problemas complejos dividiéndolos en subproblemas más pequeños y resolviéndolos de manera recursiva.

Es un enfoque algorítmico para resolver problemas complejos dividiéndolos en subproblemas más pequeños y resolviéndolos de manera recursiva. La estrategia básica de programación dinámica consiste en almacenar los resultados de los subproblemas en una estructura de datos, como una tabla o un arreglo, para evitar recalcularlos varias veces.

Hay dos enfoques comunes en programación dinámica: la **tabulación** y la **memoización**.



### Ventajas

- Eficiencia: Los algoritmos de programación dinámica suelen ser eficientes en términos de tiempo de ejecución. Al evitar recalcular subproblemas ya resueltos y aprovechar los resultados almacenados

- Optimalidad: Los algoritmos de programación dinámica garantizan la obtención de la solución óptima al problema. Al resolver y combinar subproblemas de manera óptima, se construye la solución global óptima

- Reducción del espacio de búsqueda: Mediante el almacenamiento de los resultados intermedios, los algoritmos de programación dinámica reducen el espacio de búsqueda, evitando la necesidad de recalcular los mismos subproblemas una y otra vez

### Desventajas
- Complejidad de implementación: La implementación correcta de los algoritmos de programación dinámica puede ser compleja y requiere un enfoque cuidadoso. Es necesario identificar correctamente los subproblemas, definir la relación de recursividad y diseñar la estructura de almacenamiento adecuada para los resultados intermedios

- Espacio adicional requerido: Los algoritmos de programación dinámica pueden requerir un espacio adicional para almacenar los resultados intermedios

- Limitaciones en problemas con dependencias secuenciales: Algunos problemas con dependencias secuenciales, como problemas de planificación o problemas con restricciones temporales, pueden ser más difíciles de modelar y resolver utilizando algoritmos de programación dinámica. En estos casos, pueden requerirse enfoques alternativos


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

_Usa este enfoque cuando el tamaño de la entrada sea pequeño o tengamos que obtener la mejor solución posible y ninguna otra estrategia sea más eficiente_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_