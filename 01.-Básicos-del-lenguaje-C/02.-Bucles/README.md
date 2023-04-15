# Bucles

![](/00.-Sources/Images/Bucle.png)

_Ejemplo del bucle en un juego de consola, que utiliza while para repetir el juego hasta perder_

## ¿Qué son los bucles?

Los bucles son una estructura de control que nos permite repetir una o varias instrucciones un número determinado de veces o hasta que se cumpla una condición.

## For

El bucle for es el más utilizado en la programación, ya que nos permite realizar una tarea un número determinado de veces, comunmente se utiliza para recorrer arreglos.

```c
#include <stdio.h>

int main() 
{
    int i;
    
    for(i = 0; i < 10; i++)
    {
        printf("Hola mundo\n");
    }
    
    return 0;
}
```

## While

El ciclo while es muy similar al ciclo for, pero no se utiliza para recorrer arreglos, sino para realizar una tarea hasta que se cumpla una condición.

```c
#include <stdio.h>

int main() 
{
    int i = 0;
    
    while(i < 10)
    {
        printf("Hola mundo\n");
        i++;
    }
    
    return 0;
}
```

## Do While

El ciclo do while es muy similar al ciclo while, pero la diferencia es que este ciclo se ejecuta al menos una vez, ya que primero se ejecuta el bloque de código y después se evalúa la condición.

```c
#include <stdio.h>

int main() 
{
    int i = 0;
    
    do
    {
        printf("Hola mundo\n");
        i++;
    }while(i < 10);
    
    return 0;
}
```

### Nada del otro mundo


## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_
