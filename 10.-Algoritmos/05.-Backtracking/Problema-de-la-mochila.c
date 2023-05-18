#include <stdio.h>

// Función auxiliar para calcular el máximo de dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función auxiliar para realizar el backtracking
void mochilaBacktracking(int capacidad, int pesos[], int valores[], int n, int indice, int pesoActual, int valorActual, int* valorMaximo) {
    // Caso base: si se alcanza el final de los objetos o la capacidad se agota
    if (indice == n || pesoActual == capacidad) {
        *valorMaximo = max(*valorMaximo, valorActual);
        return;
    }

    // Si el objeto actual no excede la capacidad, se considera incluirlo
    if (pesoActual + pesos[indice] <= capacidad) {
        mochilaBacktracking(capacidad, pesos, valores, n, indice + 1, pesoActual + pesos[indice], valorActual + valores[indice], valorMaximo);
    }

    // Se excluye el objeto actual y se pasa al siguiente
    mochilaBacktracking(capacidad, pesos, valores, n, indice + 1, pesoActual, valorActual, valorMaximo);
}

int main() {
    int capacidad = 50;
    int pesos[] = {10, 20, 30};
    int valores[] = {60, 100, 120};
    int n = sizeof(valores) / sizeof(valores[0]);
    int valorMaximo = 0;

    mochilaBacktracking(capacidad, pesos, valores, n, 0, 0, 0, &valorMaximo);
    printf("Valor máximo obtenido: %d\n", valorMaximo);

    return 0;
}
