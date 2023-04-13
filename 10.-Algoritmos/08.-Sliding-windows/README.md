# Programación dinámica

## La programación dinámica se utiliza donde tenemos problemas, que se pueden dividir en subproblemas similares, para que sus resultados puedan ser reutilizados.

_El enfoque de programación dinámica es similar a dividir y conquistar al dividir el problema en subproblemas posibles más pequeños y aún más pequeños. Pero a diferencia de dividir y conquistar, estos subproblemas no se resuelven de forma independiente. Más bien, los resultados de estos subproblemas más pequeños se recuerdan y se utilizan para subproblemas similares o superpuestos._

_La programación dinámica se utiliza donde tenemos problemas, que se pueden dividir en subproblemas similares, para que sus resultados puedan ser reutilizados. En su mayoría, estos algoritmos se utilizan para la optimización. Antes de resolver el subproblema en la mano, el algoritmo dinámico intentará examinar los resultados de los subproblemas previamente resueltos. Las soluciones de los subproblemas se combinan para lograr la mejor solución._

### En términos generales, podemos entender el enfoque de programación dinámica de la siguiente manera:

-  El problema debería poder dividirse en un subproblema superpuesto más pequeño.

- Se puede lograr una solución óptima mediante el uso de una solución óptima de subproblemas más pequeños.

- Los algoritmos dinámicos utilizan Memoization.

### Ventajas

- Acelera el procesamiento, ya que usa referencias que fueron previamente calculadas.

### Desventajas
- Requiere mucho uso de memoría para almacenar el resultado calculado de cada subproblema, sin poder garantizar que el valor se utilizará.

## Comparación con otras estrategias algorítmicas

### Algoritmos codiciosos

_A diferencia de los **algoritmos codiciosos**, donde se aborda la optimización local, los algoritmos dinámicos están motivados para una optimización general del problema._

### Algoritmos de divide y vencerás

_A diferencia de los **algoritmos de divide y vencerás**, donde las soluciones se combinan para lograr una solución general, los algoritmos dinámicos utilizan la salida de un subproblema más pequeño y luego intentan optimizar un subproblema más grande. Los algoritmos dinámicos utilizan memoización para recordar el resultado de subproblemas ya resueltos._

## Ejemplos

### La serie numérica de Fibonacci

### El problema de la mochila


### Algoritmos basados en este enfoque:

| # | Titulo | Implementación | Complejidad |
|---| ----- | -------- | ---------- |
|001|El problema de la mochila| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/04.-Programaci%C3%B3n-din%C3%A1mica/01-Problema-de-la-mochila.c) |Ο (n²)|
|002|El problema del viajante | C |Ο (n²)|
|003|La serie numérica de Fibonacci| [C#](https://github.com/Jonas-Lara/Basi.cs/blob/master/04.-Programaci%C3%B3n-din%C3%A1mica/Algoritmos/02-Fibonacci-memoizaci%C3%B3n.cs)|Ο (n²)|
