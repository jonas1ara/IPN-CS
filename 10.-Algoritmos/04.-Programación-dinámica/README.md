# Programación dinámica

![PD](/01.-Sources/Images/PD.png)

_Representación de la estrategia programación dinámica_

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

### Fibonacci por tabulación

El problema de Fibonacci es un clásico ejemplo para ilustrar programación dinámica. La serie de Fibonacci se define de la siguiente manera: el valor de un número en la serie es igual a la suma de los dos números anteriores. Por ejemplo, los primeros números de Fibonacci son: 0, 1, 1, 2, 3, 5, 8, ...

**Para resolver el problema de Fibonacci por tabulación, se utiliza una tabla para almacenar los valores de Fibonacci ya calculados**

```c
// n = 10

int fibT(int n)
{
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}   
```

En este código, se utiliza un arreglo `fibT` para almacenar los valores de Fibonacci ya calculados. Se comienza con los casos base  `fib[0] = 0` y `fib[1] = 1`. Luego, se itera desde `i = 2` hasta `n`, calculando el valor de `fib[i]` sumando los dos números anteriores. Al final, se devuelve `fib[n]`, que es el término de Fibonacci deseado.

### Fibonacci por memoización

El problema de Fibonacci es un clásico ejemplo para ilustrar programación dinámica. La serie de Fibonacci se define de la siguiente manera: el valor de un número en la serie es igual a la suma de los dos números anteriores. Por ejemplo, los primeros números de Fibonacci son: 0, 1, 1, 2, 3, 5, 8, ...

**En la memoización, se utiliza una tabla para almacenar los resultados de los subproblemas ya resueltos, evitando así recalcularlos en llamadas posteriores**

```c
// n = 10

#define MAX 100
int fib[MAX];

int fibM(int n)
{
    if (fib[n] != -1)
    {
        return fib[n];
    }

    if (n <= 1)
    {
        fib[n] = n;
    }
    else
    {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return fib[n];
}
```

En este código, se utiliza un arreglo `fib` para almacenar los valores de Fibonacci ya calculados. Al inicio, se inicializa todo el arreglo con el valor -1 para indicar que los valores aún no han sido calculados. La función `fibM` verifica si `fib[n]` ya ha sido calculado, en cuyo caso lo devuelve. Si no ha sido calculado, se verifica si `n` es un caso base (0 o 1) y se almacena directamente. Si no es un caso base, se calcula recursivamente sumando los dos números anteriores y se almacena en `fib[n]`.

### Problema de la mochila: dado un conjunto de elementos, cada uno con un peso y un valor, determinar la combinación de elementos que maximice el valor total mientras se mantiene el peso total dentro de un límite


```c
//  int capacidad = 50;
//  int pesos[] = {10, 20, 30};
//  int valores[] = {60, 100, 120};
//  int n = sizeof(valores) / sizeof(valores[0]);

// Función para calcular el máximo de dos números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Función para resolver el problema de la mochila mediante programación dinámica
int mochilaDinamica(int capacidad, int pesos[], int valores[], int n)
{
    int tabla[n + 1][capacidad + 1];

    // Se construye la tabla de programación dinámica
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacidad; w++)
        {
            if (i == 0 || w == 0)
                tabla[i][w] = 0;
            else if (pesos[i - 1] <= w)
                tabla[i][w] = max(valores[i - 1] + tabla[i - 1][w - pesos[i - 1]], tabla[i - 1][w]);
            else
                tabla[i][w] = tabla[i - 1][w];
        }
    }

    return tabla[n][capacidad];
}
```

En este ejemplo, la función  `mochilaDinamica` recibe la capacidad de la mochila, los pesos y valores de los objetos, y el número total de objetos. Dentro de la función, se crea una tabla bidimensional llamada `tabla` con dimensiones `(n+1) x (capacidad+1)`. Esta tabla se utilizará para almacenar los valores óptimos de subproblemas más pequeños. 

A continuación, se inicia un bucle doble para construir la tabla de programación dinámica. **El primer bucle itera sobre los objetos, mientras que el segundo bucle itera sobre las capacidades desde 0 hasta la capacidad máxima.**

Dentro del bucle, se inicializa la primera fila y la primera columna de la tabla con ceros, ya que si no hay objetos o la capacidad es cero, el valor máximo obtenido siempre será cero.

Luego, se procede a llenar la tabla calculando los valores óptimos de los subproblemas. Para cada objeto y capacidad, se verifica si el objeto actual puede ser incluido en la mochila sin exceder la capacidad. Si es posible, se considera la opción de incluir el objeto actual y se suma su valor al valor obtenido de la tabla en la fila anterior y con capacidad reducida. Si no es posible incluir el objeto actual, se toma el valor de la tabla en la fila anterior para la misma capacidad.

Una vez que se completa el bucle, el valor máximo obtenido se encuentra en la celda `tabla[n][capacidad]` y  la función `mochilaDinamica` devuelve el valor máximo obtenido.


## Conclusión

_Los algoritmos de programación dinámica son eficientes, garantizan la obtención de la solución óptima y reducen el espacio de búsqueda. Sin embargo, pueden ser complejos de implementar, requieren espacio adicional, dependen del solapamiento de subproblemas_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_