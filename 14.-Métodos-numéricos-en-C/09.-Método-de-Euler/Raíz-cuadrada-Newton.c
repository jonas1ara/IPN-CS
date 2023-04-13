#include <stdio.h>

double valorAbsoluto(double numero)
{
    if (numero < 0)
    {
        return numero * -1;
    }
    return numero;
}

double raizCuadrada(int numero)
{
    double margen = 0.000001;
    double estimacion = 1.0;
    // Mientras haya una diferencia notable.
    // Es decir, que el cuadrado de nuestra estimación difiera mucho del número
    while (valorAbsoluto((estimacion * estimacion) - numero) >= margen)
    {
        double cociente = numero / estimacion;
        double promedio = (cociente + estimacion) / 2.0;
        // Elimina la siguiente línea si no quieres ver el proceso
        printf("Estimación: %lf. Cociente: %lf. Promedio: %lf\n", estimacion, cociente, promedio);
        estimacion = promedio;
    }
    return estimacion;
}

int main(int argc, char const *argv[])
{
    int numero;
    printf("Ingresa un número: ");
    scanf("%d", &numero);
    double raiz = raizCuadrada(numero);
    printf("La raíz cuadrada de %d es %lf", numero, raiz);
    return 0;
}