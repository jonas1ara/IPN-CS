#include <stdio.h>

int fibT(int n)
{
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main()
{
    int n = 10;
    int result = fibT(n);
    printf("El término %d de Fibonacci es: %d\n", n, result);
    return 0;
}
