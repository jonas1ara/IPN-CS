#include<stdio.h>

void largoCadena(char str[]);

int main()
{
    char str[1000]= "TUF"; //Arreglo str con espacio para 1000 elementos 
    
    printf("La cadena es: %s\n",str);

    largoCadena(str);
    
    return 0;
}

void largoCadena(char str[])
{
    int i=0; 
    int count=0;
    while(str[i]!='\0') //En C, el último carácter de una cadena es el delímetro o '\0'. También se pronuncia como "Backslash zero".
    {
        count++; 
        i++;
    }
    printf("El ancho de la cadena es: %d\n",count);
}