#include <stdio.h>
#include <string.h>

int subcadenaMasLarga(char *str)
{
    int n = strlen(str);
    int longitudMax = 0;
    int inicio = 0;
    int final = 0;

    int contadorCaracteres[256] = {0}; // Inicializar el contador de caracteres

    while (final < n)
    {
        char caracterActual = str[final];

        if (contadorCaracteres[caracterActual] == 0)
        {
            contadorCaracteres[caracterActual]++;
            final++;
            int currentLength = final - inicio;
            if (currentLength > longitudMax)
                longitudMax = currentLength;
        }
        else
        {
            contadorCaracteres[str[inicio]]--;
            inicio++;
        }
    }

    return longitudMax;
}

int main()
{
    char str[] = "abcabcbb";
    int length = subcadenaMasLarga(str);
    printf("La longitud de la subcadena más larga sin caracteres repetidos es: %d\n", length);

    return 0;
}
