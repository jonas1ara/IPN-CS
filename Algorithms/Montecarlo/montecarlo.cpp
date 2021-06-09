#include <iostream>
#include <stdlib.h> // funcion de numero aleatorio: rand()
#include <time.h> // para dar valor a srand(), para el nº aleatorio
using namespace std;

int main()
{
    srand(time(0));
    long double pi;
    long double x, y; // serán las coordenadas aleatorias
    long double numeros_dentro = 0;
    long double n; // cantidad de numeros aleatorios generados

    cout << "Este programa calcula una aproximacion al numero pi con el metodo de Montecarlo." << endl;
    cout << "Consiste en generar puntos aleatorios en un cuadrado con un circulo inscrito en el, y luego ver la proporcion de puntos que esta en el circulo." << endl;
    cout << "Cuando el numero de puntos tiende a infinito, esa proporcion es pi/4" << endl;

    cout << "\nIntroduce el numero de puntos aleatorios generados (a mas puntos, mas precision, pero tambien mas tiempo de espera): ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        x = (long double)rand()/(long double)(RAND_MAX); // generar numero aleatorio de tipo double entre 0 y 1
        y = (long double)rand()/(long double)(RAND_MAX);
        // Teniendo en cuenta el lugar geometrico del circulo (x^2+y^2=r^2), podemos saber si (x,y) está dentro del circulo
        if (x*x+y*y <= 1)
        {
            numeros_dentro += 1;
        }
    }
    pi = (numeros_dentro/n)*4.0;
    cout << "\nAproximadamente, generando " << n << " puntos, pi es " << pi;
    return 0;
}
