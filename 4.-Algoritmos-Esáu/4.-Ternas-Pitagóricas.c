/*
	- Nombre del programa: Triángulo con lados enteros
	- Fecha: 02/05/2021
	- Autor: Adrián Jonas Lara Carvente
	- Descripción breve: Este programa encuentra todos los triángulos rectángulos diferentes con lados enteros en los que la suma de los lados no sea mayor a n, donde n es un valor dado por el usuario.

*/


#include <stdio.h>

int main(){
	
	int i,j,k,n,sum,l1,l2,hip; //Inicializan variables
	
	printf("\nEste programa encuentra todos los triángulos rectángulos diferentes con lados enteros en los que la suma de los lados no sea mayor a n, donde n es un valor dado por ti.\n");
	
	printf("\nAsi que, dame el valor de n: "); //Pide el valor de n
	scanf("%d",&n);
	
	for(i = 1; i <= n; i++){ //Primer for para hipotenusa
		hip= i * i ; //Se eleva al cuadrado
		
		for(j=1; j <= n; j++){ //Segundo for para lado 1
			l1 = j * j; //Se eleva al cuadrado
			
			for(k = 1; k <= n; k++){ //Tercer for para lado 2
				l2= k * k ; //Se eleva al cuadrado

				sum = l1 + l2; //Se suman los lados, con el valor ya elevado al cuadrado
				
				if(sum == hip){ //Si el valor de la suma del cuadrado de lo lados es igual al cuadrado de la hipotenusa 
					printf("\nLado 1: %d  |",j); 
					printf("  Lado 2: %d  |",k);
					printf("  Hipotenusa: %d \n",i);
				}
			}
		}
	}	
	printf("\nEsos son todos los triángulos rectángulos diferentes con lados enteros en los que la suma de los lados no es mayor a %d, adios humano. \n",n);	
	printf("\n"); //Fin del programa :)
	return 0;
}
