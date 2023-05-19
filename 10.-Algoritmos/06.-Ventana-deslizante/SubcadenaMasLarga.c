#include <stdio.h>
#include <string.h>

int longestSubstringLength(char* str) {
    int n = strlen(str);
    int maxLength = 0;
    int start = 0;
    int end = 0;

    int charCount[256] = {0};  // Inicializar el contador de caracteres

    while (end < n) {
        char currentChar = str[end];

        if (charCount[currentChar] == 0) {
            charCount[currentChar]++;
            end++;
            int currentLength = end - start;
            if (currentLength > maxLength)
                maxLength = currentLength;
        } else {
            charCount[str[start]]--;
            start++;
        }
    }

    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    int length = longestSubstringLength(str);
    printf("La longitud de la subcadena más larga sin caracteres repetidos es: %d\n", length);

    return 0;
}
