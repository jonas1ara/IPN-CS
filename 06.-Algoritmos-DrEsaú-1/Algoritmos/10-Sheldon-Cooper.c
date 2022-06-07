#include <stdio.h>

int main() {
    int primos_por_mostrar, n = 2, d, numero, numero_limite , resto;
    int es_primo; //Se usara como booleano
    int primo_final;

    printf("Este programa muestra la cantidad de números primos pedida y si su número espejo es primo\n"); 
    printf("Digite el número limite de números primos: ");
    scanf("%d", &primos_por_mostrar); 

   // n = 2; //contador pa empezar con los primos, porque pues el primer primo es 2 :D
    
    while (primos_por_mostrar > numero_limite ) { //8 > 0

        /* determinar si n es primo */
        es_primo = 1; //True
        for (d = 2; d < n; d++) { //d contaste pa dividir; siempre y cuando d sea menor a n, aumenta el valor d
            if (n % d == 0) { //residuo igual a cero, para saber si es número exacto
                es_primo = 0; //False
                break;
            }
        }

        /* mostrar el numero y actualizar el contador */
        if (es_primo) {
            numero = n; 
            
            primos_por_mostrar--; //Reduciendo el valor de primos
            
            /*Invertir números*/
            int invertir = 0;

            while(numero != 0) //721 != 0
                {
                    resto = numero % 10; //.1 , .2, .7
                    numero = numero / 10; //72.1, 7.2, 0 << se termina la condición del while
                    
                    invertir = invertir*10+resto;
                    //1ra pasada: 0 * 10 = 0 + 1 = 1
                    //2da pasada: 1 * 10 = 10 + 2 = 12
                    //3ra pasada: 12 * 10 = 120 + 7 = 127
                }
                /*Comprobar si el número espejo es primo o compuesto*/
                
                primo_final = 1; //True
                    for (int i = 2; i < invertir; i++) { //d contaste pa dividir; siempre y cuando d sea menor a n, aumenta el valor d
                        if (invertir % i == 0) { //residuo igual a cero, para saber si es número exacto
                            primo_final = 0; //False
                            break;
                        }
                    }
                
                /* mostrar el numero y actualizar el contador */
                if (primo_final) {
                    printf("El número: %d ", n);
                    
                    numero_limite = n;
                     
                    printf("y su espejo: %d son primos.", invertir);
                    printf("\nnumero limite: %d\n",numero_limite);
                }

        }
        
        
       
        n++; //Actualizar el contador, es decir si n valia 2 ahora vale 2
        
        printf("%d\n",n);
        

    }

    printf("\n");

    return 0;
}
