#include <stdio.h>

// Función para encontrar el cambio de moneda
void cambioMoneda(int monedas[], int n, int cantidad) 
{
   int i, contador = 0;

   for (i = n - 1; i >= 0; i--) 
   {
        while (cantidad >= monedas[i  ]) 
        {
            cantidad -= monedas[i];
            printf("%d ", monedas[i]);
            contador++;
        }
    }
   printf("\nMonedas totales: %d\n", contador);
}

int main()
{
    int monedas[] = {1, 5, 10, 25};
    int n = sizeof(monedas) / sizeof(monedas[0]);
    int cantidad = 47;

    cambioMoneda(monedas, n, cantidad);

    return 0;
}