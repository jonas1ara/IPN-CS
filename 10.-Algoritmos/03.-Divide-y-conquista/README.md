# Divide y vencerás 

![DyV](/01.-Sources/Images/DyV.png)

_Representación de la estrategia de fuerza bruta_

## La estrategia algorítmica de "divide y vencerás" es una técnica de resolución de problemas que se basa en dividir un problema en subproblemas más pequeños, resolverlos de forma independiente y luego combinar las soluciones para obtener la solución final

La idea central detrás de la estrategia de divide y vencerás es descomponer el problema en subproblemas más pequeños y más manejables, resolverlos por separado y luego combinar las soluciones para obtener la solución general del problema original. Esto hace típicamente a través de un enfoque recursivo, donde cada llamada recursiva se aplica a una instancia más pequeña del problema, todo esto hace que esta estrategia sea altamente eficiente en complejidad temporal pero altamente ineficiente en complejidad espacial porque la descomposición del problema en subproblemas más pequeños y la combinación de las soluciones pueden introducir un overhead adicional en términos de memoria

### Ventajas

- Paralelismo: Debido a su naturaleza divisiva, los algoritmos de "Divide y vencerás" son adecuados para ser paralelizados. Los subproblemas independientes pueden resolverse en paralelo, aprovechando el poder de procesamiento de sistemas multicore o distribuidos, lo que puede acelerar significativamente la ejecución

- Modularidad: Los algoritmos de "Divide y vencerás" se basan en la modularidad y la descomposición del problema en partes más pequeñas. Esto facilita la comprensión, la implementación y el mantenimiento del algoritmo, ya que cada subproblema se puede abordar por separado.

### Desventajas

- Necesidad de un caso base: Los algoritmos de "Divide y vencerás" requieren un caso base para detener la recursión y resolver los subproblemas más pequeños directamente. La definición y selección adecuada del caso base puede ser un desafío y, si se elige incorrectamente, puede llevar a resultados incorrectos o ineficientes

- Complejidad de implementación: La implementación de algoritmos de "Divide y vencerás" puede ser compleja debido a la necesidad de dividir el problema de manera adecuada, combinar las soluciones y gestionar la recursión. Se requiere un diseño cuidadoso y una comprensión sólida del problema para lograr una implementación correcta y eficiente

- Dependencia de la estructura del problema: La eficacia de los algoritmos de "Divide y vencerás" depende en gran medida de la estructura del problema. Si no existe una división clara en subproblemas más pequeños o si la combinación de las soluciones es compleja, la aplicación de esta técnica puede ser difícil, ineficiente o imposible

## Ejemplos

### Merge sort: es un algoritmo de ordenamiento eficiente que utiliza la estrategia de divide y vencerás para ordenar una lista de elementos

a) Dividir: La lista se divide en dos mitades de tamaño aproximadamente igual

b) Vencer: Cada mitad se ordena de forma recursiva utilizando Merge Sort

c) Combinar: Las dos mitades ordenadas se combinan para formar una lista única y ordenada

```c
// int arr[] = { 12, 11, 13, 5, 6, 7 };
// int n = sizeof(arr) / sizeof(arr[0]);

// Función para combinar dos subarreglos ordenados en uno solo
void merge(int arr[], int izq[], int tamanioIzq, int der[], int tamanioDer)
{
    int i = 0, j = 0, k = 0;

    while (i < tamanioIzq && j < tamanioDer)
    {
        if (izq[i] <= der[j])
        {
            arr[k] = izq[i];
            i++;
        }
        else
        {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < tamanioIzq)
    {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while (j < tamanioDer)
    {
        arr[k] = der[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }

    int mid = n / 2;
    int izq[mid];
    int der[n - mid];

    for (int i = 0; i < mid; i++)
    {
        izq[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        der[i - mid] = arr[i];
    }

    mergeSort(izq, mid);
    mergeSort(der, n - mid);
    merge(arr, izq, mid, der, n - mid);
}
```

En el ejemplo anterior, la función `mergeSort` se llama recursivamente para las dos mitades del arreglo `arr`. Después de que las dos mitades se ordenan de forma recursiva, la función `merge` se utiliza para combinar las mitades ordenadas en un único arreglo ordenado.

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

_Los algoritmos de "Divide y vencerás" ofrecen ventajas en términos de eficiencia, paralelismo, modularidad y reutilización. Sin embargo, presentan desventajas en términos de memoria y la complejidad de su implementación dependerá de la estructura del problema_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_