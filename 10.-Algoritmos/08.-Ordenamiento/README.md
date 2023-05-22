# Algoritmos de ordenamiento

![Ordenamiento](/01.-Sources/Images/Ordenamiento.png)

_Representación de algoritmos de ordenamiento_

## En computación y matemáticas un algoritmo de ordenamiento que pone elementos de una lista o un vector en una secuencia dada por una relación de orden

Existen diferentes tipos de algoritmos de ordenamiento, cada uno con sus propias características y eficiencia en términos de tiempo de ejecución y uso de recursos. Algunos de los algoritmos de ordenamiento más comunes son:

- Ordenamiento burbuja (Bubble sort) - O(n²)
- Ordenamiento por selección (Selection sort) - O(n²)
- Ordenamiento por inserción (Insertion sort) - O(n²)
- Ordenamiento por mezcla (Merge sort) - O(n log n)
- Ordenamiento rápido (Quick sort) - O(n log n)
- Ordenamiento por montículos (Heap sort) - O(n log n)
- Ordenamiento Shell (Shell sort) - O(n²)
- Ordenamiento por conteo (Counting sort) - O(n)
- Ordenamiento por casillas (Bucket sort) - O(n)

### Ventajas

- Organización de datos: Los algoritmos de ordenamiento permiten organizar los datos de manera coherente y estructurada, lo que facilita su acceso y manipulación posterior. Los datos ordenados suelen ser más eficientes de procesar y buscar

- Eficiencia: Los datos ordenados pueden mejorar la eficiencia en muchas operaciones, como búsquedas binarias, fusiones de arreglos y eliminación de duplicados. Los algoritmos de ordenamiento eficientes pueden reducir la complejidad temporal de estas operaciones

- Aplicaciones prácticas: El ordenamiento es una operación común en muchas aplicaciones de software. Desde organizar datos en bases de datos hasta presentar información en orden a los usuarios, los algoritmos de ordenamiento tienen numerosas aplicaciones prácticas

### Desventajas

- Complejidad temporal: Algunos algoritmos de ordenamiento tienen una complejidad temporal alta, lo que significa que su tiempo de ejecución aumenta significativamente con el tamaño de los datos a ordenar. Algoritmos como el ordenamiento por burbuja o el ordenamiento por selección tienen una complejidad temporal cuadrática, lo que puede ser ineficiente para grandes conjuntos de datos

- Dependencia del orden inicial: Algunos algoritmos de ordenamiento pueden ser sensibles al orden inicial de los datos. Si los datos ya están parcialmente ordenados o si hay patrones específicos en los datos, algunos algoritmos pueden ser menos eficientes y requerir más comparaciones y movimientos de elementos

- Implementación compleja: Algunos algoritmos de ordenamiento más eficientes, como el ordenamiento rápido o el ordenamiento por mezcla, pueden ser más complejos de implementar y depurar en comparación con los algoritmos más simples. Requieren una comprensión más profunda de los conceptos y pueden tener casos especiales difíciles de manejar


## Ejemplos

### Ordenamiento burbuja: Este algoritmo compara repetidamente pares adyacentes de elementos y los intercambia si están en el orden incorrecto - O(n²)

![OB](/01.-Sources/Images/OB.png)

_Representación del ordenamiento burbuja_

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

void ordenamientoBurbuja(int arr[], int n)
{
    int i, j;
    bool intercambio = false;
    for (i = 0; i < n - 1; i++)
    {
        intercambio = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Intercambio de elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                intercambio = true;
            }
        }

        if (!intercambio)
        {
            break;
        }

    }
}
```

### Ordenamiento por insercción: Este algoritmo construye una lista ordenada tomando un elemento a la vez y colocándolo en la posición correcta dentro de la lista ordenada. Comienza con una lista de un solo elemento y se va expandiendo, insertando cada nuevo elemento en su posición adecuada - O(n²)

![OI](/01.-Sources/Images/OI.png)

_Representación del ordenamiento por insercción_


```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

void ordenamientoPorInserccion(int arr[], int n)
{
   int i, j, valor;
   for (i = 1; i < n; i++)
   {
      valor = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > valor)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = valor;
   }
}
```

### Ordenamiento rápido: Este algoritmo utiliza el enfoque "divide y vencerás" para ordenar la lista. Selecciona un elemento como pivote y divide la lista en dos sublistas: una con elementos menores que el pivote y otra con elementos mayores que el pivote. Luego, se aplica recursivamente el mismo proceso a las sublistas hasta que la lista esté completamente ordenada - O(n log n)

![OR](/01.-Sources/Images/OR.png)

_Representación del ordenamiento rápido_


```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);
// int izq = 0;
// int der = n - 1;

