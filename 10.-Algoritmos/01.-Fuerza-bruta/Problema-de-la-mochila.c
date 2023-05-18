#include <stdio.h>

// Función auxiliar para calcular el máximo de dos números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Función para resolver el problema de la mochila mediante fuerza bruta
int mochilaFuerzaBruta(int capacidad, int pesos[], int valores[], int n)
{
    // Caso base: si no hay objetos o no hay capacidad, el valor es 0
    if (n == 0 || capacidad == 0)
        return 0;

    // Si el peso del objeto actual excede la capacidad, se excluye
    if (pesos[n - 1] > capacidad)
        return mochilaFuerzaBruta(capacidad, pesos, valores, n - 1);

    // Se devuelve el máximo entre incluir el objeto actual y excluirlo
    return max(valores[n - 1] + mochilaFuerzaBruta(capacidad - pesos[n - 1], pesos, valores, n - 1),
               mochilaFuerzaBruta(capacidad, pesos, valores, n - 1));
}

int main()
{
    int capacidad = 50;
    int pesos[] = {10, 20, 30};
    int valores[] = {60, 100, 120};
    int n = sizeof(valores) / sizeof(valores[0]);

    int valorMaximo = mochilaFuerzaBruta(capacidad, pesos, valores, n);
    printf("Valor máximo obtenido: %d\n", valorMaximo);

    return 0;
}
