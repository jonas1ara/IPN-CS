#include <stdio.h>
#include <math.h>

int main()
{
    printf ("¯  _(ツ)_/¯"); 

    //Funciones trigonometricas
    double valor = 0.5;

    printf("%d", sin(valor));
    printf("%d", cos(valor));
    printf("%d", tan(valor));

    //Funciones trigonometricas inversas
    printf("%d", asin(valor));
    printf("%d", acos(valor));
    printf("%d", atan(valor));

    //Funciones logaritmicas
    printf("%d", log(valor));
    printf("%d", log10(valor));
    
    //Funciones de raíz
    printf("%d", sqrt(valor)); //Raíz cuadrada
    printf("%d", cbrt(valor)); //Raíz cubica

    //Funciones de potencia
    printf("%d", pow(valor, 2));

    //Funciones de redondeo
    printf("%d", round(valor));
    printf("%d", ceil(valor));
    printf("%d", floor(valor));

    //Funciones hiperbólicas
    printf("%d", sinh(valor));
    printf("%d", cosh(valor));
    printf("%d", tanh(valor));

    //Otras funciones que tambien se pueden usar
    printf("%d", hypot(3,2)); //Damos los valores (a,b) para calcular la hipotenusa
    printf("%d", fabs(valor)); //Devuelve el valor absoluto
    printf("%d", fmod(valor, 2)); //Devuelve el resto de la division
    printf("%d", frexp(valor, &valor)); //Devuelve el exponente y el resto de la division
    printf("%d", ldexp(valor, 2)); //Devuelve el valor multiplicado por el exponente
    printf("%d", modf(valor, &valor)); //Devuelve el parte entera y el resto de la division
    printf("%d", fmax(valor, 2)); //Devuelve el mayor valor
    printf("%d", fmin(valor, 2)); //Devuelve el menor valor
    printf("%d",ceilf(valor)); //Devuelve el valor entero mas cercano
    printf("%d",floorf(valor)); //Devuelve el valor entero mas cercano    


    return 0;
}