// Función para particionar la matriz en dos submatrices
int particion(int arr[], int izq, int der)
{
   int pivote = arr[der];
   int i = (izq - 1);
   for (int j = izq; j <= der - 1; j++)
   {
      if (arr[j] < pivote)
      {
         i++;
         // Intercambio de elementos
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   // Intercambio de elementos
   int temp = arr[i + 1];
   arr[i + 1] = arr[der];
   arr[der] = temp;
   return (i + 1);
}

void ordenamientoRapido(int arr[], int izq, int der)
{
   if (izq < der)
   {
      int indiceParticion = particion(arr, izq, der);
      ordenamientoRapido(arr, izq, indiceParticion - 1);
      ordenamientoRapido(arr, indiceParticion + 1, der);
   }
}
```

### Ordenamiento por montículos: Este algoritmo utiliza una estructura de datos llamada "montículo" o "heap" para ordenar la lista. Primero, se construye un montículo a partir de los elementos de la lista. Luego, se extrae repetidamente el elemento máximo (en un montículo máximo) y se coloca al final de la lista ordenada. El proceso de extracción del elemento máximo y reconstrucción del montículo se repite hasta que el montículo esté vacío - O(n log n)

![OM](/01.-Sources/Images/OM.png)

_Representación del ordenamiento por montículos_


```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

// Función para amontonar un subárbol en un índice dado
void amontonar(int arr[], int n, int i)
{
   int mayor = i;
   int izq = 2 * i + 1;
   int der = 2 * i + 2;
   if (izq < n && arr[izq] > arr[mayor])
   {
      mayor = izq;
   }
   if (der < n && arr[der] > arr[mayor])
   {
      mayor = der;
   }
   if (mayor != i)
   {
      // Intercambio de elementos
      int temp = arr[i];
      arr[i] = arr[mayor];
      arr[mayor] = temp;
      amontonar(arr, n, mayor);
   }
}

void ordenamientoPorMonticulo(int arr[], int n)
{
   // Construir montículo (heap)
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      amontonar(arr, n, i);
   }
   // Extraer elementos del montículo
   for (int i = n - 1; i > 0; i--)
   {
      // Intercambio de elementos
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      amontonar(arr, i, 0);
   }
}
```

### Ordenamiento por conteo: Este algoritmo de Counting Sort se utiliza cuando se conocen los valores posibles de los elementos a ordenar y estos son enteros no negativos. Funciona mediante la creación de un arreglo auxiliar de tamaño igual al valor máximo más uno de los elementos a ordenar. Luego, cuenta la frecuencia de cada elemento y utiliza esta información para construir la lista ordenada - O(n)

![OC](/01.-Sources/Images/OC.png)

_Representación del ordenamiento por conteo_

```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

void ordenamientoPorConteo(int arr[], int n)
{
   int max = arr[0];
   for (int i = 1; i < n; i++)
   {
      if (arr[i] > max)
      {
         max = arr[i];
      }
   }

   int conteo[max + 1];
   int arregloOrdenado[n];

   for (int i = 0; i <= max; i++)
   {
      conteo[i] = 0;
   }

   for (int i = 0; i < n; i++)
   {
      conteo[arr[i]]++;
   }

   for (int i = 1; i <= max; i++)
   {
      conteo[i] += conteo[i - 1];
   }

   for (int i = n - 1; i >= 0; i--)
   {
      arregloOrdenado[conteo[arr[i]] - 1] = arr[i];
      conteo[arr[i]]--;
   }

   for (int i = 0; i < n; i++)
   {
      arr[i] = arregloOrdenado[i];
   }
}
```

### Ordenamiento por casillas: Este algoritmo divide la lista en un número finito de "casillas" o "buckets". Luego, distribuye los elementos en cada casilla en función de un criterio específico. Cada casilla se ordena individualmente, ya sea utilizando otro algoritmo de ordenamiento o recursivamente. Finalmente, los elementos se concatenan para obtener la lista ordenada - O(n)

![OC](/01.-Sources/Images/OC.png)

_Representación del ordenamiento por casillas_


```c
// int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
// int n = sizeof(arr) / sizeof(arr[0]);

struct Nodo {
   int dato;
   struct Nodo *siguiente;
};

void ordenamientoPorCasillas(int arr[], int n)
{
   struct Nodo **casillas;
   int i, j;

   // Cantidad de casillas
   int numCasillas = 10;

   casillas = (struct Nodo **)malloc(numCasillas * sizeof(struct Nodo *));

   for (i = 0; i < numCasillas; i++)
   {
      casillas[i] = NULL;
   }

   // Colocar elementos en las casillas correspondientes
   for (i = 0; i < n; i++)
   {
      int indiceCasillas = arr[i] / numCasillas;
      struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
      nuevoNodo->dato = arr[i];
      nuevoNodo->siguiente = NULL;

      // Insertar en la casilla utilizando ordenamiento por inserción
      struct Nodo *actual = casillas[indiceCasillas];
      struct Nodo *anterior = NULL;
      while (actual != NULL && actual->dato < nuevoNodo->dato)
      {
         anterior = actual;
         actual = actual->siguiente;
      }
      if (anterior == NULL)
      {
         nuevoNodo->siguiente = casillas[indiceCasillas];
         casillas[indiceCasillas] = nuevoNodo;
      }
      else
      {
         nuevoNodo->siguiente = actual;
         anterior->siguiente = nuevoNodo;
      }
   }

   // Concatenar los elementos de todas las casillas
   int index = 0;
   for (i = 0; i < numCasillas; i++)
   {
      struct Nodo *actual = casillas[i];
      while (actual != NULL)
      {
         arr[index++] = actual->dato;
         struct Nodo *temp = actual;
         actual = actual->siguiente;
         free(temp);
      }
   }

   free(casillas);
}
```

## Conclusión

_Los algoritmos de ordenamiento son herramientas fundamentales para organizar datos y mejorar la eficiencia de muchas operaciones. Aunque tienen algunas desventajas en términos de complejidad temporal, espacio adicional y dependencia del orden inicial, su utilidad práctica y su importancia en la ciencia de la computación los convierten en una área de estudio esencial_

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_