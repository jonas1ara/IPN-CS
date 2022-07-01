# Algoritmos voraces

## En el enfoque de un algoritmo codicioso las decisiones se toman desde el dominio solucion dado. 

_En el enfoque de un algoritmo codicioso las decisiones se toman desde el dominio solucion dado. Se elige la solución más cercanda que parece solucionar el problema, posteriormente intenta encontrar una solución optima localiza, que eventualmente puede conducir a soluciones optimas a nivel mundial. Sin embargo generalmente no proporcionan soluciones a nivel mundial._

### Ventajas

- Son rápidos

### Desventajas
- No siempre dan la mejor solución

## Ejemplos

### Contar monedas

_Este problema es contar hasta un valor deseado eligiendo las monedas menos posibles y el enfoque codicioso obliga al algoritmo a elegir la moneda más grande posible._

![](/00.-Sources/Images/Contar.png)

#### Si se nos proporcionan mondeas $1, $2, $3, $5 y $10 y se nos pide que contemos $18, entonces el procedimiento codicioso será:

- Seleccionar moneda de $10, el recuento restante es 8.
- Luego seleccionar moneda de $5, el recuento restante es 3.
- Luego seleccionar moneda de $2, el recuento restante es 1.
- Al final seleccionar moneda de $1, y se resuelve el problema.

_Parece funcionar bien, pero si cambiamos ligeramente el problema, entonces el enfoque queda mal optmizado. Si tenemos monedas de $1, $7 y $10, y necesitamos contar al $15, puede usar más monedas de las necesarias:_

#### Si se nos proporcionan monedas de $1, $7 y $10, y necesitamos contar al $15, puede usar mas monedas de las necesarias:

- Seleccionar moneda de $10, el recuero restante es 5
- Luego seleccionar moneda de $1, el recuento restante es 4.
- Luego seleccionar moneda de $1, el recuento restante es 3.
- Luego seleccionar moneda de $1, el recuento restante es 2.
- Luego seleccionar moneda de $1, el recuento restante es 1.
- Al final seleccionar moneda de $1, y se resuelve el problema.

#### Cuando la solución mas optima es:

- Seleccionar moneda de $7, el recuero restante es 8
- Luego seleccionar moneda de $7, el recuento restante es 1.
- Al final seleccionar moneda de $1, y se resuelve el problema.

### El problema de la mochila

![](/00.-Sources/Images/Mochila.png)

#####

#####

### Algoritmos basados en este enfoque:

| # | Titulo | Implementación | Complejidad |
|---| ----- | -------- | ---------- |
|001|El problema de la mochila| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/02.-Voraces/01-Problema-de-la-mochila.c) |Ο (n²)|
|002|El problema del viajante | C |Ο (n²)|
|003|El problema de la programación de trabajos | C |Ο (n²)|
