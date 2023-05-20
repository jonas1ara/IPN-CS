#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Nodo {
    int clave;
    int valor;
    struct Nodo* siguiente;
};

void inicializarTabla(struct Nodo* tabla[]) {
    for (int i = 0; i < SIZE; i++) {
        tabla[i] = NULL;
    }
}

int funcionHash(int clave) {
    return clave % SIZE;
}

void insertar(struct Nodo* tabla[], int clave, int valor) {
    int indice = funcionHash(clave);

    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->clave = clave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = tabla[indice];
    tabla[indice] = nuevoNodo;
}

int buscar(struct Nodo* tabla[], int clave) {
    int indice = funcionHash(clave);

    struct Nodo* actual = tabla[indice];
    while (actual != NULL) {
        if (actual->clave == clave) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }

    return -1;
}

int main() {
    struct Nodo* tabla[SIZE];
    inicializarTabla(tabla);

    insertar(tabla, 10, 100);
    insertar(tabla, 20, 200);
    insertar(tabla, 30, 300);

    int resultado = buscar(tabla, 20);
    if (resultado == -1) {
        printf("El elemento no se encuentra en la tabla hash.\n");
    } else {
        printf("El valor asociado a la clave es %d.\n", resultado);
    }

    return 0;
}
