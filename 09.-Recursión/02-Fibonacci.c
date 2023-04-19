#include <stdio.h>

int fibonacci(int n)
{
    //Caso base
    if (n <= 1)
        return n;
    //Caso recursivo
    else
        return fibonacci(n -1) + fibonacci(n - 2);
}

int main()
{
    int n, resultado;

    printf("Dame un número: ");
    scanf("%d",&n);
    resultado = fibonacci(n);
    printf("Fibonacci del número %d es: %d\n", n, resultado);

    return 0;
}