#include <stdio.h>
#include <math.h>

double calcularDistancia(int x1, int y1, int x2, int y2)
{
    /*
        Aplicar la fórmula que dice:
        distancia = raiz_cuadrada_de(elevar_al_cuadrado(x1-x2) + elevar_al_cuadrado(y1-y2))
        Nota: no importa el orden de los puntos ni si la distancia al restar es negativa
    */
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(int argc, char const *argv[])
{
    int x1 = 3, y1 = -4;
    int x2 = 6, y2 = 0;
    double distancia = calcularDistancia(x1, y1, x2, y2);
    printf("La distancia entre %d,%d y %d,%d es %lf", x1, y1, x2, y2, distancia);
    return 0;
}