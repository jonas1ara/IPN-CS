# Matemáticas básicas

![](./Sources/Images/MB.png)

_Implementaciones básicas de matemáticas en C, son las bases que te servirán y te harán avanzar para usarla con análisis numérico o algoritmos más avanzados, **en este README voy a explicar el álgebra lineal y su implementación básica en C_

## Álgebra lineal

El álgebra lineal es una rama de las matemáticas que se enfoca en el estudio de los espacios vectoriales, las transformaciones lineales, y los sistemas de ecuaciones lineales. Esta rama de las matemáticas utiliza herramientas matemáticas para describir y analizar objetos y fenómenos que pueden ser representados mediante vectores y matrices

## ¿Qué es un sistema de ecuaciones lineales?

Un sistema de ecuaciones lineales es un conjunto de ecuaciones lineales que tienen la misma variable. Por ejemplo, el sistema de ecuaciones lineales:

![](./Sources/Images/SistemaEcuaciones.png)

_Sistema de ecuaciones lineales en álgebra lineal_

Sistema de ecuaciones lineales en C, es un conjunto de ecuaciones lineales que tienen la misma variable. Por ejemplo, el sistema de ecuaciones lineales:

![](./Sources/Images/SistemaEcuacionesC.png)

## ¿Qué es una vector?

Un vector es una magnitud que tiene una dirección y un sentido. En el álgebra lineal, un vector es una lista de números, llamados sus componentes. Los vectores se representan con letras mayúsculas, como `A`, `B`, `C`, etc. Los vectores se pueden representar gráficamente como flechas, donde la longitud de la flecha es la magnitud del vector y la dirección de la flecha es la dirección del vector.

![](./Sources/Images/Vector.png)

_Vector en álgebra lineal_

Vector en C, es un arreglo de números, donde cada número es una componente del vector. Por ejemplo, el vector `A = (1, 2, 3)` se puede representar como un arreglo de tres números:

![](./Sources/Images/VectorC.png)

_Vector implementado en el lenguaje C_

## ¿Qué es una matriz?

Una matriz es una tabla rectangular de números, llamados sus elementos. Las matrices se representan con letras mayúsculas, como `A`, `B`, `C`, etc. Las matrices se pueden representar gráficamente como tablas de números, donde cada número es un elemento de la matriz.

![](./Sources/Images/Matriz.png)

_Matriz en álgebra lineal_

Matriz en C, es un arreglo de vectores, donde cada vector es una fila de la matriz. Por ejemplo, la matriz `A = (1, 2, 3), (4, 5, 6), (7, 8, 9)` se puede representar como un arreglo de tres vectores:

![](./Sources/Images/MatrizC.png)

_Matriz implementada en el lenguaje C_

## ¿Qué es un escalar?

Un escalar es un número real. En el álgebra lineal, un escalar es un número real que se multiplica por un vector o una matriz. Los escalares se representan con letras minúsculas, como `a`, `b`, `c`, etc.

![](./Sources/Images/Escalar.png)

_Escalar en álgebra lineal_

Escalar en C, es un número real que se multiplica por un vector o una matriz. Los escalares se representan con letras minúsculas, como `a`, `b`, `c`, etc.

![](./Sources/Images/EscalarC.png)

### Operaciones con matrices

#### Suma de matrices

La suma de dos matrices `A` y `B` se denota como `A + B` y se define como:

![](./Sources/Images/Suma.png)

_Suma de matrices en álgebra lineal_

Suma de matrices en C, es la suma de dos matrices `A` y `B` se denota como `A + B` y se define como:

![](./Sources/Images/SumaC.png)

_Suma de matrices implementada en el lenguaje C_

#### Resta de matrices

La resta de dos matrices `A` y `B` se denota como `A - B` y se define como:

![](./Sources/Images/Resta.png)

_Resta de matrices en álgebra lineal_

Resta de matrices en C, es la resta de dos matrices `A` y `B` se denota como `A - B` y se define como:

![](./Sources/Images/RestaC.png)

_Resta de matrices implementada en el lenguaje C_

#### Multiplicación de matrices

La multiplicación de dos matrices `A` y `B` se denota como `A * B` y se define como:

![](./Sources/Images/Multiplicacion.png)

_Multiplicación de matrices en álgebra lineal_

Multiplicación de matrices en C, es la multiplicación de dos matrices `A` y `B` se denota como `A * B` y se define como:

![](./Sources/Images/MultiplicacionC.png)

_Multiplicación de matrices implementada en el lenguaje C_

#### Multiplicación de una matriz por un escalar

La multiplicación de una matriz `A` por un escalar `k` se denota como `k * A` y se define como:

![](./Sources/Images/MultiplicacionEscalar.png)

_Multiplicación de una matriz por un escalar en álgebra lineal_

Multiplicación de una matriz por un escalar en C, es la multiplicación de una matriz `A` por un escalar `k` se denota como `k * A` y se define como:

![](./Sources/Images/MultiplicacionEscalarC.png)


### Tipos de matrices

#### ¿Qué es una matriz identidad?

Una matriz identidad es una matriz cuadrada que tiene unos en la diagonal principal y ceros en todas las demás entradas. La matriz identidad se representa con la letra `I` y tiene el mismo número de filas y columnas. Por ejemplo, la matriz identidad de 3 × 3 se representa como `I3` y se define como:

![](./Sources/Images/Identidad.png)

_Matriz identidad en álgebra lineal_

Matriz identidad en C, es una matriz cuadrada que tiene unos en la diagonal principal y ceros en todas las demás entradas. La matriz identidad se representa con la letra `I` y tiene el mismo número de filas y columnas. Por ejemplo, la matriz identidad de 3 × 3 se representa como `I3` y se define como:

![](./Sources/Images/IdentidadC.png)

_Matriz identidad implementada en el lenguaje C_

#### ¿Qué es una matriz transpuesta?

Una matriz transpuesta es una matriz que se obtiene de otra matriz cambiando sus filas por columnas. La matriz transpuesta de una matriz `A` se denota como `A^T` y se define como:

![](./Sources/Images/Transpuesta.png)

_Matriz transpuesta en álgebra lineal_

Matriz transpuesta en C, es una matriz que se obtiene de otra matriz cambiando sus filas por columnas. La matriz transpuesta de una matriz `A` se denota como `A^T` y se define como:

![](./Sources/Images/TranspuestaC.png)

#### ¿Qué es una matriz inversa?

Una matriz inversa es una matriz que, cuando se multiplica por otra matriz, produce la matriz identidad. La matriz inversa de una matriz `A` se denota como `A^-1` y se define como:

![](./Sources/Images/Inversa.png)

_Matriz inversa en álgebra lineal_

Matriz inversa en C, es una matriz que, cuando se multiplica por otra matriz, produce la matriz identidad. La matriz inversa de una matriz `A` se denota como `A^-1` y se define como:

![](./Sources/Images/InversaC.png)
















