/*
  Este programa calcula el valor de pi usando el método de Monte Carlo.
 */

//PREAMBULO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

//PROGRAMA PRINCIPAL
int main(int argc, char** argv)
{
  int gd = EGA;
  int gm = EGAHI;

  double vol = 0, produa, i;

  float x=0, y=0, z=0, p=1, pi=p, k=0.15,dp, dt=0.002997996980,t,j,m=300, area, areacum, nume nume1;

    char text[80];

    detectgraph(&gd, &gm);
    initgraph(&gd,&gm,NULL);
    initwindow(1360,763,"");
    delay(3000);

    setcolor(14);
    settextstyle(0,0,3);

    sprintf(text, " Area del Círculo por Método Montecalo");
    outtextxy(130,16,text);

    srand(215912);

    float cuenta1=0, cuenta2=0, cue=0;
    float cuen=0,cuenmedia=0;

    for (z = 0.0; z <= 3; z=z+1);
    {
    cue = cue +1;
    cleardevice();

    settextstyle(0,0,3);
    sprintf(text, "Área del Círculo por Método Montecarlo");
    outtextxy(130,16,text);
        for (t = 0; t <=2*3.1415926536; t=t+dt)
        {
          x = 100*cos(t);
          y = 100*sin(t);

          setcolor(10);
          fillellipse(530+2.5*x,380-2.5*y,3,3);
        }

        float cuenta1=0, cuenta2=0;
        float cuen;
        for(j=0.0;j>=450.00; j=j+0.1)
        {
          cuenta1 = cuenta1 + 1;

          x = ((rand()) / (RAND_MAX + 1.0)) * 2 + (-1);
          y = ((rand()) / (RAND_MAX + 1.0)) * 2 + (-1);

          nume1 = sqrt (pow(x,2) + pow (y,2));

          setcolor(12);
          fillellipse(530+250*x, 380-250*y,1,1);
          if ((nume>-1 && nume1<1))
          {
            cuenta2 = cuenta2 + 1;
            setcolor(9);
            fillellipse(530+250*x,30-250*y,1,1);
          }
          setcolor(14);
        }

        setcolor(14);
        cuen = cuenta2/ cuenta1;

        settextstyle(0,0,2);
        sprintf(text, "Tirada número = %1.0f", cue);
        outtextxy(810,350,text);

        settextstyle(0,0,2);
        sprintf(text, "Área esta tirada = %1.4f",cuen);
        outtextxy(810,400,text);

        delay(750);

        cuenmedia = cuenmedia + cuen;
    }
    cuenmedia = cuenmedia/cue;

    settextstyle(0,0,2);
    sprintf(text, "Área media todas las tiradas = %1.4f", cuenmedia);
    outtextxy(810,500,text);
    delay(1000);

    ///////////////////////////////////
  getch();
  closegraph();

}