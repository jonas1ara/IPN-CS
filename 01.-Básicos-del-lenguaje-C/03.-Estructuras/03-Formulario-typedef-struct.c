#include <stdio.h>

typedef struct {
    char nombre[50];
    char empleo[50];
    int edad;
} reg;

int main()
{
    reg f1, f2;

    //Instancia 1 del formulario
    printf("Introduce valores para el formulario 1: \n");
    printf("Ingrese el nombre: ");
    fgets(f1.nombre, 50, stdin);

    printf("Ingrese el empleo: ");
    fflush(stdin);
    fgets(f1.empleo, 50, stdin);

    printf("Ingrese la edad: ");
    scanf("%d", &f1.edad);

    //Instancia 2 del formulario
    printf("Introduce valores para el formulario 2: \n");
    printf("Ingrese el nombre: ");
    fflush(stdin);
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