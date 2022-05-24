#include <stdio.h>
#define PI 3.14159265358979323846

double gradosARadianes(double grados)
{
    return grados * PI / 180;
}

double radianesAGrados(double radianes)
{
    return radianes * 180 / PI;
}

int main()
{
    // Probar. 1 radián equivale a 57.2958 grados
    double radianes = 1;
    double convertidosAGrados = radianesAGrados(radianes);
    printf("%.4f radianes equivalen a %.4f grados\n", radianes, convertidosAGrados);
    // Y lo inverso
    double grados = 57.2958;
    double convertidoARadianes = gradosARadianes(grados);
    printf("%.4f grados equivalen a %.4f radianes\n", grados, convertidoARadianes);
    return 0;
}