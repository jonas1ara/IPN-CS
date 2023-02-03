#include <iostream>
#include<stdio.h>
using namespace std;
int x=0;

//Aca comprobamos si la reina esta colocado en una posicion valida
//para que la posicion sea valida las reinas no deben en la misma columna
//y tampoco pueden estar en la misma fila, ni diagonal
bool comprobar(int reinas[],int n, int k){
	int i;
	for(i=0;i<k;i++){
		if( (reinas[i]==reinas[k]) or (abs(k-i) == abs(reinas[k]-reinas[i]))){
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
		cout<<"Solucion "<<x<<" : ";
		for(int i=0;i<n;i++){
			cout<<reinas[i]<<" , ";
		}
		cout<<endl;
		
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
	cout<<"Ingresar la cantidad de reinas : ";
	cin>>cant;

	int *reinas = new int[cant];

	for(int i=0;i<cant;i++){
		reinas[i]=-1;
	}

	Nreinas(reinas,cant,k);

	return 0;
}