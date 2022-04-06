#include <stdio.h>
#include <stdlib.h>

#define PUNTOS_X (6)
#define PUNTOS_H (4)
#define PUNTOS_Y ((PUNTOS_X) + (PUNTOS_H) - 1)

/* Los metodos tienen la misma interfaz:
    x, h ---> son las señales de entrada
       y ---> es la señal de salida        */
void input_side_conv(int *x, int *h, int *y)
{
    int i,j;
    for(i=0;i<PUNTOS_X; i++)
        for(j=0;j<PUNTOS_H;j++)
            y[i+j]=y[i+j]+x[i]*h[j];
}

void output_side_conv(int *x, int *h, int *y)
{
    int i,j;

    for(i=0;i<PUNTOS_Y; i++) {
        y[i]=0;
        for(j=0;j<PUNTOS_H;j++) {
            if(i-j<0 || i-j>=PUNTOS_X) continue;
            y[i] = y[i]+h[j]*x[i-j];
        }
    }
}

int main()
{
    int x[PUNTOS_X] = {0,-1,-1,2,1,1};
    int h[PUNTOS_H] = {1,0,-1,1};
    int y1[PUNTOS_Y] = {0,0,0,0,0,0,0,0,0};
    int y2[PUNTOS_Y] = {0,0,0,0,0,0,0,0,0};

    int i;

    //calculamos la convolucion por el primer metodo
    input_side_conv(x, h, y1);
    //calculamos la convolucion por el otro metodo
    output_side_conv(x, h, y2);

    //mostramos las dos respuestas
    printf("Input Side        Output Side\n");
    for(i=0;i<PUNTOS_Y;i++)
        printf("[%2d]              [%d]\n", y1[i], y2[i]);

    return 0;
}

