#include <stdio.h>

int main ()
{
 
	float x, y, x0= 2014, y0=3000, x1=2018, y1=3800, x2= 2019, y2=4100;

	printf("Este programa te da la matricula de un año entre el 2000 y 2030\n"); 
	printf("Escribe el año del cual deseas saber la matricula: \n" );
	scanf("%f",&x);
	
	if (x>=2000 && x<=2030) 
	{
	
	//Interpolación cuadrática
	y=(y0*(((x-x1)*(x-x2))/((x0-x1)*(x0-x2))))+(y1*(((x-x0)*(x-x2))/((x1-x0)*(x1 x2))))+(y2*(((x-x0)*(x-x1))/((x2-x0)*(x2-x1))));

	printf("El numero de alumnos matriculados es: %.2f\n",y);
	
	} 
	else 

	printf("Este programa solo cálcula la matricula entre el año 2000 al año 2030,por favor ingresa un año valido.\n");
 
 return 0;
}
