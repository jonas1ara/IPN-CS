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
//  int monedas[] = {1, 5, 10, 25};
//  int n = sizeof(monedas) / sizeof(monedas[0]);
//  int cantidad = 47;

void cambioMoneda(int monedas[], int n, int cantidad) 
{
   int i, contador = 0;

   for (i = n - 1; i >= 0; i--) 
   {
        while (cantidad >= monedas[i  ]) 
        {
            cantidad -= monedas[i];
            printf("%d ", monedas[i]);
            contador++;
        }
    }
   printf("\nMonedas totales: %d\n", contador);
}
```

En este ejemplo, la función `cambioMoneda` toma un arreglo de monedas `monedas`, el número de monedas `n` y la cantidad a cambiar `cantidad`. El objetivo es encontrar la combinación más pequeña de monedas que sume la cantidad dada.

El algoritmo voraz utilizado aquí es simple: elegir la moneda más grande posible en cada paso, comenzando con la más grande y avanzando hacia la más pequeña. Esto se logra mediante un bucle while que resta la moneda más grande posible de la cantidad y la imprime en la pantalla.


### Problema de la mochila: dado un conjunto de elementos, cada uno con un peso y un valor, determinar la combinación de elementos que maximice el valor total mientras se mantiene el peso total dentro de un límite.

```c
//  int capacidad = 50;
//  int pesos[] = {10, 20, 30};
//  int valores[] = {60, 100, 120};
//  int n = sizeof(valores) / sizeof(valores[0]);

int mochilaVoraz(int capacidad, int pesos[], int valores[], int n)
{
    // Cálculo del valor por unidad de peso de cada objeto
    int valoresPorPeso[n];
    int i;
    for (i = 0; i < n; i++)
    {
        valoresPorPeso[i] = valores[i] / pesos[i];
    }

    // Ordenar los objetos en orden descendente según su valor por unidad de peso
    for (i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (valoresPorPeso[j] > valoresPorPeso[maxIndex])
            {
                maxIndex = j;
            }
        }
        
        // Intercambiar los valores por unidad de peso y los arreglos correspondientes
        int tempValorPorPeso = valoresPorPeso[maxIndex];
        valoresPorPeso[maxIndex] = valoresPorPeso[i];
        valoresPorPeso[i] = tempValorPorPeso;

        int tempPeso = pesos[maxIndex];
        pesos[maxIndex] = pesos[i];
        pesos[i] = tempPeso;

        int tempValor = valores[maxIndex];
        valores[maxIndex] = valores[i];
        valores[i] = tempValor;
    }

    // Llenar la mochila
    int valorMaximo = 0;
    int pesoActual = 0;
    i = 0;
    while (pesoActual < capacidad && i < n)
    {
        if (pesoActual + pesos[i] <= capacidad)
        {
            pesoActual += pesos[i];
            valorMaximo += valores[i];
        }
        else
        {
            int pesoRestante = capacidad - pesoActual;
            valorMaximo += valoresPorPeso[i] * pesoRestante;
            pesoActual = capacidad;
        }
        i++;
    }

    return valorMaximo;
}
```

En este ejemplo, la función `mochilaVoraz` implementa el enfoque voraz para resolver el problema de la mochila. Primero, se calcula el valor por unidad de peso de cada objeto y se almacena en el arreglo `valoresPorPeso`. Luego, se ordenan los objetos en orden descendente según su valor por unidad de peso.

A continuación, se realiza el llenado de la mochila seleccionando los objetos en orden de su valor por unidad de peso, siempre que no exceda la capacidad de la mochila. Si el objeto no puede ser completamente incluido, se calcula la fracción correspondiente al peso restante y se agrega al valor máximo.

En la función `main`, se definen los datos de ejemplo, incluyendo la capacidad de la mochila, los pesos y valores de los objetos. Se llama a la función `mochilaVoraz` y se imprime el valor máximo obtenido.

Es importante tener en cuenta que este enfoque voraz no garantiza obtener la solución óptima en todos los casos, pero en muchos casos proporciona soluciones aproximadas eficientes. 

## Conclusión

_Usa este enfoque cuando el tamaño de la entrada sea pequeño o tengamos que obtener la mejor solución posible y ninguna otra estrategia sea más eficiente_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_