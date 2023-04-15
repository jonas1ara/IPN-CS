# How To

#### Impletaciones de sofware para hacer tareas especificas

![](/00.-Sources/Images/HowTo.jpeg)

_"How To" en español quiere decir "como"_

Supon que quieres medir el tiempo que tarda en ejecutarse el algoritmo de `ordenamiento por inserción` en un array de 1000000 elementos. Para ello, tendrías que hacer lo siguiente:

- Crear un array de 1000000 elementos
- Generar 1000000 números aleatorios
- Programar el algoritmo de `ordenamiento por insercción`
- Medir el tiempo que tarda en ejecutarse

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 1000000

int main()
{
    clock_t start, end;
    double cpu_time_used;

	int numeros[NUMS_TO_GENERATE] = { 0 }, N, aux, j;

    start = clock();

    // Código a medir
	srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++)
    {
        N = rand() % MAX;
        numeros[i] = N;
		
		printf("%d.- %d\n", i, N);
    }

    for (int i = 1; i < NUMS_TO_GENERATE; i++)
    {
        aux = numeros[i];
        j = i - 1;

        while (j >= 0 && numeros[j] > aux)
        {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = aux;
    }

    for (int i = 0; i < NUMS_TO_GENERATE; i++)
    {
        printf("%d.- %d\n", i, numeros[i]);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución: %f\n", cpu_time_used);

    return 0;
}
```

Te puedes dar cuenta que para realizar esa tarea debes tener conocimiento de cómo crear y recorrer un arreglo de 1000000 elementos, conocer la función `srand()` y `rand()` para generar números aleatorios, conocer el algoritmo de `ordenamiento por insercción` y por último, conocer la función `time()` para medir el tiempo que tarda en ejecutarse el algoritmo

_La programación es saber cómo unir piezas de código para realizar una tarea específica_

## Contenido

### Medir tiempo de ejecución

_Programa para medir el tiempo de ejecución de un algoritmo_

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Código a medir
    printf("Midiendo ...\n");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución: %f\n", cpu_time_used);

    return 0;
}
```

La librería `time.h` nos proporciona un nuevo tipo de dato `clock_t` que es de tipo `long int` y  la función `clock()` que nos permite medir el tiempo de ejecución de un algoritmo. La función `clock()` nos devuelve el tiempo en milisegundos que tarda en ejecutarse el algoritmo, para convertirlo a segundos, debemos dividirlo entre `CLOCKS_PER_SEC` que es una constante que nos proporciona la librería `time.h` y que nos indica el número de milisegundos que hay en un segundo, eso lo guardamos en la variable `cpu_time_used` y la imprimimos en pantalla al final

### Generar números aleatorios

_Programa para generar números aleatorios_

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000000
#define NUMS_TO_GENERATE 1000
 
int main() 
{

    int numeros[NUMS_TO_GENERATE] = { 0 }, N ; //Declara arreglo vacio del tamaño que tome NUMS_TO_GENERATE 
 
    srand(time(NULL)); 
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX; 
 		
    	printf("%d.- %d\n",i, N); //Se imprime variable i que es el número de iteración (opcional) y N que es el número generado

	 }

    exit(EXIT_SUCCESS);
}
```

En la constante `MAX` definimos el tamaño máximo de los números a generar, en la constante `NUMS_TO_GENERATE` definimos el número de números a generar. La función `srand()` nos permite generar números pseudo aleatorios, para ello, le pasamos como parámetro la función `time()` que nos devuelve el tiempo en milisegundos que ha transcurrido desde el 1 de enero de 1970 hasta el momento en que se ejecuta el programa. La función `rand()` nos devuelve un número pseudo aleatorio entre 0 y el número que le pasemos como parámetro, en este caso, le pasamos como parámetro la constante `MAX` que es 1000000, por lo tanto, la función `rand()` nos devolverá un número entre 0 y 1000000. La función `rand()` nos devuelve un número entero, por lo tanto, para que nos devuelva un número decimal, lo dividimos entre `MAX` que es 1000000 y lo guardamos en la variable `N` que es de tipo `int` y la imprimimos en pantalla


### Intercambio de valores

_Programa para intercambiar valores_

```c
#include <stdio.h>

