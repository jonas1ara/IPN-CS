/*
	Ciclo Do While 
	
	Es una estructura de control cíclica que permite ejecutar de manera repetitiva un bloque
	de instrucciones sin evaluar de forma inmediata una condición especifica, sino evaluándola 
	justo después de ejecutar por primera vez el bloque de instrucciones 
*/

#include<stdio.h>

int main()
{	
	int contador = 1; // Se inicializa el entero contador en 1

	do //Bloque a ejecutar de forma inmediata
	{
		printf("%i\n",contador);
		contador++; //Adherir 1 a contador
		
	} while(contador <=10); //Condicionar el bloque anterior
	
	return 0;
}
