# Complejidad algoritmica

_La teoría de la complejidad es el estudio de la cantidad de recursos que requiere un algoritmo al ejecutarse en función del tamaño de su entrada, es fundamental conocerla para escribir código de manera eficiente, existen dos tipos de complejidad:_

- **Complejidad espacial:** cuánta memoria necesita un algoritmo para ejecutarse.

- **Complejidad del tiempo:** cuánto tiempo necesita un algoritmo para ejecutarse.

_En la mayoría de los casos, se pone más atención en la complejidad del tiempo que a la complejidad espacial porque se puede reutilizar memoría pero no se puede reutilizar el tiempo que tarda un algoritmo en ejecutarse, es más fácil comprar memoria que ganar tiempo._

## Notación Asintótica 

![](/00.-Sources/Images/bigO.png)

- **Complejidad del tiempo constante <i>O(1)</i>**: → Se dice que un algoritmo se ejecuta en tiempo constante si requiere la misma cantidad de tiempo, independientemente del tamaño de entrada, por ejemplo, acceder a cualquier elemento de una matriz o una función para intercambiar dos números.

- **Complejidad del tiempo logarítmico <i>O(log n)</i>** → Significa esencialmente que el tiempo de funcionamiento crece en proporción logaritmica a la del tamaño de entrada, es decir que la relación entre el número de operaciones N y el tamaño de la entrada n disminuye cuando aumenta el tamaño de entrada, por ejemplo el algoritmo de búsqueda binaria, con cada iteración, nuestra función va dividiendo la entrada, realizando así la operación inversa de exponenciación.

- **Complejidad del tiempo lineal <i>O(n)</i>** →  Un algoritmo se ejecuta en tiempo lineal cuando el tiempo de ejecución aumenta a lo sumo proporcionalmente con el tamaño de la entrada n, ejemplos en esta complejidad son, Shell Sort y la búsqueda lineal.

- **Complejidad del tiempo logarítmico lineal <i>O(n log n)</i>** →Los algoritmos de esta complejidad temporal son ligeramente más lentos que los de tiempo lineal y se mantienen escalables, las implementaciones flotan alrededor del tiempo lineal hasta que la entrada alcanza un tamaño lo suficientemente grande, por ejemplo, los algoritmos basados en la estrategia algoritmica de divide y conquista (Merge Sort, Heap Sort y Quick Sort).

- **Complejidad del tiempo cuadrático <i>O(n²)</i>** → Significa que hay un bucle que itera sobre un conjunto de cosas, y dentro de ese bucle hay otro bucle sobre todas las cosas, ejemplos sobre esta complejidad son BubbleSort, Selection Sort e Insertion Sort.

- **Complejidad del tiempo exponencial <i>O(2^n)</i>** → Significa que el tiempo de ejecución se duplica con cada adición al conjunto de datos de entrada. ,el problema de la mochila o el problema de las N reinas, son ejemplos de esta complejidad. 

- **Complejidad del tiempo factorial <i>O(n!)</i>** → Un algoritmo se ejecuta en tiempo factorial si itera sobre la entrada n un número de veces igual a n multiplicado por todos los números enteros positivos menores que n, el problema del viajante y el algoritmo para calcular permutaciones de una colección, son ejemplos de la complejidad del tiempo factorial.



