
# Enfoque divida y conquista

## En el enfoque de divide y conquista, el problema en cuestión, se divide en subproblemas más pequeños y luego cada problema se resuelve de forma independiente (conquista).

_En el enfoque de divide y conquista, el problema en cuestión, se divide en subproblemas más pequeños y luego cada problema se resuelve de forma independiente (conquista). Cuando seguimos dividiendo los subproblemas en subproblemas aún más pequeños, eventualmente podemos llegar a una etapa en la que no sea posible más división. Se resuelven esos subproblemas "atómicos" más pequeños posibles (fracciones). La solución de todos los subproblemas finalmente se fusiona para obtener la solución de un problema original._

![](/00.-Sources/Images/DyC.png)

## En términos generales, podemos entender el enfoque de dividir y conquistar en un proceso de tres pasos:

### Dividir/Romper

_Este paso implica dividir el problema en subproblemas más pequeños. Los subproblemas deben representar una parte del problema original. Este paso generalmente toma un enfoque recursivo para dividir el problema hasta que ningún subproblema sea más divisible. En esta etapa, los subproblemas se vuelven de naturaleza atómica, pero aún representan una parte del problema real._

### Conquistar/Resolver

_Este paso recibe muchos subproblemas más pequeños que deben resolverse. Generalmente, en este nivel, los problemas se consideran "resueltos" por sí solos._

### Fusionar/Combinar

_Cuando se resuelven los subproblemas más pequeños, esta etapa los combina recursivamente hasta que formulan una solución del problema original. Este enfoque algorítmico funciona de manera recursiva y los pasos de conquista y fusión funcionan tan cerca que aparecen como uno solo._



### Algoritmos basados en este enfoque:

| # | Titulo | Implementación | Complejidad |
|---| ----- | -------- | ---------- |
|001|Ordenamiento por mezcla| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/06.-Ordenamiento/04-Ordenamiento-por-Mezcla.c) |Ο (n log n)|
|002|Ordenamiento rápido | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/06.-Ordenamiento/05-Ordenamiento-R%C3%A1pido.c)|Ο (n log n)|
|003|Búsqueda binaria | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/07.-B%C3%BAsqueda/12-B%C3%BAsqueda-Binaria.c)|Ο (log n)|

