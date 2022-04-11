/*
    // Los apuntadores son variables cuyos valores son direcciones de memoria.
    Cuando definimos una variable le asignamos un valor. Por ejemplo; una variable entera denominada "a".
    Así es como informamos al compilador dos cosas; el nombre y el tipo de dato, por lo que cuando
    encuentre la palabra reservada int, reserva 4 bytes de memoria 
    para almacenar el valor entero y al asignarle un valor 
    especificamos un espacio de memoria.
*/

#include <stdio.h>

int main() 
{
    
    int a = 4; //Variable entera llamada a que reserva 4 bytes de memoria
    int *apt = &a; //La variable apuntador se asigna con * y APUNTAMOS a nuestra variable a con & para referirnos a la valor alojado en esta variable
    printf("%p\n", apt); //Imprimir la dirección de memoria con %p, nos da la dirección de memoria como un entero hexadecimal*/
 
    return 0;

}