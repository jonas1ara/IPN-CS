#include <stdio.h>

void invertir (int numero);

int main()
{
    int numero;    
    printf("Dame un número:\n");
    scanf("%d", &numero); 
    
    invertir(numero);

    return 0;
}

void invertir (int numero)
{
    int resto , invertir = 0;
    while(numero!=0) 
    {
        resto = numero%10; 
        numero = numero/10; 
        
        invertir = invertir*10+resto;
    }
    
    printf("El numero invertido es: %d\n",invertir);
}