#include<stdio.h>

int main()
{
    int N = 101;
    int num = N;
    int dec=0;
    int base = 1;
    while(N!=0) //101 no es igual a cero
    {
        int rem = N%10;
        dec = dec+rem*base;
        base = base*2;
        N = N/10;
    }
    printf("La equivalencia decimal de %d es %d",num,dec);
}