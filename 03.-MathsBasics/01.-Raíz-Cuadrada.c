#include <math.h>
#include <stdio.h>
<<<<<<< HEAD
int main(int argc, char const *argv[])
{
	double numero = 2525.60;
	double raizCuadrada = sqrt(numero);
	printf("La raiz cuadrada de %lf es %lf\n", numero, raizCuadrada);
	return 0;
=======

int main(int argc, char const *argv[])
{
    double numero;

    printf("Escribe un número y te dire su raíz cuadra\n");
    scanf("%lf", &numero);

    double raizCuadrada = sqrt(numero);
    printf("La raíz cuadrada de %lf  es %lf\n", numero, raizCuadrada);

    return 0;

>>>>>>> d6e7eaf2e4f2fb773748da1e66ee668ce1f72718
}