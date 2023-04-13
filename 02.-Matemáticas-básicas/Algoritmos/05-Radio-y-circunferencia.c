#include <stdio.h>
// Definir PI si no existe

#include <math.h>
#ifndef MPI
#define MPI 3.14159265358979323846
#endif

int main()
{
    double diametro = 0;
    printf("Ingresa el diámetro:");
    scanf("%lf", &diametro);
    double circunferencia = diametro * MPI;
    double radio = diametro / 2;
    printf("La circunferencia es %.2lf y el radio es %.2lf", circunferencia, radio);
}