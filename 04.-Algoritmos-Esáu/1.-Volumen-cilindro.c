//Librería que contiene las funciones scanf y printf
#include <stdio.h>
//Función principal
int main ()
{
    // Este programa calcula el volumen de un cilindro conociendo su radio y su altura
    printf("Este programa cálcula el volumen de un cilindro conociendo su radio y su altura\n");
    // Variables de mi función
    float radio, altura, volumen;
    printf("Escribe el radio del cilindro: ");
    //Guardo el radio en la variable flotante radio
    scanf("%f", &radio);
    //Pido la altura del cilindro
    printf("Escribe la altura del cilindro: ");
    //Guardo la altura en la variable flotante
    scanf("%f", &altura);
    //Calculo el volumen
    volumen= 3.14159 * radio * radio * altura;
    //Imprimo el resultado
    printf("El volumen del cilindro es %.3f", volumen);
    printf("\n");

return 0;
}