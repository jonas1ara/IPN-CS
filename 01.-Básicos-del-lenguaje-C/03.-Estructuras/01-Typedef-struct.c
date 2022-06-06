/*
	Un struct en C permite usar algo parecido a los objetos anónimos de OOP. No son clases, simplemente son
	un modo de agrupar un objeto de determinado tipo con ciertas propiedades.
*/

#include <stdio.h>

typedef struct
    {
        int paginas;
        char nombre[20];
        float precio;
    } libro;

int main()
{
    libro JT[10]; // Se define una estructura llamada libro renombrada JT

    for (int i = 0; i < 10; i++)
    {
        JT[i].precio = 25 + i;
        printf("El precio de la estructura %i es de %f\n",i+1, JT[i].precio);
    }
    
    // //Instancia del libro JT
    // JT.paginas = 200;
    // strcpy (JT.nombre, "Juego de tronos" );
    // JT.precio = 20.5;

    // //Instancia del libro CR
    // CR.paginas = 250;
    // strcpy (CR.nombre, "Choque de reinas" );
    // CR.precio = 30;

    // printf("El libro de juego de tronos tiene %d páginas\n", JT.paginas);
    // printf("El nombre del libro es %s\n", JT.nombre);
    // printf("El precio del libro es %.2f\n", JT.precio);

    // printf("El libro de juego de tronos tiene %d páginas\n", CR.paginas);
    // printf("El nombre del libro es %s\n", CR.nombre);
    // printf("El precio del libro es %.2f\n", CR.precio);


    return 0;
}