#include <stdio.h>

int main () {
	
	int a = 80; //We initialize an integer variable to 80
	float f = 45.3; //We initialize a floating variable in 45.3
	float sum = (float)a + f; //we add (float)a to turn the integer into floating and sum

	printf("%.3f\n",sum);
/*
	//uncomments this printf, comment on the one above and recompile
	printf("Integer: %i\nFloating: %.2f\nDouble: %.3f\nCharacter: %c\n",a, (float)a, (double)a, (char)a);
*/

	return 0;


}
