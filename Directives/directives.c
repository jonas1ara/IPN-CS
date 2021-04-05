//The processor directives are the ones that contain libraries and macros, they start with #



#include <stdio.h> 
/*
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "directives.c"
*/

#define PI 3.14159 //Symbolic constants: Inmutable value.

#define CUBE(a) a*a*a //Macro: Is a series of instructions that are stored so that they can be executed sequentially through a single call.


int main() {
	
	/*
	int suma;

	suma = PI + 3;
	*/

	int a = 3;
	
	printf("The value of the variable is:  %i\n",CUBE(a));

	return 0;
	
}