void swap(a,b);

int main() 
{
   int a = 5, b = 3, temp;
   printf("Antes de intercambiar a = %d y b = %d\n",a,b);

   swap(a,b);

   return 0;
}

// Intercambio de valores
void swap(int a, int b) {
   int temp;
   temp = a; 
   a = b; 
   b = temp; 

   printf("Despues de intercambiar a = %d y b = %d \n",a,b);
}
```

La función `swap()` recibe dos parámetros, `a` y `b` que son de tipo `int`, en la función `swap()` creamos una variable `temp` que es de tipo `int` y le asignamos el valor de `a`, después, le asignamos a `a` el valor de `b` y por último, le asignamos a `b` el valor de `temp` que es el valor que tenía `a` antes de intercambiarlo. Al final, imprimimos en pantalla los valores de `a` y `b` después de intercambiarlos

### Invertir un número

_Programa para invertir un número_

```c
#include <stdio.h>

void invertir (int numero);

int main()
{
    int numero;    
    printf("Dame un número:\n");
    scanf("%d", &numero); 
    
    invertir(numero);

    return 0;
}

void invertir (int numero)
{
    int resto , invertir = 0;
    while(numero!=0) 
    {
        resto = numero%10; 
        numero = numero/10; 
        
        invertir = invertir*10+resto;
    }
    
    printf("El numero invertido es: %d\n",invertir);
}
```

La función `invertir()` recibe un parámetro, `numero` que es de tipo `int`, en la función `invertir()` creamos tres variables, `resto` que es de tipo `int`, `invertir` que es de tipo `int` y `numero` que es de tipo `int`. En el ciclo `while()` mientras `numero` sea diferente de 0, se ejecutará el código que está dentro del ciclo. En la variable `resto` guardamos el resto de la división de `numero` entre 10, después, en la variable `numero` guardamos el cociente de la división de `numero` entre 10, por último, en la variable `invertir` guardamos el resultado de multiplicar `invertir` por 10 y sumarle el valor de `resto`. Al final, imprimimos en pantalla el valor de `invertir`

### Invertir un vector

_Programa para invertir un vector_

```c
#include<stdio.h>

void invertirArray(int arr[], int start, int end);

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("El vector es: \n");
	for(int i=0;i<n;i++)
	{
	    printf("%d ",arr[i]);
	}
	printf("\n");

	
	invertirArray(arr, 0, n-1); 
	printf("El array invertido es: \n");
	for(int i=0;i<n;i++)
	{
	    printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}

void invertirArray(int arr[], int start, int end)
{
	int temp;
	while (start < end) 
	{
		temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
}	
```

La función `invertirArray()` recibe tres parámetros, `arr[]` que es un arreglo de tipo `int`, `start` que es de tipo `int` y `end` que es de tipo `int`, en la función `invertirArray()` creamos una variable `temp` que es de tipo `int`. En el ciclo `while()` mientras `start` sea menor que `end`, se ejecutará el código que está dentro del ciclo. En la variable `temp` guardamos el valor de `arr[start]`, después, en la posición `start` del arreglo `arr[]` guardamos el valor de `arr[end]`, por último, en la posición `end` del arreglo `arr[]` guardamos el valor de `temp`. Al final, imprimimos en pantalla el arreglo `arr[]` invertido

### Invertir una cadena

_Programa para invertir una cadena_

```c
//La misma mierda pero con strings y char

#include<stdio.h>

void invertir(char arr[], int start, int end);


int main()
{
	char arr[] = "InstitutoPolitecnicoNacional";
	int n = 28;
	printf("Cadena original es: \n");
	printf("%s\n",arr);
	
	invertir(arr, 0, n-1);

	printf("Cadena invertida es: \n");
	printf("%s ",arr);
	printf("\n");
	
	return 0;
}

void invertir(char arr[], int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; 
		end--; 
	}
}	
```

La función `invertir()` recibe tres parámetros, `arr[]` que es un arreglo de tipo `char`, `start` que es de tipo `int` y `end` que es de tipo `int`, en la función `invertir()` creamos una variable `temp` que es de tipo `char`. En el ciclo `while()` mientras `start` sea menor que `end`, se ejecutará el código que está dentro del ciclo. En la variable `temp` guardamos el valor de `arr[start]`, después, en la posición `start` del arreglo `arr[]` guardamos el valor de `arr[end]`, por último, en la posición `end` del arreglo `arr[]` guardamos el valor de `temp`. Al final, imprimimos en pantalla el arreglo `arr[]` invertido

### Largo de una cadena

_Programa para calcular el largo de una cadena_

```c
#include<stdio.h>

