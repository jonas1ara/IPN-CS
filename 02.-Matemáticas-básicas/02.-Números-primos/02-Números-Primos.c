#include <stdio.h>

int main() {
    int primos_por_mostrar, n;
    int es_primo;

    printf("Cuantos primos desea mostrar: ");
    scanf("%d", &primos_por_mostrar);

    n = 2;
    while (primos_por_mostrar > 0) {

        /* determinar si n es primo */
        es_primo = 1;
        for (int i= 2; i < n; i++) {
            if (n % i == 0) {
                es_primo = 0;
                break;
            }
        }
        /* mostrar el numero
         * y actualizar el contador */
        if (es_primo) 
        {
            printf("%d ", n);
            primos_por_mostrar--;
        }
        n++;
    }

    printf("\n");
    return 0;
}
