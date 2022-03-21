#include <stdio.h>

int main()
{
    int i, j, n;

    printf("Ingrese altura de la piramide: \n");
    scanf("%d",&n);

    for (i = 0; i <= n; i++)
    {
        for (j = 1; j <= n-i; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
            
    }
}
