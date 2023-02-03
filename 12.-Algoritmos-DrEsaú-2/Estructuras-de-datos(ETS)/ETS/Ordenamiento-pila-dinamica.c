#include <stdio.h>    
#include <stdlib.h>   
#include <stdbool.h>  

// Estructura del nodo de una pila
struct nodo {
  int numero;
  struct nodo *siguiente;
};

// Prototipos de funciones
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimirPila(void);
void imprimirArreglo(int arr[], int n) ;
void ordenamiento_por_Inserccion(int arr[], int n);
int ultimo(void);  // Función entera que devuelve el último elemento de la pila, de utilidad para el algoritmo de ordenamiento por selección


// Todo comienza con el nodo superior
struct nodo *superior = NULL;

int main() {

    int arr[]= {}; // Arreglo que contiene los elementos extraídos de la pila para el ordenamiento
    int eleccion;
    int numero;
    int n;
    printf("Bienvenido al programa de ordenamiento por insercción mediante una pila dinámica\n\n");
    printf("Por favor ingresa el número de elementos que tendrá la pila: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Ingresa el número que agregaremos a la pila:\n");
        scanf("%d", &numero);
        agregar(numero);
    }
    imprimirPila();
    for (int i = 0; i < n; i++)
    {
       printf("Eliminando el último elemento: %d , ", ultimo());

        arr[i] = ultimo();

        eliminarUltimo();
        imprimirPila();
    }
    printf("Nada por imprimir, el arreglo obtenido para ordenar por el método de insercción es el siguiente:\n");
    imprimirArreglo(arr , n);
    ordenamiento_por_Inserccion(arr, n);
    
    printf("Arreglo ordenado por el método de insercción:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);

        agregar(arr[i]); //A la vez que se va recorriendo el arreglo ordenado, se agregan los elementos en orden a la pila
    }
    printf("\n\n"); //Brinquito para que no se vea tan malo el resultado jaja :v
    
    imprimirPila();

    return 0;
    
}

//Función para saber cuál es el último elemento(número) de la pila
int ultimo() 
{
    if (superior == NULL)
    return -1;
    return superior->numero;
}

//Operación push
void agregar(int numero) 
{
  // Reservamos memoria para el nuevo nodo, que se agregará a la pila
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  // Asignamos el valor del nuevo nodo
  nuevoNodo->numero = numero;
  // Y ahora el nuevo nodo es el superior, y su siguiente es el que antes era el superior
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}

// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void) 
{
  printf("elemento eliminado.\n"); //Para confirmar que el elemento fue eliminado
  if (superior != NULL) {
    // Para liberar la memoria más tarde debemos referencias al espacio de memoria del nodo a eliminar y asi no equivocadamente eliminar el que sigue
    struct nodo *temporal = superior;
    // Ahora superior es a lo que apuntaba su siguiente
    superior = superior->siguiente;

    // Liberar memoria que estaba ocupando el que eliminamos (la referencia de memoria)
    free(temporal);
  }
}

//Función para imprimir la pila
void imprimirPila(void) 
{
  printf("Imprimiendo pila ...\n\n");
  struct nodo *temporal = superior; // Guardamos el nodo superior en una variable temporal
  //Mientras el nodo temporal no sea nulo, imprimimos su valor y movemos el puntero al siguiente nodo
  while (temporal != NULL) {
    printf("%d\n", temporal->numero);
    temporal = temporal->siguiente;
  }
  printf("\n");
}

//Función para imprimir arreglo utilizado para el ordenamiento, le pasamos el arreglo y el número de elementos que contiene
void imprimirArreglo(int arr[], int n) 
{
   // Navegar a tráves de todos los elementos del arreglo
   for(int i = 0;i < n ;i++) 
   {
      printf("%d ", arr[i]);
   }
	
   printf("\n\n");
}

//Función para ordenar por selección, le pasamos el arreglo y el número de elementos que contiene
void ordenamiento_por_Inserccion(int arr[], int n) 
{
   int valor_a_insertar;
   int posicion_a_insertar;
  
   // Ciclo a tráves de todos los números del arreglo
   for(int i = 1; i < n; i++) 
   { 
      // Selecciona un valor para ser insertado 
      valor_a_insertar = arr[i];
		
      // Selecciona el espacio donde el valor será insertado 
      posicion_a_insertar = i;
		
      // Comprobar si el anterior no es mayor que el valor a insertar 
      while (posicion_a_insertar > 0 && arr[posicion_a_insertar-1] > valor_a_insertar) 
      {
         arr[posicion_a_insertar] = arr[posicion_a_insertar-1];
         posicion_a_insertar--;
      }

      if(posicion_a_insertar != i) 
      {
         // Inserte el número en la posición del agujero
         arr[posicion_a_insertar] = valor_a_insertar;
      }
   }  
}
