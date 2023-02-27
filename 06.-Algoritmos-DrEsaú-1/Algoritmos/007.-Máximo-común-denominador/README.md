# El Algoritmo de Euclides

![alt text](/00.-Sources/Images/E.jpeg)

_**Euclides viendo cómo la cagaste al elegir la carrera**_

El algoritmo de Euclides es un método para calcular el máximo común divisor (MCD) de dos números enteros. **El MCD es el número más grande que divide a ambos números sin dejar un resto.** Este algoritmo se basa en la observación de que si el MCD de dos números a y b existe, entonces el MCD de a y b también es igual al MCD de b y el resto de a dividido entre b. A continuación, se explica el procedimiento:

1. Se toman los dos números enteros a y b para los que se desea encontrar el MCD

2. Si b es igual a cero, entonces el MCD es a

3. Si b no es igual a cero, entonces se realiza la división entera de a entre b para obtener el resto r, esto se puede expresar como a = bq + r, donde q es el cociente entero de a dividido por b

4. Se toma el MCD de b y r

5. El resultado del MCD es el resultado final de la función


_En resumen, el algoritmo de Euclides se basa en la división sucesiva de a y b hasta encontrar un par de números en el que uno sea cero. El MCD es el último número diferente de cero en esta secuencia_

Por ejemplo, para encontrar el MCD de 40 y 24 utilizando el algoritmo de Euclides, el proceso sería el siguiente:

```
40 = 24 x 1 + 16
24 = 16 x 1 + 8
16 = 8 x 2 + 0
```

El último número diferente de cero es 8, por lo que el MCD de 40 y 24 es 8

_El algoritmo de Euclides **es un método eficiente y fácil de entender para encontrar el MCD de dos números enteros**, y tiene aplicaciones en matemáticas, ciencias y programación_
