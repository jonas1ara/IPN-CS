#include <stdio.h>
#include <stdlib.h>

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

void imprimirArreglo(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

int main()
{
   int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
   int n = sizeof(arr) / sizeof(arr[0]);

   printf("Ordenamiento por casillas (bucket sort) - O(n)\n\n");

   printf("Arreglo original: ");
   imprimirArreglo(arr, n);

   ordenamientoPorCasillas(arr, n);

   printf("Arreglo ordenado: ");
   imprimirArreglo(arr, n);

   return 0;
}