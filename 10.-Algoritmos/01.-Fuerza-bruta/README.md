# Algoritmos de fuerza bruta

![FuerzaBruta](/01.-Sources/Images/FuerzaBruta.png)

_Representación de la estrategia de fuerza bruta_

## Es un enfoque algoritmico de prueba y error, cuándo se implementa se prueban todas las posibles soluciones

La estrategia algorítmica de fuerza bruta consiste en probar exhaustivamente todas las posibles soluciones para un problema, sin aplicar ningún tipo de optimización o heurística. Este enfoque es útil cuando el tamaño del problema es pequeño o cuando no existen algoritmos más eficientes para resolverlo.

La idea principal detrás de la fuerza bruta es generar todas las combinaciones posibles y evaluar cada una de ellas hasta encontrar la solución correcta. Aunque puede ser efectiva en algunos casos, esta estrategia puede volverse ineficiente rápidamente a medida que el tamaño del problema aumenta, ya que implica probar todas las combinaciones, lo que puede llevar a un alto consumo de tiempo y recursos.

### Ventajas

- Optienes la mejor solución de todas.
- Siempre encuentra una solución, si se logra implementar.
- Es más fácil de implementar.

### Desventajas
- Este enfoque puede tomar demasiado tiempo(siglos incluso).
- No considera eficiencia.

## Ejemplos

### Encontrar todos los números primos en un rango dado

```c
#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void encontrarPrimos(int rangoInicial, int rangoFinal) {
    printf("Números primos en el rango [%d, %d]:\n", rangoInicial, rangoFinal);
    
    for (int num = rangoInicial; num <= rangoFinal; num++) {
        if (esPrimo(num)) {
            printf("%d ", num);
        }
    }
    
    printf("\n");
}

int main() {
    int rangoInicial, rangoFinal;
    
    printf("Ingrese el rango inicial: ");
    scanf("%d", &rangoInicial);
    
    printf("Ingrese el rango final: ");
    scanf("%d", &rangoFinal);
    
    encontrarPrimos(rangoInicial, rangoFinal);
    
    return 0;
}
```

En este ejemplo, hemos creado una función llamada `esPrimo` que determina si un número dado es primo o no. Esta función realiza una verificación exhaustiva dividiendo el número entre todos los enteros desde 2 hasta la raíz cuadrada del número.

La función `encontrarPrimos` toma un rango inicial y final, y busca todos los números primos dentro de ese rango. Utiliza un bucle `for` para iterar sobre todos los números dentro del rango y llama a la función `esPrimo` para verificar si cada número es primo o no. Si un número es primo, se imprime en la pantalla.

Esta implementación utiliza la **estrategia de fuerza bruta** porque prueba exhaustivamente todos los números en el rango dado para determinar si son primos o no. Si el rango es grande, la ejecución puede llevar mucho tiempo, ya que no se aplican optimizaciones adicionales para reducir el número de pruebas.


### Two Sum: dado un array de números enteros y un objetivo, encontrar los índices de los dos números en el array cuya suma sea igual al objetivo.

```c
#include <stdio.h>

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

int main() 
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int result[2];

    twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, result);

    printf("Indices de los numeros que suman el objetivo: [%d, %d]\n", result[0], result[1]);

    return 0;
}
```

En este ejemplo, la función `twoSum` recibe el array de números `nums`, su tamaño `numsSize`, el objetivo `target` y un array `result` donde almacenaremos los índices de los dos números que suman el objetivo.

La función utiliza dos bucles `for` anidados para probar todas las combinaciones posibles de números en el array. Comienza con el primer número en el índice `i` y busca el segundo número en el índice`j` (siempre mayor que `i`). Si la suma de estos dos números es igual al objetivo, almacenamos los índices `i` y `j` en el array `result` y salimos de la función.

Es importante destacar que esta solución tiene una complejidad temporal de **O(n²)** debido a los bucles anidados, donde n es el tamaño del array `nums`. Si el tamaño del array es muy grande, esta solución puede volverse ineficiente.

## Algoritmos basados en este enfoque:

| # | Titulo | Implementación | Complejidad |
|---| ----- | -------- | ---------- |
|001|Ordenamiento burbuja| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/06.-Ordenamiento/01-Ordenamiento-Burbuja.c) |Ο (n²)|
|002|Problema de las N reinas | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/05.-Backtracking/01-N-Reinas-Geek.c)|Ο (2^n)|
