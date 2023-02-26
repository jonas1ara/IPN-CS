#include <stdio.h>  
#include <string.h>

int main () 
{

	char texto[20];//Declaro la variable de tipo char texto con un máximo de 20 carácteres. 
	int i, j; //Declaro variables i y j como enteros.
	printf("Este programa convierte cualquier carácter a binario\n");
	printf("Introduzca su carácter u oracion de 20 carácteres máximo: "); //Le pido al usuario 
	scanf("%[^\n]",&texto); //Ocupamos %[^\n] para poder hacer la lectura de caracteres y hacemos uso de salto de página. 
	fflush(stdin); //Limpiamos la memoria 
	char *str = texto; //El valor de texto se lo asigno a *str
	int largo = strlen(str);//Ocupo la funcion strlen ya que devuelve el número. 

	for (i = 0; i < largo; i++) //Iniciamos un ciclo for para recorrer
	 {
	   for(j=7;j>=0;j--)//Impresión binaria de 0 a 7 porque esos son los números de bits.
		{
			if((str[i]>>j&1)==1) //Condición para imprimir 1 o 0.
			  printf("1"); 
			else 
			  printf("0"); 
		}
	  printf(" = %c  \n", str[i] ); //Imprimimos nuestra cadena de caracter
	}
	
	return 0;
}
