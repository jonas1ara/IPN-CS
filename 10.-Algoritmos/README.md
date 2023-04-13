# Algoritmos

_El algoritmo es un procedimiento paso a paso, que define un conjunto de instrucciones que se ejecutarán en un cierto orden para obtener la salida deseada. Los algoritmos generalmente se crean independientemente de los lenguajes subyacentes, es decir, un algoritmo se puede implementar en más de un lenguaje de programación._

### Características de un algoritmo

_No todos los procedimientos se pueden llamar algoritmo. Un algoritmo debe tener las siguientes características:_

- **Inequívoco:** Debe ser claro e inequívoco. Cada uno de sus pasos (o fases), y sus entradas/ salidas deben ser claros y deben conducir a un solo significado.

- **Entrada:** Debe tener 0 o más entradas bien definidas.

- **Salida:** Debe tener 1 o más salidas bien definidas y debe coincidir con la salida deseada.

- **Finitud:** Debe terminar después de un número finito de pasos.

- **Viabilidad:** Debe ser factible con los recursos disponibles.

- **Independiente:** Debe tener instrucciones paso a paso, que deben ser independientes de cualquier código de programación.

## Diseño de algoritmos:

_En el diseño y análisis de algoritmos, **generalmente el segundo método se utiliza para describir un algoritmo.** Hace que sea fácil para el analista analizar el algoritmo ignorando todas las definiciones no deseadas. Puede observar qué operaciones se están utilizando y cómo fluye el proceso, **diseñamos un algoritmo para obtener una solución de un problema determinado.** Un problema se puede resolver de más de una manera, por lo tanto, se pueden derivar muchos algoritmos de solución para un problema determinado, entonces el siguiente paso es analizar los algoritmos de solución propuestos e implementar la mejor solución adecuada._

## Análisis de algoritmos 

_La eficiencia de un algoritmo se puede analizar en dos etapas diferentes, antes de la implementación y después de la implementación. Son las siguientes:_

- **Análisis a priori:** Este es un análisis teórico de un algoritmo. La eficiencia de un algoritmo se mide asumiendo que todos los demás factores, por ejemplo, la velocidad del procesador, son constantes y no tienen ningún efecto en la implementación.

- **Análisis posterior:** Este es un análisis empírico de un algoritmo. El algoritmo seleccionado se implementa utilizando el lenguaje de programación. Esto se ejecuta en la máquina de la computadora de destino. En este análisis, se recopilan estadísticas reales como el tiempo de ejecución y el espacio requerido.

## Complejidad algoritmica

_La teoría de la complejidad es el estudio de la cantidad de recursos que requiere un algoritmo al ejecutarse en función del tamaño de su entrada, es fundamental conocerla para escribir código de manera eficiente, existen dos tipos de complejidad:_

- **Complejidad espacial:** cuánta memoria necesita un algoritmo para ejecutarse.

- **Complejidad del tiempo:** cuánto tiempo necesita un algoritmo para ejecutarse.

_En la mayoría de los casos, se pone más atención en la complejidad del tiempo que a la complejidad espacial porque se puede reutilizar memoría pero no se puede reutilizar el tiempo que tarda un algoritmo en ejecutarse, es más fácil comprar memoria que ganar tiempo._

## Notación Asintótica 

![](/00.-Sources/Images/bigO.png)

### Complejidad del tiempo constante <i>O(1)</i>

- Complejidad del tiempo constante **<i>O(1)</i>**: → Se dice que un algoritmo se ejecuta en tiempo constante si requiere la misma cantidad de tiempo, independientemente del tamaño de entrada, por ejemplo, acceder a cualquier elemento de una matriz o una función para intercambiar dos números.

_**Algoritmo para intercambiar valores:**_

```c
void intercambio(int a, int b) 
{   
   int temp;
   
   temp = a; 
   a = b; 
   b = temp;
}

```

### Complejidad del tiempo logarítmico <i>O(log n)</i>

- Complejidad del tiempo logarítmico **<i>O(log n)</i>** → Significa esencialmente que el tiempo de funcionamiento crece en proporción logaritmica a la del tamaño de entrada, es decir que la relación entre el número de operaciones N y el tamaño de la entrada n disminuye cuando aumenta el tamaño de entrada, por ejemplo el algoritmo de búsqueda binaria, con cada iteración, nuestra función va dividiendo la entrada, realizando así la operación inversa de exponenciación.

_**Algoritmo de búsqueda binaria:**_

```c
int busquedaBinaria(int data) 
{
   int limiteInferior = 0;
   int limiteSuperior = MAX -1;
   int puntoMedio = -1;
   int comparacion = 0;      
   int index = -1;
	
   while(limiteInferior <= limiteSuperior) 
   {
      puntoMedio = limiteInferior + (limiteSuperior - limiteInferior) / 2;	
		
      if(arr[puntoMedio] == data) 
      {
         index = puntoMedio;
         break;
      } else 
      {
         if(arr[puntoMedio] < data) 
         {
            limiteInferior = puntoMedio + 1;
         }
         else 
         {
            limiteSuperior = puntoMedio -1;
         }
      }               
   }
   return index;
}
```

