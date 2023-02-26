# Carácer a Binario

![](/00.-Sources/Images/binario.PNG)


_Para convertir un carácter a su representación binaria utilizando ciclos for, se puede utilizar la misma técnica que se utiliza con el operador ">>" y "&", pero se implementa manualmente. Es decir, se recorre cada bit del número entero correspondiente al carácter y se compara su valor con una potencia de 2._

_La siguiente función muestra cómo se puede hacer esto utilizando ciclos for:_

```C
void car_a_binario(char c) {
    int i, j;
    for (i = 7; i >= 0; i--) {
        j = 1 << i;
        if (c & j) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

```

_En esta función, se utiliza un bucle for para recorrer los bits del número entero correspondiente al carácter de izquierda a derecha. Dentro del bucle, se utiliza la variable j para almacenar el valor de la potencia de 2 correspondiente al bit actual. Luego, se utiliza el operador "&" para comparar el bit actual con el valor j. Si el resultado es distinto de cero, significa que el bit está activado y se imprime un 1. De lo contrario, se imprime un 0._




