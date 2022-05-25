#include<stdio.h>

int main()
{
    char str[1000]= "TUF"; //Arreglo str con espacio para 1000 elementos 
    int i=0; 
    int count=0;
    while(str[i]!='\0') //En C, el último carácter de una cadena es el delímetro o '\0'. También se pronuncia como "Backslash zero".
    {
        count++; //Va contando cuantas veces se atraviesa, lo que es igual al tamaño de la cadena
        i++; //Va a atravesando el Arreglo hasta que llegue al ultimo carácter 
    }
    printf("El ancho de la cadena es: %d\n",count);

}
