#include <stdio.h>


int factorial(int n)
{
    //Caso base 
    if (n == 1)
    {
        return n;
    }
    //Caso recursivo
    else
    {
        return n * factorial (n - 1);
    }
}

int main()
{
    int n, resultado;

    printf("Dame un número: ");
    scanf("%d",&n);
    resultado = factorial(n);
    printf("El factorial del número %d es: %d\n", n, resultado);
    

    return 0;
}

