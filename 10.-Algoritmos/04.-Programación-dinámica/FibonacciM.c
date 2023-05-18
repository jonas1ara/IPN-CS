#include <stdio.h>

#define MAX 100
int fib[MAX];

int fibM(int n)
{
    if (fib[n] != -1)
    {
        return fib[n];
    }

    if (n <= 1)
    {
        fib[n] = n;
    }
    else
    {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return fib[n];
}

int main()
{
    int n = 10;
    for (int i = 0; i < MAX; i++)
    {
        fib[i] = -1;
    }

    int result = fibM(n);
    printf("El término %d de Fibonacci es: %d\n", n, result);
    return 0;
}
