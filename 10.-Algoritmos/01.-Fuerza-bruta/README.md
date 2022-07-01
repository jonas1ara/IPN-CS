# Algoritmos de fuerza bruta

## Es un enfoque algoritmico de prueba y error, cuándo se implementa se prueban todas las posibles soluciones.

### Ventajas

- Optienes la mejor solución de todas.
- Siempre encuentra una solución, si se logra implementar.
- Es más fácil de implementar.

### Desventajas
- Este enfoque puede tomar demasiado tiempo(siglos incluso)
- No considera eficiencia

### Encontrar el divisor de un número natural n

##### Divisores de 4
- 4/1 = 4
- 4/2 = 2
- 4/3 = ...
- 4/4 = 4

##### Divisores de 99
- 99/1 = 99
- 99/2 = ...
- 99/3 = 33
- 99/4 = ...
- ...
- 99/99 = 1

### Algoritmos basados en este enfoque:

| # | Titulo | Implementación | Complejidad |
|---| ----- | -------- | ---------- |
|001|Ordenamiento burbuja| [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/06.-Ordenamiento/01-Ordenamiento-Burbuja.c) |Ο (n²)|
|002|Problema de las N reinas | [C](https://github.com/Jonas-Lara/IPN-CS/blob/master/10.-Algoritmos/05.-Backtracking/01-N-Reinas-Geek.c)|Ο (2^n)|
