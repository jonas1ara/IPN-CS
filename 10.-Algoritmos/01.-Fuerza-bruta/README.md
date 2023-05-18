# Algoritmos de fuerza bruta

![FuerzaBruta](/01.-Sources/Images/FuerzaBruta.png)

_Representación de la estrategia de fuerza bruta_

## Es un enfoque algoritmico de prueba y error, cuándo se implementa se prueban todas las posibles soluciones

La estrategia algorítmica de fuerza bruta consiste en probar exhaustivamente todas las posibles soluciones para un problema, sin aplicar ningún tipo de optimización o heurística. Este enfoque es útil cuando el tamaño del problema es pequeño o cuando no existen algoritmos más eficientes para resolverlo.

La idea principal detrás de la fuerza bruta es generar todas las combinaciones posibles y evaluar cada una de ellas hasta encontrar la solución correcta. Aunque puede ser efectiva en algunos casos, esta estrategia puede volverse ineficiente rápidamente a medida que el tamaño del problema aumenta, ya que implica probar todas las combinaciones, lo que puede llevar a un alto consumo de tiempo y recursos.

### Ventajas

- Garantía de encontrar la solución óptima: Los algoritmos de fuerza bruta prueban todas las posibles soluciones en busca de la óptima. Esto significa que, si existe una solución, el algoritmo la encontrará, lo que ofrece una garantía de optimalidad

- Simplicidad conceptual: Estos algoritmos suelen ser relativamente fáciles de entender e implementar, ya que no requieren de estrategias complicadas ni heurísticas sofisticadas

- No dependencia de estructuras de datos complejas: Los algoritmos de fuerza bruta no necesitan utilizar estructuras de datos especializadas o algoritmos complicados para su implementación

### Desventajas

- Ineficiencia en tiempo de ejecución: Debido a que prueban todas las combinaciones posibles, los algoritmos de fuerza bruta pueden ser extremadamente ineficientes en términos de tiempo de ejecución

- Consumo de recursos: Los algoritmos de fuerza bruta requieren de una gran cantidad de recursos computacionales, como memoria y capacidad de procesamiento, especialmente cuando el espacio de búsqueda es grande

- No escalabilidad: La eficiencia de los algoritmos de fuerza bruta disminuye rápidamente a medida que aumenta el tamaño del problema. 

## Ejemplos

### Two Sum: dado un array de números enteros y un objetivo, encontrar los índices de los dos números en el array cuya suma sea igual al objetivo.

```c
// int nums[] = {2, 7, 11, 15};
// int target = 9;
// int resultado[2];

void twoSum(int nums[], int n, int target, int* resultado) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                resultado[0] = i;
                resultado[1] = j;
                return;
            }
        }
    }
}
```

En este ejemplo, la función `twoSum` recibe el array de números `nums`, su tamaño `n`, el objetivo `target` y un array `resultado` donde almacenaremos los índices de los dos números que suman el objetivo.

La función utiliza dos bucles `for` anidados para probar todas las combinaciones posibles de números en el array. Comienza con el primer número en el índice `i` y busca el segundo número en el índice`j` (siempre mayor que `i`). Si la suma de estos dos números es igual al objetivo, almacenamos los índices `i` y `j` en el array `resultado` y salimos de la función.

Es importante destacar que esta solución tiene una complejidad temporal de **O(n²)** debido a los bucles anidados, donde n es el tamaño del array `nums`. Si el tamaño del array es muy grande, esta solución puede volverse ineficiente.

### Problema de la mochila: dado un conjunto de elementos, cada uno con un peso y un valor, determinar la combinación de elementos que maximice el valor total mientras se mantiene el peso total dentro de un límite.

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

int mochilaFuerzaBruta(int capacidad, int pesos[], int valores[], int n)
{
    //Caso base
    if (n == 0 || capacidad == 0)
        return 0;

    // Si el peso del objeto actual excede la capacidad, se excluye
    if (pesos[n - 1] > capacidad)
        return mochilaFuerzaBruta(capacidad, pesos, valores, n - 1);

    // Se devuelve el máximo entre incluir el objeto actual y excluirlo
    return max(valores[n - 1] + mochilaFuerzaBruta(capacidad - pesos[n - 1], pesos, valores, n - 1),
               mochilaFuerzaBruta(capacidad, pesos, valores, n - 1));
}
```

En este ejemplo, la función `mochilaFuerzaBruta` implementa el enfoque de fuerza bruta utilizando una función auxiliar recursiva llamada `mochilaRecursiva`. En cada llamada recursiva, se consideran dos opciones: incluir el objeto actual o no incluirlo. Se exploran todas las combinaciones posibles de objetos y se calcula el valor máximo obtenido. El caso base se alcanza cuando se llega al final de los objetos o cuando la capacidad restante es 0.

El valor máximo obtenido se devuelve y se imprime en la función `main`. En este caso de ejemplo, la capacidad de la mochila es 50, y se tienen 3 objetos con sus respectivos pesos y valores. **El valor máximo obtenido es 220, que corresponde a la combinación de los objetos 1 y 3.**

Cabe destacar que la implementación de fuerza bruta es sencilla de entender y codificar, pero puede volverse muy ineficiente para instancias grandes del problema de la mochila debido a la necesidad de probar todas las combinaciones posibles.



## Conclusión

_Usa este enfoque cuando el tamaño de la entrada sea pequeño o no tengas otra opción para resolver el problema_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_