void largoCadena(char str[]);

int main()
{
    char str[1000]= "TUF"; 
    
    printf("La cadena es: %s\n",str);

    largoCadena(str);
    
    return 0;
}

void largoCadena(char str[])
{
    int i=0; 
    int count=0;
    while(str[i]!='\0') //En C, el último carácter de una cadena es el delímetro o '\0'. También se pronuncia como "Backslash zero".
    {
        count++; 
        i++;
    }
    printf("El ancho de la cadena es: %d\n",count);
}
```

La función `largoCadena()` recibe un parámetro, `str[]` que es un arreglo de tipo `char`, en la función `largoCadena()` creamos dos variables, `i` que es de tipo `int` y `count` que es de tipo `int`. En el ciclo `while()` mientras el valor de `str[i]` sea diferente de `\0`, se ejecutará el código que está dentro del ciclo. En la variable `count` guardamos el valor de `count` más 1, después, en la variable `i` guardamos el valor de `i` más 1. Al final, imprimimos en pantalla el valor de `count`

### Impresión de una pirámide

_Programa para imprimir una pirámide_

```c
#include <stdio.h>

#define P 5

int main()
{
	for (int i = 0; i < P; i++)
	{
		for (int k = 0; k < P - i; k++)
		{
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
```

En el programa anterior, creamos una constante `P` que es de tipo `int` y le asignamos el valor de 5. En el ciclo `for()` mientras `i` sea menor que `P`, se ejecutará el código que está dentro del ciclo. En el ciclo `for()` mientras `k` sea menor que `P - i`, se ejecutará el código que está dentro del ciclo. Imprimimos en pantalla un espacio. Al final, imprimimos en pantalla un salto de línea. En el ciclo `for()` mientras `k` sea menor que `i * 2 + 1`, se ejecutará el código que está dentro del ciclo. Imprimimos en pantalla un asterisco y al final, imprimimos en pantalla un salto de línea

### Impresión de un circulo

_Programa para imprimir un circulo_

```c
#include <stdio.h>
#include <math.h>

#define N 10

int main()
{

    for(int j = 0; j <= N*2; j++) //y
	{
		for(int i = 0; i<= N*2; i++) //x
		{
			if (pow(i-N,2) + pow(j-N,2) <= pow(N,2))
			{
				printf("%c",176);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	} 
    
    return 0;
}
```

En el programa anterior, creamos una constante `N` que es de tipo `int` y le asignamos el valor de 10. En el ciclo `for()` mientras `j` sea menor o igual que `N * 2`, se ejecutará el código que está dentro del ciclo. En el ciclo `for()` mientras `i` sea menor o igual que `N * 2`, se ejecutará el código que está dentro del ciclo. Si la potencia de `i - N` más la potencia de `j - N` es menor o igual que la potencia de `N`, se ejecutará el código que está dentro del `if`, de lo contrario, se ejecutará el código que está dentro del `else`. Imprimimos en pantalla un carácter especial y al final, imprimimos en pantalla un salto de línea

![](/00.-Sources/Gifs/PiMonteCarlo.gif)

_**Simulación del calculo de Pi usando el método de Monte Carlo**, ¿podrías ser capaz de intuir que programas se necesitan para realizar esta tarea?_

---

### La programación es saber cómo unir piezas de código para realizar una tarea específica 😌

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
