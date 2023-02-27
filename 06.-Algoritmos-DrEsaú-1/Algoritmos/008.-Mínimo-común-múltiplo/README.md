#  Mínimo Común Múltiplo (mcm)

_El mínimo común múltiplo (mcm) de dos números enteros *es el número más pequeño que es múltiplo común de ambos números.** Se puede calcular el mcm de dos números utilizando el máximo común divisor (MCD) y la siguiente fórmula:_

**mcm(a, b) = (a x b) / MCD(a, b)**

Es decir, el mcm de dos números enteros a y b es igual al producto de a y b dividido por su máximo común divisor

Por ejemplo, para encontrar el mcm de 12 y 18, primero hay que encontrar su MCD utilizando el algoritmo de Euclides:

```
18 = 12 x 1 + 6
12 = 6 x 2 + 0

El último número diferente de cero es 6, por lo que el MCD de 12 y 18 es 6.
```

Luego, se utiliza la fórmula para calcular el mcm:

**mcm(12, 18) = (12 x 18) / 6 = 36**

Por lo tanto, el mcm de 12 y 18 es 36. Esto significa que 36 es el número más pequeño que es múltiplo tanto de 12 como de 18


