# Matemáticas básicas

_Implementaciones básicas de matemáticas en C, son las bases que te servirán y te harán avanzar para usarla con análisis numérico o algoritmos más avanzados, **en este README voy a explicar el álgebra lineal y su implementación básica en C**_

## Álgebra lineal

![](/00.-Sources/Images/AL.jpg)

El álgebra lineal es una rama de las matemáticas que se enfoca en el estudio de los espacios vectoriales, las transformaciones lineales, y los sistemas de ecuaciones lineales. Esta rama de las matemáticas utiliza herramientas matemáticas para describir y analizar objetos y fenómenos que pueden ser representados mediante vectores y matrices

## Sistema de ecuaciones lineales; la base del álgebra lineal

Un sistema de ecuaciones lineales es un conjunto de ecuaciones lineales que tienen la misma variable. Por ejemplo, el sistema de ecuaciones lineales:

![](/00.-Sources/Images/SEL.jpg)

_Sistema de ecuaciones lineales en álgebra lineal_

## Vector; el corazón del álgebra lineal

Un vector es una magnitud que tiene una dirección y un sentido. En el álgebra lineal, un vector es una lista de números, llamados sus componentes. Los vectores se representan con letras mayúsculas, como `A`, `V`, etc. Los vectores se pueden representar gráficamente como flechas, donde la longitud de la flecha es la magnitud del vector y la dirección de la flecha es la dirección del vector.

![](/00.-Sources/Images/Vector.png)

_Vector en álgebra lineal_

Vector en C, es un arreglo de números, donde cada número es una componente del vector. Por ejemplo, el vector V se puede implementar en C de la siguiente manera; `vector[] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)` se puede representar como un arreglo de 10 números:

![](/00.-Sources/Images/VectorC.png)

_Vector implementado en el lenguaje C_

## Matriz; la esencia del álgebra lineal

Una matriz es una tabla rectangular de números, llamados sus elementos. Las matrices se representan con letras mayúsculas, como `A`, `B`, `C`, etc. Y con la minuscula n para indicar el número de filas y m para indicar el número de columnas. Por ejemplo, la matriz `A = (1, 2, 3), (4, 5, 6), (7, 8, 9)` se puede representar como una tabla de tres filas y tres columnas:

![](/00.-Sources/Images/Matriz.png)

_Matriz en álgebra lineal_

Matriz en C, es un arreglo de vectores, donde cada vector es una fila de la matriz. Por ejemplo, la matriz  A se puede implementar en C de la siguiente manera `matriz[3][3] = {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};` como un arreglo de tres vectores:

![](/00.-Sources/Images/MatrizC.png)

_Matriz implementada en el lenguaje C_

## Escalar; la unidad del álgebra lineal

Un escalar es un número real. En el álgebra lineal, un escalar es un número real que se multiplica por un vector o una matriz. Los escalares se representan con letras minúsculas, como `a`, `b`, `c`, etc.

![](/00.-Sources/Images/Escalar.png)

_Escalar en álgebra lineal_

Escalar en C, es un número real que se multiplica por un vector o una matriz. Los escalares se representan con letras minúsculas, como `a`, `b`, `c`, etc.

![](/00.-Sources/Images/EscalarC.png)

### Operaciones con matrices

#### Suma de matrices

La suma de dos matrices `A` y `B` se denota como `A + B` y se define como:

![](/00.-Sources/Images/SumaM.png)

_Suma de matrices en álgebra lineal_

Suma de matrices en C, es la suma de dos matrices `A` y `B` se denota como `A + B` y se define como:

![](/00.-Sources/Images/SumaMC.png)

_Suma de matrices implementada en el lenguaje C_

#### Resta de matrices

La resta de dos matrices `A` y `B` se denota como `A - B` y se define como:

![](/00.-Sources/Images/RestaM.png)

_Resta de matrices en álgebra lineal_

Resta de matrices en C, es la resta de dos matrices `A` y `B` se denota como `A - B` y se define como:

![](/00.-Sources/Images/RestaMC.png)

_Resta de matrices implementada en el lenguaje C_

#### Multiplicación de matrices

La multiplicación de dos matrices `A` y `B` se denota como `A * B` y se define como:

![](/00.-Sources/Images/MultiplicacionM.jpg)

_Multiplicación de matrices en álgebra lineal_

Multiplicación de matrices en C, es la multiplicación de dos matrices `A` y `B` se denota como `A * B` y se define como:

![](/00.-Sources/Images/MultiplicacionMC.png)

_Multiplicación de matrices implementada en el lenguaje C_

#### Multiplicación de una matriz por un escalar

La multiplicación de una matriz `A` por un escalar `k` se denota como `k * A` y se define como:

![](/00.-Sources/Images/MultiplicacionEscalar.png)

_Multiplicación de una matriz por un escalar en álgebra lineal_

Multiplicación de una matriz por un escalar en C, es la multiplicación de una matriz `A` por un escalar `k` se denota como `k * A` y se define como:

![](/00.-Sources/Images/MultiplicacionEscalarC.png)


### Tipos de matrices

#### Matriz identidad

Una matriz identidad es una matriz cuadrada que tiene unos en la diagonal principal y ceros en todas las demás entradas. La matriz identidad se representa con la letra `I` y tiene el mismo número de filas y columnas. Por ejemplo, la matriz identidad de 3 × 3 se representa como `I3` y se define como:

![](/00.-Sources/Images/MatrizI.png)

_Matriz identidad en álgebra lineal_

Matriz identidad en C, es una matriz cuadrada que tiene unos en la diagonal principal y ceros en todas las demás entradas. La matriz identidad se representa con la letra `I` y tiene el mismo número de filas y columnas. Por ejemplo, la matriz identidad de 3 × 3 se representa como `I3` y se define como:

![](/00.-Sources/Images/MatrizIC.png)

_Matriz identidad implementada en el lenguaje C_

#### Matriz transpuesta

Una matriz transpuesta es una matriz que se obtiene de otra matriz cambiando sus filas por columnas. La matriz transpuesta de una matriz `A` se denota como `A^T` y se define como:

![](/00.-Sources/Images/MatrizT.png)

_Matriz transpuesta en álgebra lineal_

Matriz transpuesta en C, es una matriz que se obtiene de otra matriz cambiando sus filas por columnas. La matriz transpuesta de una matriz `A` se denota como `A^T` y se define como:

![](./Sources/Images/MatrizTC.png)

#### Matriz inversa

Una matriz inversa es una matriz que, cuando se multiplica por otra matriz, produce la matriz identidad. La matriz inversa de una matriz `A` se denota como `A^-1` y se define como:

![](/00.-Sources/Images/MatrizInversa.jpg)

_Matriz inversa en álgebra lineal_

Existen varios métodos para calcular la matriz inversa de una matriz. El método más común es el método de Gauss-Jordan. El método de Gauss-Jordan se basa en la eliminación de Gauss y la eliminación de Gauss-Jordan. El método de Gauss-Jordan se puede utilizar para calcular la matriz inversa de una matriz cuadrada de cualquier tamaño, pero es un programa muy largo y no es el propocito de este post

# En resumen es muy importante para el desarrollo de la inteligencia artificial, y para el desarrollo de la inteligencia artificial es necesario el uso de matrices, por lo que es importante conocer las operaciones con matrices, los tipos de matrices y las operaciones con escalares  🤓

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado_

















