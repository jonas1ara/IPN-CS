#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50]; //Vector de caracteres de 50 posiciones para el nombre
    char empleo[50]; //Vector de caracteres de 50 posiciones para el empleo
    int edad;
} reg;

int main()
{
    reg f1, f2; //Declaración de dos registros tipo reg

    //Instancia 1 del formulario
    printf("Introduce valores para el formulario 1: \n");
    printf("Ingrese el nombre: ");
    fgets(f1.nombre, 50, stdin); //función fgets lee una línea de texto y la guarda en un vector de caracteres
    //Lo guarda en la variable nombre de la estructura f1
    printf("Ingrese el empleo: ");
    fflush(stdin);
    fgets(f1.empleo, 50, stdin);
    //Lo guarda en la variable empleo de la estructura f1

    printf("Ingrese la edad: ");
    scanf("%d", &f1.edad); //Amperson para guarda la variable en la estructura f1

    //Instancia 2 del formulario
    printf("Introduce valores para el formulario 2: \n");
    printf("Ingrese el nombre: ");
    fflush(stdin); //Cuándo vamos a introducir una línea de texto, debemos borrar el buffer de entrada antes de introducir la línea de texto
    fgets(f2.nombre, 50, stdin);

    printf("Ingrese el empleo: ");
    fflush(stdin);
    fgets(f2.empleo, 50, stdin);

    printf("Ingrese la edad: ");
    scanf("%d", &f2.edad);

    printf("\nLos valores del formulario 1 son: \n");
    printf("Nombre: %s", f1.nombre);
    printf("Empleo: %s", f1.empleo);
    printf("Edad: %d\n", f1.edad);

    printf("\nLos valores del formulario 2 son: \n");
    printf("Nombre: %s", f2.nombre);
    printf("Empleo: %s", f2.empleo);
    printf("Edad: %d\n", f2.edad);

    return 0;
}