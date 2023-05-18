#include <stdio.h>

// Función para calcular el máximo de dos números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Función para resolver el problema de la mochila mediante programación dinámica
int mochilaDinamica(int capacidad, int pesos[], int valores[], int n)
{
    int tabla[n + 1][capacidad + 1];

    // Se construye la tabla de programación dinámica
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacidad; w++)
        {
            if (i == 0 || w == 0)
                tabla[i][w] = 0;
            else if (pesos[i - 1] <= w)
                tabla[i][w] = max(valores[i - 1] + tabla[i - 1][w - pesos[i - 1]], tabla[i - 1][w]);
            else
                tabla[i][w] = tabla[i - 1][w];
        }
    }

    return tabla[n][capacidad];
}

int main()
{
    int capacidad = 50;
    int pesos[] = {10, 20, 30};
    int valores[] = {60, 100, 120};
    int n = sizeof(valores) / sizeof(valores[0]);

    int valorMaximo = mochilaDinamica(capacidad, pesos, valores, n);
    printf("Valor máximo obtenido: %d\n", valorMaximo);

    return 0;
}


