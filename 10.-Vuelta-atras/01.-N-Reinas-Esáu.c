/*
	OchoReinas.cpp
	21/09/21
	Esau Escobar
	Programa que resuelve el problema de las 8 reinas
*/
#include<stdio.h>
#include<stdlib.h>

//Prototipos de funciones
int *crearArreglo(int);
void reinas(int,int*,int*,int*,int*);

int n_reinas = 0;

int main(void){
	//Declaracion de apuntadores para el arreglo
	int *columnas,*filas,*diagonalN,*diagonalI;
	
	//Crear los arreglos
	columnas = crearArreglo(8);
	filas = crearArreglo(8);
	diagonalN = crearArreglo(15);
	diagonalI = crearArreglo(15);
	
	//Inicializar arreglos
	for(int i=0;i<8;i++){
		columnas[i]=-1;
		filas[i]=0;
	}
	for(int i=0;i<15;i++){
		diagonalN[i]=0;
		diagonalI[i]=0;
	}
	
	reinas(0,columnas,filas,diagonalN,diagonalI);
	
	//Mostrar el tablero
	printf("\nTABLERO\n");
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j==columnas[i])
				printf(" R ");
			else
				printf(" - ");
		}
		printf("\n");
	}
	
	return 0;
}

int *crearArreglo(int tam){
	int *arreglo;
	arreglo =(int *)malloc(sizeof(int) *tam);  
	return arreglo;
}

void reinas(int i,int *columnas, int *filas, int *diagonalN, int *diagonalI){
	for(int j=0;j<8;j++){ //Controla las filas
		//Verificar si hay reina en la fila o diagonales
		if( (!filas[j]) && (!diagonalN[i-j+7]) && (!diagonalI[i+j]) ){
			//Colocar una reina
			columnas[i] = j;
			filas[j] = 1;
			diagonalN[i-j+7] = 1;
			diagonalI[i+j] = 1;
			n_reinas++;
			//Hay mas reinas por colocar?
			if(i<7){
				reinas(i+1,columnas,filas,diagonalN,diagonalI); //Recursivamente colocar otra reina
				if(n_reinas<8){ //No pude colocar las 8 reinas entonces
					//Retirar la reina colocada en este nivel
					filas[j] = 0;
					diagonalN[i-j+7] = 0;
					diagonalI[i+j] = 0;
					n_reinas--;
				}
			}
		}
	}
}
