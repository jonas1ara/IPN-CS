# Algoritmos de ordenamiento

![Ordenamiento](/01.-Sources/Images/Ordenamiento.png)

_Representación de algoritmos de ordenamiento_

## En computación y matemáticas un algoritmo de ordenamiento que pone elementos de una lista o un vector en una secuencia dada por una relación de orden

Existen diferentes tipos de algoritmos de ordenamiento, cada uno con sus propias características y eficiencia en términos de tiempo de ejecución y uso de recursos. Algunos de los algoritmos de ordenamiento más comunes son:

- Ordenamiento burbuja (Bubble sort)
- Ordenamiento por selección (Selection sort)
- Ordenamiento por inserción (Insertion sort)
- Ordenamiento por mezcla (Merge sort)
- Ordenamiento rápido (Quick sort)
- Ordenamiento por montículos (Heap sort)
- Ordenamiento Shell (Shell sort)
- Ordenamiento por conteo (Counting sort)
- Ordenamiento por casillas (Bucket sort)

### Ventajas

- Organización de datos: Los algoritmos de ordenamiento permiten organizar los datos de manera coherente y estructurada, lo que facilita su acceso y manipulación posterior. Los datos ordenados suelen ser más eficientes de procesar y buscar

- Eficiencia: Los datos ordenados pueden mejorar la eficiencia en muchas operaciones, como búsquedas binarias, fusiones de arreglos y eliminación de duplicados. Los algoritmos de ordenamiento eficientes pueden reducir la complejidad temporal de estas operaciones

- Aplicaciones prácticas: El ordenamiento es una operación común en muchas aplicaciones de software. Desde organizar datos en bases de datos hasta presentar información en orden a los usuarios, los algoritmos de ordenamiento tienen numerosas aplicaciones prácticas

### Desventajas

- Complejidad temporal: Algunos algoritmos de ordenamiento tienen una complejidad temporal alta, lo que significa que su tiempo de ejecución aumenta significativamente con el tamaño de los datos a ordenar. Algoritmos como el ordenamiento por burbuja o el ordenamiento por selección tienen una complejidad temporal cuadrática, lo que puede ser ineficiente para grandes conjuntos de datos

- Dependencia del orden inicial: Algunos algoritmos de ordenamiento pueden ser sensibles al orden inicial de los datos. Si los datos ya están parcialmente ordenados o si hay patrones específicos en los datos, algunos algoritmos pueden ser menos eficientes y requerir más comparaciones y movimientos de elementos

- Implementación compleja: Algunos algoritmos de ordenamiento más eficientes, como el ordenamiento rápido o el ordenamiento por mezcla, pueden ser más complejos de implementar y depurar en comparación con los algoritmos más simples. Requieren una comprensión más profunda de los conceptos y pueden tener casos especiales difíciles de manejar


## Ejemplos

### Ordenamiento burbuja: Este algoritmo compara repetidamente pares adyacentes de elementos y los intercambia si están en el orden incorrecto

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```

### Ordenamiento por insercción: Este algoritmo construye una lista ordenada tomando un elemento a la vez y colocándolo en la posición correcta dentro de la lista ordenada. Comienza con una lista de un solo elemento y se va expandiendo, insertando cada nuevo elemento en su posición adecuada

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```

### Ordenamiento rápido: Este algoritmo utiliza el enfoque "divide y vencerás" para ordenar la lista. Selecciona un elemento como pivote y divide la lista en dos sublistas: una con elementos menores que el pivote y otra con elementos mayores que el pivote. Luego, se aplica recursivamente el mismo proceso a las sublistas hasta que la lista esté completamente ordenada

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```

### Ordenamiento por montículos: Este algoritmo utiliza una estructura de datos llamada "montículo" o "heap" para ordenar la lista. Primero, se construye un montículo a partir de los elementos de la lista. Luego, se extrae repetidamente el elemento máximo (en un montículo máximo) y se coloca al final de la lista ordenada. El proceso de extracción del elemento máximo y reconstrucción del montículo se repite hasta que el montículo esté vacío

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```

### Ordenamiento por conteo: Este algoritmo de Counting Sort se utiliza cuando se conocen los valores posibles de los elementos a ordenar y estos son enteros no negativos. Funciona mediante la creación de un arreglo auxiliar de tamaño igual al valor máximo más uno de los elementos a ordenar. Luego, cuenta la frecuencia de cada elemento y utiliza esta información para construir la lista ordenada

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```

### Ordenamiento por casillas: Este algoritmo divide la lista en un número finito de "casillas" o "buckets". Luego, distribuye los elementos en cada casilla en función de un criterio específico. Cada casilla se ordena individualmente, ya sea utilizando otro algoritmo de ordenamiento o recursivamente. Finalmente, los elementos se concatenan para obtener la lista ordenada

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

```




## Conclusión

_Los algoritmos de ordenamiento son herramientas fundamentales para organizar datos y mejorar la eficiencia de muchas operaciones. Aunque tienen algunas desventajas en términos de complejidad temporal, espacio adicional y dependencia del orden inicial, su utilidad práctica y su importancia en la ciencia de la computación los convierten en una área de estudio esencial_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_