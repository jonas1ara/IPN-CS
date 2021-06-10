/*
	Nombre del programa: mcd.c 
	Fecha: 6/10/21
	Autor: Adrián Jonás Lara Carvente
	Descripción breve: Este programa cálcula el Máximo Común Divisor de dos números con el 
					   algoritmo de Euclides.
*/


#include <stdio.h>

int main()
{
	int a,b,q,r; //Declaramos variables enteras.

	printf("Este programa cálcula el Máximo Común Divisor de dos números con el algoritmo de Euclides, por la naturaleza del algoritmo, introduce primero el valor mayor\n"); //Ilustramos al usuario
	printf("\nIngrese el valor de a:\n");
	scanf("%d",&a); //Almacenamos el valor introducido en la variable a
	printf("Ingrese el valor de b:\n");
	scanf("%d",&b); //Almacenamos el valor introducido en la variable b
	
	if((b<=a)&&(a>0)&&(b>0)) //Condicionamos haciendo uso de la compuerta lógica AND
	{
		printf("\nEntonces\n"); //Este printf confirma que el programa cumple la primera condición
	} 
	if((b<=a)&&(a>0)&&(b>0)) //Volvemos a hacer uso de la misma condición
	{
		q=a/b; //Asignamos a q el valor de la división entre a y b
		r=a%b; //Asignamos a r el valor del residuo de la división entre a y b

		printf("a = %d / b = %d tiene cociente(q) = %d y residuo(r) = %d",a,b,q,r);		
		
		if(r==0) //Si el residuo es igual a cero
		{
			printf("\nmcd(%d,%d) = %d",a,b,b); //Imprime los valores de a,b,b en pantalla
		}	else //Si esto no se cumple, entonces entrara a un ciclo
			{
				while(r>0) //Ciclo que se repetira mientras el residuo sea mayor a 0
				{
					printf("\nmcd(%d,%d)=",a,b); //Imprimira el valor de a y b, nadamas.
					a=b; //Asignamos el valor de b a a
					b=r; //Asignamos el valor de r a b
					q=a/b; //Otra vez se realiza la división a entre b
					r= a%b; //Y se asigna al valor de r el residuo de la división
					
					if(r==0) //Si dicho residuo es cero
					{
						printf("\nmcd(%d,%d)=%d",a,b,b); //Entonces Imprimir el Máximo Común Divisor
					}
				}
			}
	}	else
		{
			printf("Los datos introducidos son incorrectos\n"); //Si no se cumple que el primer valor sea mayor
		}

	return 0;

}

