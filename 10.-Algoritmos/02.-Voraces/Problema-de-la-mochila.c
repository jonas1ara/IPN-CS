#include <stdio.h>

int mochilaVoraz(int capacidad, int pesos[], int valores[], int n)
{
    // Cálculo del valor por unidad de peso de cada objeto
    int valoresPorPeso[n];
    int i;
    for (i = 0; i < n; i++)
    {
        valoresPorPeso[i] = valores[i] / pesos[i];
    }

    // Ordenar los objetos en orden descendente según su valor por unidad de peso
    for (i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (valoresPorPeso[j] > valoresPorPeso[maxIndex])
            {
                maxIndex = j;
            }
        }
        // Intercambiar los valores por unidad de peso y los arreglos correspondientes
        int tempValorPorPeso = valoresPorPeso[maxIndex];
        valoresPorPeso[maxIndex] = valoresPorPeso[i];
        valoresPorPeso[i] = tempValorPorPeso;

        int tempPeso = pesos[maxIndex];
        pesos[maxIndex] = pesos[i];
        pesos[i] = tempPeso;

        int tempValor = valores[maxIndex];
        valores[maxIndex] = valores[i];
        valores[i] = tempValor;
    }

    // Realizar el llenado de la mochila
    int valorMaximo = 0;
    int pesoActual = 0;
    i = 0;
    while (pesoActual < capacidad && i < n)
    {
        if (pesoActual + pesos[i] <= capacidad)
        {
            pesoActual += pesos[i];
            valorMaximo += valores[i];
        }
        else
        {
            int pesoRestante = capacidad - pesoActual;
            valorMaximo += valoresPorPeso[i] * pesoRestante;
            pesoActual = capacidad;
        }
        i++;
    }

    return valorMaximo;
}

int main()
{
    int capacidad = 50;
    int pesos[] = {10, 20, 30};
    int valores[] = {60, 100, 120};
    int n = sizeof(valores) / sizeof(valores[0]);

    int valorMaximo = mochilaVoraz(capacidad, pesos, valores, n);
    printf("Valor máximo obtenido: %d\n", valorMaximo);

    return 0;
}
