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

### Suma máxima de un subarreglo: dado un arreglo de enteros, encontrar la suma máxima de un subarreglo de tamaño k - O(n)

```c
// int arr[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
//  int n = sizeof(arr) / sizeof(arr[0]);
//  int k = 3;

int sumaMaxSubarreglo(int arr[], int n, int k)
{
    int sumaMax = 0;
    int sumaActual = 0;

    // Calcular la suma de los primeros k elementos
    for (int i = 0; i < k; i++)
        sumaActual += arr[i];

    sumaMax = sumaActual;

    // Calcular la suma de las subcadenas restantes deslizando la ventana
    for (int i = k; i < n; i++)
    {
        sumaActual += arr[i] - arr[i - k]; // Agregar el elemento más reciente y restar el elemento más antiguo
        if (sumaActual > sumaMax)
            sumaMax = sumaActual;
    }

    return sumaMax;
}
```

En este ejemplo, se encuentra la suma máxima de una subcadena de longitud fija `k` en un arreglo dado. La ventana se desliza de izquierda a derecha a medida que se actualiza la suma actual `sumaActual` sumando el elemento más reciente y restando el elemento más antiguo. El algoritmo mantiene el rastro de la suma máxima encontrada `sumaMax` y lo actualiza si se encuentra una suma mayor. El algoritmo devuelve la suma máxima encontrada después de que la ventana se deslice a través de la matriz.


### Subcadena más larga sin caracteres repetidos: dado un string, encontrar la longitud de la subcadena más larga sin caracteres repetidos - O(n)

```c
// char str[] = "abcabcbb";

int subcadenaMasLarga(char *str)
{
    int n = strlen(str);
    int longitudMax = 0;
    int inicio = 0;
    int final = 0;

    int contadorCaracteres[256] = {0}; // Inicializar el contador de caracteres

    while (final < n)
    {
        char caracterActual = str[final];

        if (contadorCaracteres[caracterActual] == 0)
        {
            contadorCaracteres[caracterActual]++;
            final++;
            int currentLength = final - inicio;
            if (currentLength > longitudMax)
                longitudMax = currentLength;
        }
        else
        {
            contadorCaracteres[str[inicio]]--;
            inicio++;
        }
    }

    return longitudMax;
}
```

En este ejemplo, se busca encontrar la longitud de la subcadena más larga en una cadena de caracteres sin caracteres repetidos. El algoritmo utiliza una ventana deslizante para rastrear el `inicio` y el `final` de la subcadena actual sin caracteres repetidos. El arreglo `contadorCaracteres` se utiliza para mantener un registro del recuento de cada carácter en la ventana actual. Si se encuentra un carácter repetido, se mueve el inicio de la ventana hacia adelante y se actualiza el recuento de caracteres. El algoritmo mantiene un registro de la longitud máxima de la subcadena sin caracteres repetidos encontrada hasta ahora y la actualiza si se encuentra una subcadena más larga.



## Conclusión

_La clave es identificar cómo ajustar los índices de inicio y fin de la ventana, así como realizar un seguimiento de la información relevante dentro de la ventana para llegar a la solución deseada_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_