/*
    Nombre del programa: El mejor número
    Fecha: 3 Octubre del 2021
    Autor: Aspire Linux
    Descripción: ¿Existen otros valores primos "p", tales que el número espejo de "p" también sea primo?

*/
#include <stdio.h>

int main() {
    int primos_por_mostrar, n, d, numero, resto;
    int es_primo; //Se usara como booleano

    printf("Este programa muestra la cantidad de números primos pedida y si su número espejo es primo\n"); 
    printf("¿Cuantos primos desea mostrar? "); 
    scanf("%d", &primos_por_mostrar); 

    n = 2; //contador pa empezar con los primos, porque pues el primer primo es 2 :D
    while (primos_por_mostrar > 0) { //8 > 0

        /* determinar si n es primo */
        es_primo = 1; //True
        for (d = 2; d < n; d++) { //d contaste pa dividir; siempre y cuando d sea menor a n, aumenta el valor d
            if (n % d == 0) { //residuo igual a cero, para saber si es número exacto
                es_primo = 0; //False
                break;
            }
        }

        /* mostrar el numero
         * y actualizar el contador */
        if (es_primo) {
            printf("%d ", n);
            numero = n; 
            primos_por_mostrar--; //Reduciendo el valor de primos
            
            //Invertir numeros
            int invertir=0;

            while(numero!=0) //721 != 0
                {
                    resto = numero%10; //.1 , .2, .7
                    numero = numero/10; //72.1, 7.2, 0 << se termina la condición del while
                    
                    invertir = invertir*10+resto;
                    //1ra pasada: 0 * 10 = 0 + 1 = 1
                    //2da pasada: 1 * 10 = 10 + 2 = 12
                    //3ra pasada: 12 * 10 = 120 + 7 = 127
                }
                
                int count = 0;
                for (int i = 1; i <= invertir; i++)
                {
                    if (invertir%i==0)
                    {
                        count++;
                    }
                }
                if (count>2)
                {
                    printf("Su espejo no es primo: %d\n", invertir);
                }
                else
                {
                    printf("Su espejo es primo: %d\n", invertir);
                }

        }
        n++; //actualizar el contador

    }

    printf("\n");
    return 0;
}
