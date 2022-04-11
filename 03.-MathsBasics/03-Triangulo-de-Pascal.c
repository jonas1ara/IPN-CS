/*
    Escribir un programa que se permita visualizar el triangulo de pascal.
    En el triángulo de pascal cada número es la suma de los dos
    números situados encima de él.

    -Utiliza una matriz de una dimensión
*/

#include <stdio.h>

// Declaración de las funciones a utilizar
unsigned factorial(unsigned);

int main()
{
   //Variables a utilizar
    int filas = 0;
    int columnas = 0;
    int contador = 0;
    int posicion = 0;
    int f = 0;
    int c = 0;
    int calculo = 0;
    
    printf("Dame el número de filas: ");
    scanf("%d", &filas);

    //Para calcular el numero de elementos del vector realizamos el sumatorio del numero de filas
    for (contador = filas-1; contador >=0 ; contador--)
    {
        columnas+=contador;
    }
    
    //Creamos el vector donde guardar los valores

    int triangulo[columnas];
    //recorremos el vector realizando el calculo del valor, utilizando el numero combinatorio

    for (f = 0; f<filas-1; f++)
    {
        for (c = 0; c <= f; c++)
        {
            // se calcula el valor del numero en el vector utilizando el numero combin.

            calculo = factorial(f)/(factorial(c)*factorial(f-c));
            // se asigna el valor a la posicion del vector que corresponde
            triangulo[posicion]=calculo;
            posicion++;
        }
    }
    //Visualizar el triangulo de pascal
    posicion = 0;
    for (f = 0; f < filas-1; f++)
    {
        printf("\n%*c",(int)(columnas/2)-f,' ');
        for (c = 0; c <= f; c++)
        {
            printf("%d ",triangulo[posicion]); 
            posicion++;
        }
    }
    
    return 0;
}

//Función factorial que devuelve el resultado del factorial de un numero sin utilizar recursividad
unsigned factorial(unsigned numero)
{
    int resultado = 0;
    int contador = 0;
    if (numero == 0)
    {
        resultado =1;
    }
    else
    {
        resultado=1;
        for ( contador = numero; contador > 0; contador--)
        {
            resultado*=contador;
        }
    }
    return resultado;
}