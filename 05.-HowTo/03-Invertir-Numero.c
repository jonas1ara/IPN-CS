#include <stdio.h>

int main()
{
    int numero, resto , invertir = 0;
    
    printf("Dame un número:\n");
    scanf("%d", &numero); //721
    
    while(numero!=0) //721 != 0
    {
        resto = numero%10; //.1 , .2, .7
        numero = numero/10; //72.1, 7.2, 0 << se termina la condición del while
        
        invertir = invertir*10+resto;
        //1ra pasada: 0 * 10 = 0 + 1 = 1
        //2da pasada: 1 * 10 = 10 + 2 = 12
        //3ra pasada: 12 * 10 = 120 + 7 = 127
    }
    
    printf("El numero invertido es: %d\n",invertir);

    return 0;

}