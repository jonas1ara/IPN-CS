# Algoritmos voraces

![Voraces](/01.-Sources/Images/Voraces.png)

_Representación de la estrategia de algoritmos voraces

## Es un enfoque algoritmico que consiste en elegir siempre la opción óptima local en cada paso con la esperanza de obtener una solución óptima global

Los algoritmos voraces, también conocidos como algoritmos ávidos o greedy en inglés, son una estrategia algorítmica que consiste en elegir siempre la opción óptima local en cada paso con la esperanza de obtener una solución óptima global. En otras palabras, se toma la mejor decisión posible en cada momento, sin preocuparse por las consecuencias futuras.

Los algoritmos voraces son útiles cuando se trata de problemas de optimización, donde se busca encontrar la solución más eficiente o efectiva. Sin embargo, no siempre garantizan la solución óptima global, ya que pueden quedarse atrapados en una solución local que no es la mejor a largo plazo.

La estrategia algorítmica de los algoritmos voraces se puede dividir en los siguientes pasos generales:

- Definir el conjunto de posibles soluciones
- Seleccionar la mejor solución local
- Combinar la solución seleccionada con la solución parcial
- Repetir los pasos 2 y 3 hasta que se encuentre la solución global

### Ventajas

- Eficiencia: Suelen ser eficientes en términos de tiempo de ejecución, porque no requieren probar todas las soluciones posibles
- Fácil implementación: Los algoritmos voraces suelen ser relativamente fáciles de entender e implementar en comparación con otros algoritmos más complejos
- Soluciones aproximadas: En muchos casos, los algoritmos voraces proporcionan soluciones aproximadas aceptables en un tiempo razonable

### Desventajas
- No garantizan la optimalidad global: La principal desventaja de los algoritmos voraces es que pueden quedarse atrapados en soluciones subóptimas.
- Falta de retroceso: Los algoritmos voraces no suelen realizar cambios en las decisiones tomadas en pasos anteriores. Esto significa que una elección temprana puede comprometer la solución final
- Sensibilidad a cambios en los datos: Los algoritmos voraces pueden ser sensibles a cambios en los datos de entrada

## Ejemplos

### Conjunto de monedas: dado un conjunto de monedas, encontrar la cantidad mínima de monedas necesarias para formar una cantidad dada.


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