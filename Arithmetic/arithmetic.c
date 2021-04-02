#include <stdio.h>

int main(void) {
	
	int num1, num2, resultado;
	int a=2;
	int b=3;
	
	printf("Ingrese un número:\n");	
	scanf("%d",&num1);

	printf("Ingreso el segundo número:\n");
	scanf("%d",&num2);

	/*resultado = num1 / num2;*/ //Cambiar operador por cualquiera de los operadores aritméticos; suma, resta, división y multiplicación. Vuelve a compilar.
	
	resultado = a*(num1-num2) / b*(num1+num2);
	
	printf("El resultado de la operación es: %d\n", resultado);

	return 0;
}
