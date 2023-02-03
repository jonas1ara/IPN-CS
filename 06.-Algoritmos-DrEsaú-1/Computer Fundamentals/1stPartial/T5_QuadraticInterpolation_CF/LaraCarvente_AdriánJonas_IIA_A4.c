/*
	Name: Interpolation
	Date: 25/04/21 20:00
	Author: Adrián Jonás Lara Carvente 
	Description: This program calculates quadratic interpolation based on three points on a plane
*/
#include <stdio.h>
int main ()
{
	//I declare float variables 
	float x, y, x0= 2014, y0=3000, x1=2018, y1=3800, x2= 2019, y2=4100;
	
	//I explain to the user what to do
	printf ("\nEste programa te da la matricula de un año entre el 2000 y 2030\n");	
	
	//The user enters the year and saves in variable X
	printf ("Escribe el año del cual deseas saber la matricula: \n" );
	scanf("%f",&x);
	
	//I condition the program so that it has a minimum and a maximum of years
	if (x>=2000 && x<=2030) {
		//Interpolation in variable Y, I just transcribed equation
		y=(y0*(((x-x1)*(x-x2))/((x0-x1)*(x0-x2))))+(y1*(((x-x0)*(x-x2))/((x1-x0)*(x1-x2))))+(y2*(((x-x0)*(x-x1))/((x2-x0)*(x2-x1))));
		 
		//Prints result
		printf("El numero de alumnos matriculados es: %f\n",y);
		} 
		//Help the user
		else printf ("Este programa solo cálcula la matricula entre el año 2000 al año 2030,por favor ingresa un año valido.\n");
    
    	return 0;
}