### Complejidad del tiempo lineal <i>O(n)</i>

- Complejidad del tiempo lineal **<i>O(n)</i>** → Un algoritmo se ejecuta en tiempo lineal cuando el tiempo de ejecución aumenta a lo sumo proporcionalmente con el tamaño de la entrada n, ejemplos en esta complejidad son, Shell Sort y la búsqueda lineal.

_**Algoritmo de búsqueda lineal:**_

```c
int busquedaLineal(int data)
{
   int comparaciones = 0;
   int index = -1;
   int i;

   for(i = 0;i<MAX;i++) 
   {
      comparaciones++;
		
      if(data == arr[i]) 
      {
         index = i;
         break;
      }
   }   
   return index;
}
```

### Complejidad del tiempo logarítmico lineal <i>O(n log n)</i>

- Complejidad del tiempo logarítmico lineal <i>O(n log n)</i> → Los algoritmos de esta complejidad temporal son ligeramente más lentos que los de tiempo lineal y se mantienen escalables, las implementaciones flotan alrededor del tiempo lineal hasta que la entrada alcanza un tamaño lo suficientemente grande, por ejemplo, los algoritmos basados en la estrategia algoritmica de divide y conquista (Merge Sort, Heap Sort y Quick Sort).

_**Algoritmo de ordenamiento por mezcla:**_

```c
void ordenamiento_por_Mezcla(int inicio, int mitad, int final) 
{
   int i1, i2, i;

   for(i1 = inicio, i2 = mitad + 1, i = inicio; i1 <= mitad && i2 <= final; i++) 
   {
      if(a[i1] <= a[i2])
         b[i] = a[i1++];
      else
         b[i] = a[i2++];
   }
 
   while(i1 <= mitad)    
      b[i++] = a[i1++];

   while(i2 <= final)   
      b[i++] = a[i2++];
      
   for(i = inicio; i <= final; i++)
      a[i] = b[i];
}
```

### Complejidad del tiempo cuadrático <i>O(n²)</i>

- Complejidad del tiempo cuadrático <i>O(n²)</i> → Significa que hay un bucle que itera sobre un conjunto de cosas, y dentro de ese bucle hay otro bucle sobre todas las cosas, ejemplos sobre esta complejidad son BubbleSort, Selection Sort e Insertion Sort.

_**Algoritmo de ordenamiento burbuja:**_

```c
void ordenamiento_Burbuja() 
{
   int temp;
   
   for(int i = 0; i < MAX-1; i++) 
   { 
      for(int j = 0; j < MAX-1-i; j++) 
      {
         if(arr[j] > arr[j+1]) 
         {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
   	  }
   }    
}
```
### Complejidad del tiempo exponencial <i>O(2^n)</i>

- Complejidad del tiempo exponencial <i>O(2^n)</i> → Significa que el tiempo de ejecución se duplica con cada adición al conjunto de datos de entrada. ,el problema de la mochila o el problema de las N reinas, son ejemplos de esta complejidad. 

_**Algoritmo para resolver el problema de las N reinas:**_

```c

bool resolverNQ(int tablero[N][N], int colm)
{
	if (colm >= N)
		return true;

	for (int i = 0; i < N; i++) 
	{	
		if (posicionValida(tablero, i, colm)) 
		{
			board[i][colm] = 1;

			if (resolverNQ(tablero, colm + 1))
				return true;
			tablero[i][colm] = 0; 
		}
	}
	return false;
}
```

### Complejidad del tiempo factorial <i>O(n!)</i>

- Complejidad del tiempo factorial <i>O(n!)</i> → Un algoritmo se ejecuta en tiempo factorial si itera sobre la entrada n un número de veces igual a n multiplicado por todos los números enteros positivos menores que n, el algoritmo para cálcular los números de Fibonacci recursivamente y el algoritmo para calcular permutaciones de una colección, son ejemplos de la complejidad del tiempo factorial.

_**Algoritmo para cálcular los números de Fibonacci recursivamente:**_

```c
int Fibonacci(int n)
{
	if(n <= 1)
	{
		return n;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
```

---

## En resumen si estas empezando en las ciencias de la computación es muy importante que comprendas las diferentes estrategías algoritmicas y su análisis asintótico, no solo para entrevistas técnicas sino para desarrollar un proceso de pensamiento que puedes llevar a cualquier lado 🧠

## Referencias 📚

_Cormen, T. H., Leiserson, C. E., Rivest, R. L. & Stein, C. (2009). [Introduction to Algorithms](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844) (3rd ed.). MIT Press._

## Expresiones de gratitud

Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado
