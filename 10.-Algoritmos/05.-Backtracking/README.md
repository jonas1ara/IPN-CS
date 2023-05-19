# Algoritmos de backtracking

![BT](/01.-Sources/Images/BT.png)

_Representación de la estrategia backtracking_

## La estrategia algorítmica de backtracking es una técnica utilizada para encontrar soluciones a problemas de búsqueda exhaustiva, donde se exploran todas las posibles combinaciones hasta encontrar una solución óptima o satisfactoria

La estrategia algorítmica de backtracking es una técnica utilizada para encontrar soluciones a problemas de búsqueda exhaustiva, donde se exploran todas las posibles combinaciones hasta encontrar una solución óptima o satisfactoria. Esta estrategia se basa en la idea de "prueba y error", donde se realiza una búsqueda en profundidad de manera recursiva, explorando diferentes opciones y retrocediendo (backtracking) cuando una opción no conduce a una solución válida.

El algoritmo de backtracking generalmente sigue estos pasos:

1) Definir el problema: Se debe definir claramente el problema y las restricciones que se deben cumplir para encontrar una solución válida

2) Diseñar una función recursiva: Se crea una función recursiva que se encargará de realizar la búsqueda exhaustiva y el backtracking. Esta función se llama a sí misma de manera recursiva y se detiene cuando se encuentra una solución válida o se agotan todas las opciones

3) Establecer condiciones de terminación: Se definen las condiciones de terminación para la recursión. Estas condiciones pueden variar según el problema, por ejemplo, puede ser cuando se encuentra una solución válida o cuando se exploran todas las posibles combinaciones

4) Realizar la exploración y el backtracking: La función recursiva explora todas las posibles opciones paso a paso. En cada paso, se verifica si la opción actual cumple con las restricciones del problema. Si se cumple, se continúa explorando recursivamente con la siguiente opción. Si no se cumple, se retrocede (backtrack) al paso anterior y se prueba con la siguiente opción

 5) Almacenar las soluciones encontradas:
 Durante la exploración, se deben almacenar las soluciones válidas encontradas. Esto puede hacerse mediante una estructura de datos, como una lista o un arreglo, donde se van agregando las soluciones encontradas



### Ventajas

- Exploración exhaustiva: Los algoritmos de backtracking prueban sistemáticamente todas las posibles soluciones, lo que garantiza que se encuentre una solución óptima si existe. **Esto los hace útiles en problemas de búsqueda exhaustiva y optimización**

- Flexibilidad: Los algoritmos de backtracking son muy flexibles y se pueden aplicar a una amplia variedad de problemas, ya que no están limitados por restricciones estructurales rígidas

- Eficiencia en casos favorables: En algunos casos, los algoritmos de backtracking pueden ser altamente eficientes, ya que pueden podar ramas completas del árbol de búsqueda cuando se detecta que no conducen a una solución válida

### Desventajas

- Complejidad exponencial: La complejidad temporal de los algoritmos de backtracking puede crecer exponencialmente con el tamaño del problema y el número de opciones disponibles en cada paso. **Esto los hace ineficientes para problemas grandes o con un espacio de búsqueda extenso**

- Búsqueda ciega: Los algoritmos de backtracking no utilizan información heurística para guiar la exploración del espacio de búsqueda. Esto significa que pueden explorar ramas innecesarias y requerir un número significativo de pruebas

- Restricciones explícitas: Para evitar la exploración de soluciones inválidas, los algoritmos de backtracking requieren la definición y aplicación de restricciones explícitas. Esto puede ser difícil de hacer en algunos casos, lo que hace que el problema sea difícil de resolver con backtracking


## Ejemplos

### N Queens: dado un tablero de ajedrez de tamaño n, encontrar una configuración de N reinas en el tablero NxN donde ninguna reina pueda atacar a otra

```c
#define N 8

int tablero[N][N];

int esSeguro(int fila, int col)
{
	int i, j;

	// Verificar la fila hacia la izquierda
	for (i = 0; i < col; i++)
	{
		if (tablero[fila][i])
			return 0;
	}

	// Verificar la diagonal superior izquierda
	for (i = fila, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (tablero[i][j])
			return 0;
	}

	// Verificar la diagonal inferior izquierda
	for (i = fila, j = col; j >= 0 && i < N; i++, j--)
	{
		if (tablero[i][j])
			return 0;
	}

	return 1;
}

int resolverNQueens(int col)
{
	if (col >= N)
		return 1;

	for (int fila = 0; fila < N; fila++)
	{
		if (esSeguro(fila, col))
		{
			tablero[fila][col] = 1;

			if (resolverNQueens(col + 1))
				return 1;

			tablero[fila][col] = 0; // Backtracking
		}
	}

	return 0;
}
```

