#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int x=0;

//Aca comprobamos si la reina esta colocado en una posicion valida
//para que la posicion sea valida las reinas no deben en la misma columna
//y tampoco pueden estar en la misma fila, ni diagonal
bool comprobar(int reinas[],int n, int k){
	int i;
	for(i=0;i<k;i++){
		if( (reinas[i]==reinas[k]) || (abs(k-i) == abs(reinas[k]-reinas[i]))){
			return false;
		}
	}
	return true;
}
	
void Nreinas(int reinas[],int n, int k){
	//este es el caso base que me indica que se ha encontrado una solucion
	//por lo cual ya no hay mas reinas por colocar.Hemos logrado poner
	//todas las reinas en el tablero deajerdrez
	if(k==n){
		//print(reinas,n);
		x++;
		printf("Solucion: %d", x);
		for(int i=0;i<n;i++){
			printf("%d", reinas[i];
		}
		printf("\n");
		
	}
	//aun quedan reinas por colocar y el algoritmo debe seguir buscando
	else{
		for(reinas[k]=0;reinas[k]<n;reinas[k]++){
			if(comprobar(reinas,n,k)){
				Nreinas(reinas,n,k+1);
			}
		}
	}
}
		
int main(int argc, char *argv[]) {
	int k=0;
	int cant;
	printf("Ingresar la cantidad de reinas : ");
	scanf("%d", &cant);

	int *reinas = int[cant];

	for(int i=0;i<cant;i++){
		reinas[i]=-1;
	}

	Nreinas(reinas,cant,k);

	return 0;
}