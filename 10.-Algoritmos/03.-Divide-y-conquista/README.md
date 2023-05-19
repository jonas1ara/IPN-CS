# Divide y conquista 

![DyC](/01.-Sources/Images/DyC.png)

_Representación de la estrategia divide y conquista_

## La estrategia algorítmica de "divide y conquista" es una técnica de resolución de problemas que se basa en dividir un problema en subproblemas más pequeños, resolverlos de forma independiente y luego combinar las soluciones para obtener la solución final

La idea central detrás de la estrategia de divide y conquista es descomponer el problema en subproblemas más pequeños y más manejables, resolverlos por separado y luego combinar las soluciones para obtener la solución general del problema original. Esto hace típicamente a través de un enfoque recursivo, donde cada llamada recursiva se aplica a una instancia más pequeña del problema, todo esto hace que esta estrategia sea altamente eficiente en complejidad temporal pero altamente ineficiente en complejidad espacial porque la descomposición del problema en subproblemas más pequeños y la combinación de las soluciones pueden introducir un overhead adicional en términos de memoria

### Ventajas

- Paralelismo: Debido a su naturaleza divisiva, los algoritmos de "Divide y conquista" son adecuados para ser paralelizados. Los subproblemas independientes pueden resolverse en paralelo, aprovechando el poder de procesamiento de sistemas multicore o distribuidos, lo que puede acelerar significativamente la ejecución

- Modularidad: Los algoritmos de "Divide y conquista" se basan en la modularidad y la descomposición del problema en partes más pequeñas. Esto facilita la comprensión, la implementación y el mantenimiento del algoritmo, ya que cada subproblema se puede abordar por separado.

### Desventajas

- Necesidad de un caso base: Los algoritmos de "Divide y conquista" requieren un caso base para detener la recursión y resolver los subproblemas más pequeños directamente. La definición y selección adecuada del caso base puede ser un desafío y, si se elige incorrectamente, puede llevar a resultados incorrectos o ineficientes

- Complejidad de implementación: La implementación de algoritmos de "Divide y conquista" puede ser compleja debido a la necesidad de dividir el problema de manera adecuada, combinar las soluciones y gestionar la recursión. Se requiere un diseño cuidadoso y una comprensión sólida del problema para lograr una implementación correcta y eficiente

- Dependencia de la estructura del problema: La eficacia de los algoritmos de "Divide y conquista" depende en gran medida de la estructura del problema. Si no existe una división clara en subproblemas más pequeños o si la combinación de las soluciones es compleja, la aplicación de esta técnica puede ser difícil, ineficiente o imposible

## Ejemplos

### Merge sort: es un algoritmo de ordenamiento eficiente que utiliza la estrategia de divide y conquista para ordenar una lista de elementos

a) Dividir: La lista se divide en dos mitades de tamaño aproximadamente igual

b) Conquista: Cada mitad se ordena de forma recursiva utilizando Merge Sort

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

### Búsqueda binaria: es un algoritmo eficiente para encontrar un elemento en una lista ordenada

a) Dividir: La lista se divide en dos mitades 

b) Conquista: Se determina en qué mitad puede estar el elemento

c) Combinar: Se repite el proceso en la mitad seleccionada hasta que se encuentra el elemento o determinar que no existe

```c
// int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
// int n = sizeof(arr) / sizeof(arr[0]);
// int target = 12;

// Función de búsqueda binaria
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

## Conclusión

_Los algoritmos de "Divide y conquista" ofrecen ventajas en términos de eficiencia, paralelismo, modularidad y reutilización. Sin embargo, presentan desventajas en términos de memoria y la complejidad de su implementación dependerá de la estructura del problema_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_