El código utiliza una matriz llamada `tablero` para representar el tablero de ajedrez, donde se colocarán las reinas. La función `esSeguro` se encarga de verificar si es seguro colocar una reina en una posición específica del tablero. 

La función `resolverNQueens` es la función principal que realiza el backtracking. Recibe como parámetro la columna actual que se está considerando para colocar una reina. Esta función se llama recursivamente para explorar todas las posibles combinaciones de ubicación de las reinas en el tablero.

Dentro de la función `resolverNQueens`, se realizan las siguientes acciones:

1) Se verifica si se ha colocado una reina en todas las columnas (si la columna actual es mayor o igual que 
`N`). En ese caso, se ha encontrado una solución válida y se retorna 1

2) Si aún no se han colocado todas las reinas, se itera por cada fila del tablero

3) Para cada fila, se verifica si es seguro colocar una reina en esa posición utilizando la función `esSeguro`. Si es seguro, se marca esa posición como ocupada colocando un 1 en la matriz `tablero`

4) Luego, se llama recursivamente a la función `resolverNQueens` incrementando la columna actual en 1. Esto permite continuar explorando las posibles ubicaciones de las reinas en las columnas restantes

5) Si la llamada recursiva devuelve 1, significa que se ha encontrado una solución válida. En ese caso, se retorna 1 para propagar la solución hacia arriba

6) Si la llamada recursiva devuelve 0, se llega al caso de backtracking. En este caso, se desmarca la posición actual colocando un 0 en la matriz `tablero` y se continúa con la siguiente fila del bucle

7) Si no se encuentra ninguna solución válida después de explorar todas las filas, se retorna 0 para indicar que no se ha encontrado ninguna solución válida


### Problema de la mochila: dado un conjunto de elementos, cada uno con un peso y un valor, determinar la combinación de elementos que maximice el valor total mientras se mantiene el peso total dentro de un límite

```c
//  int capacidad = 50;
//  int pesos[] = {10, 20, 30};
//  int valores[] = {60, 100, 120};
//  int n = sizeof(valores) / sizeof(valores[0]);
//  int valorMaximo = 0;

// Función para calcular el máximo de dos números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Función para realizar el backtracking
void mochilaBacktracking(int capacidad, int pesos[], int valores[], int n, int indice, int pesoActual, int valorActual, int *valorMaximo)
{
    // Caso base: si se alcanza el final de los objetos o la capacidad se agota
    if (indice == n || pesoActual == capacidad)
    {
        *valorMaximo = max(*valorMaximo, valorActual);
        return;
    }

    // Si el objeto actual no excede la capacidad, se considera incluirlo
    if (pesoActual + pesos[indice] <= capacidad)
    {
        mochilaBacktracking(capacidad, pesos, valores, n, indice + 1, pesoActual + pesos[indice], valorActual + valores[indice], valorMaximo);
    }

    // Se excluye el objeto actual y se pasa al siguiente
    mochilaBacktracking(capacidad, pesos, valores, n, indice + 1, pesoActual, valorActual, valorMaximo);
}
```

La función `mochilaBacktracking`, que utiliza el enfoque de backtracking para resolver el problema de la mochila. Toma varios argumentos: la `capacidad` de la mochila, los `pesos[]` y `valores[]` de los objetos, el número total de objetos como `n`, el `indice` actual, el `pesoActual`, el `valorActual`y un puntero a la dirección de memoria de `valorMaximo`

Dentro de la función, se verifica el caso base: si se alcanza el final de los objetos `(indice == n)` o si el peso acumulado alcanza la capacidad máxima de la mochila. En ese caso, se actualiza el valor máximo si el valor acumulado actual es mayor.

Si el objeto actual no excede la capacidad de la mochila, se realiza una llamada recursiva a `mochilaBacktracking` con el siguiente índice, el peso acumulado actual más el peso del objeto actual, el valor acumulado actual más el valor del objeto actual, y los demás argumentos se mantienen sin cambios.

Luego, se realiza una segunda llamada recursiva a `mochilaBacktracking` con el siguiente índice, pero el peso y valor acumulados no se modifican. Esto representa la opción de excluir el objeto actual.

El algoritmo de backtracking continúa explorando todas las combinaciones posibles de objetos, tomando decisiones de inclusión o exclusión en cada paso, hasta que se consideran todos los objetos.

## Conclusión

_En resumen, los algoritmos de backtracking garantizan la exploración exhaustiva de todas las posibles soluciones y son flexibles en términos de aplicabilidad. Sin embargo, pueden tener una complejidad exponencial, realizar una búsqueda ciega, requerir restricciones explícitas y ser sensibles al orden de las opciones, toma esto en cuenta al plantearte un problema que creas que puedes resolver usando backtracking_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_