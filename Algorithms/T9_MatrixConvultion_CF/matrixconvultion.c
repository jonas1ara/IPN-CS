/*
	Matrices.c
	20/05/2021
	Esaú Escobar
	Programa que multiplica dos matrices
*/

#include<stdio.h>

#define FilasA 3
#define ColumnasA 3
#define FilasB 3
#define ColumnasB 2

int main(){
	// Declaración de variables
	int matrizA[FilasA][ColumnasA] = {{3, 2, 1},
	                                  {1, 1, 3},
						              {0, 2 ,1}};
	
	int matrizB[FilasB][ColumnasB] = {{2, 1},
	                     			  {1, 0},
						              {3, 2}};
	
	int producto[FilasA][ColumnasB];
	int suma;
	
	//Mensaje de inicio
	printf("Este programa multiplica dos matrices\n\n");
	
	//Realizar la multiplicación utilizando ciclos anidados
	//Recorrer las filas de la matrizA
	for(int i=0; i<FilasA;i++){
		//Recorrer las columnas de la matrizB
		for(int j=0; j<ColumnasB;j++){
			suma = 0;
			//Recorrer las filas de B o columnas de A
			for(int k=0; k<ColumnasA; k++){
				suma += matrizA[i][k] * matrizB[k][j];
			}
			//Alamacenar el valor resultante
			producto[i][j] = suma;
		}
	}
	
	//Imprimir matrices
	printf("Matriz A = \n");
	//Recorrer filas
	for(int i=0;i<FilasA;i++){
		//Recorrer columnas
		for(int j=0;j<ColumnasA;j++){
			printf("%d ",matrizA[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz B = \n");
	//Recorrer filas
	for(int i=0;i<FilasB;i++){
		//Recorrer columnas
		for(int j=0;j<ColumnasB;j++){
			printf("%d ",matrizB[i][j]);
		}
		printf("\n");
	}
	//Imprimir el resultado
	printf("Producto = \n");
	//Recorrer filas
	for(int i=0;i<FilasA;i++){
		//Recorrer columnas
		for(int j=0;j<ColumnasB;j++){
			printf("%d ",producto[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
