#include <stdio.h>

double mochilaVoraz(int capacidad, int pesos[], double valores[], int n) {
    // Cálculo del valor por unidad de peso de cada objeto
    double valoresPorPeso[n];
    int i;
    for (i = 0; i < n; i++) {
        valoresPorPeso[i] = valores[i] / pesos[i];
    }

    // Ordenar los objetos en orden descendente según su valor por unidad de peso
    for (i = 0; i < n - 1; i++) {
        int maxIndex = i;
        int j;
        for (j = i + 1; j < n; j++) {
            if (valoresPorPeso[j] > valoresPorPeso[maxIndex]) {
                maxIndex = j;
            }
        }
        // Intercambiar los valores por unidad de peso y los arreglos correspondientes
        double tempValorPorPeso = valoresPorPeso[maxIndex];
        valoresPorPeso[maxIndex] = valoresPorPeso[i];
        valoresPorPeso[i] = tempValorPorPeso;

        int tempPeso = pesos[maxIndex];
        pesos[maxIndex] = pesos[i];
        pesos[i] = tempPeso;

        double tempValor = valores[maxIndex];
        valores[maxIndex] = valores[i];
        valores[i] = tempValor;
    }

    // Realizar el llenado de la mochila
    double valorMaximo = 0.0;
    int pesoActual = 0;
    i = 0;
    while (pesoActual < capacidad && i < n) {
        if (pesoActual + pesos[i] <= capacidad) {
            pesoActual += pesos[i];
            valorMaximo += valores[i];
        } else {
            int pesoRestante = capacidad - pesoActual;
            valorMaximo += valoresPorPeso[i] * pesoRestante;
            pesoActual = capacidad;
        }
        i++;
    }

    return valorMaximo;
}

int main() {
    int capacidad = 50;
    int pesos[] = {10, 20, 30};
    double valores[] = {60.0, 100.0, 120.0};
    int n = sizeof(valores) / sizeof(valores[0]);

    double valorMaximo = mochilaVoraz(capacidad, pesos, valores, n);
    printf("Valor máximo obtenido: %.2f\n", valorMaximo);

    return 0;
}
