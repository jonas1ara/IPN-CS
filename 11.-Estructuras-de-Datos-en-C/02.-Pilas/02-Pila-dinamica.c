/*
Estructuras de datos en C: implementación de pila de enteros
Recuerda que el último en entrar es el primero en salir
LIFO: https://es.wikipedia.org/wiki/Last_in,_first_out
Basado en las operaciones que dice la Wikipedia:
https://es.wikipedia.org/wiki/Pila_(inform%C3%A1tica)#Operaciones
@author parzibyte
Visita: parzibyte.me
*/
#include <stdio.h>   // printf
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos

// Un nodo tiene un dato, el cual es el número. Y otro nodo al que apunta
struct nodo {
  int numero;
  struct nodo *siguiente;
};

// Prototipos de funciones
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void); // El tamaño de la pila
bool vacia(void);  // Indica si la pila está vacía
int ultimo(void);  // El último elemento. Devuelve 0 si no hay elementos

// Todo comienza con el nodo superior
struct nodo *superior = NULL;

int main() {
  int eleccion;
  int numero;
  while (eleccion != -1) {
    printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir "
           "pila\n4.- Imprimir tamaño\n5.- Comprobar si está vacía\n6.- "
           "Mostrar último elemento\n-1.- Salir\n\n\tElige: ");
    scanf("%d", &eleccion);
    switch (eleccion) {
    case 1:
      printf("Ingresa el número que agregaremos:\n");
      scanf("%d", &numero);
      agregar(numero);
      break;
    case 2:
      eliminarUltimo();
      break;
    case 3:
      imprimir();
      break;
    case 4:
      printf("La pila mide %d\n", tamanio());
      break;
    case 5:
      if (vacia()) {
        printf("La pila está vacía\n");
      } else {
        printf("La pila NO está vacía\n");
      }
      break;
    case 6:
      printf("El último elemento es: %d\n", ultimo());
      break;
    }
  }
}

int tamanio(void) {
  int contador = 0;
  if (superior == NULL)
    return contador;
  struct nodo *temporal = superior;
  while (temporal != NULL) {
    contador++;
    temporal = temporal->siguiente;
  }
  return contador;
}

bool vacia(void) { return superior == NULL; }

int ultimo() {
  if (superior == NULL)
    return -1;
  return superior->numero;
}

// Operación push
void agregar(int numero) {
  printf("Agregando %d\n", numero);
  // El que se agregará; reservamos memoria
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  // Le ponemos el dato
  nuevoNodo->numero = numero;
  // Y ahora el nuevo nodo es el superior, y su siguiente
  // es el que antes era superior
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}

void imprimir(void) {
  printf("Imprimiendo...\n");
  struct nodo *temporal = superior;
  while (temporal != NULL) {
    printf("%d\n", temporal->numero);
    temporal = temporal->siguiente;
  }
}

// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void) {
  printf("Eliminando el último\n");
  if (superior != NULL) {
    // Para liberar la memoria más tarde debemos
    // tener la referencia al que vamos a eliminar
    struct nodo *temporal = superior;
    // Ahora superior es a lo que apuntaba su siguiente
    superior = superior->siguiente;

    // Liberar memoria que estaba ocupando el que eliminamos
    free(temporal);
  }
}
