# Ventana deslizante

![VD](/01.-Sources/Images/VD.png)

_Representación de la estrategia ventana deslizante_

## La estrategia del ventana deslizante (sliding window) es un enfoque algorítmico utilizado en la programación para resolver problemas que involucran subarreglos o subcadenas de una estructura de datos, como un arreglo o una cadena de caracteres

La estrategia del ventana deslizante (sliding window) es un enfoque algorítmico utilizado en la programación para resolver problemas que involucran subarreglos o subcadenas de una estructura de datos, como un arreglo o una cadena de caracteres.

Consiste en mantener una "ventana" de elementos mientras se avanza a través de la estructura de datos, actualizando y ajustando la ventana en cada iteración. Esto permite encontrar soluciones óptimas o realizar cálculos eficientes sin tener que recorrer la estructura de datos completa repetidamente.

El concepto básico del sliding window implica mantener dos índices, uno para el inicio de la ventana y otro para el final de la ventana. A medida que avanzas a través de la estructura de datos, ajustas estos índices para expandir o reducir el tamaño de la ventana según sea necesario. Dependiendo del problema que estés resolviendo, los índices se pueden actualizar de diferentes maneras.

### Ventajas

- Eficiencia: Los algoritmos de ventana deslizante pueden ser muy eficientes, ya que evitan realizar cálculos repetitivos al aprovechar la información previamente calculada. La ventana deslizante permite mantener un estado actualizado y realizar operaciones en tiempo constante, lo que mejora el rendimiento general del algoritmo

- Reducción de la complejidad temporal: Al dividir el problema en subproblemas más pequeños que se solucionan a medida que la ventana se desliza, estos algoritmos pueden reducir la complejidad temporal 

- Espacio adicional limitado: Los algoritmos de ventana deslizante suelen requerir un espacio adicional constante o lineal, dependiendo del tamaño de la ventana deslizante y de las variables auxiliares utilizadas. **Esto los hace adecuados para problemas en los que el espacio adicional es un factor importante a considerar** como podría ser el algoritmo de [Kadane](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)

### Desventajas

- Requisito de una ventana fija: Los algoritmos de ventana deslizante asumen una ventana fija de tamaño predeterminado. No son adecuados para problemas en los que el tamaño de la ventana no es constante o debe ajustarse dinámicamente

- Dificultad en algunos escenarios: Algunos problemas pueden presentar desafíos adicionales al aplicar la técnica de la ventana deslizante. Por ejemplo, si el problema involucra cambios en el tamaño o forma de la ventana, o si requiere restricciones adicionales en la solución, puede ser necesario considerar enfoques alternativos

- Dependencia del orden de los elementos: Los algoritmos de ventana deslizante pueden depender del orden en que se procesan los elementos dentro de la ventana. Esto significa que el orden incorrecto puede llevar a resultados incorrectos o subóptimos

## Ejemplos

### Suma máxima de una subcadena: dado un array de números enteros, encontrar la suma máxima de una subcadena contigua de números en el array.

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



### 

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