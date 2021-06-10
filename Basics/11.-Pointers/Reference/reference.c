/*
	//Calls by reference; function to raise a number to the cube.

	Many functions require the ability to modify one or more variables in a function call in that case we can avoid over loads are making copies of the object or our variable.

*/


#include <stdio.h>

void cubo(int *n); //Prototype of our function, pointer argument.

int main() {
	
	int num = 5;
	printf("Original value: %i\n",num);
	cubo(&num); //I tell num to assign you the value returned by the functioni, reference with &
	printf("The new valor: %i\n", num);
	
	return 0;	
}
void cubo(int *n) { //void value are not required to return a value, it will receive the parameter that we send above and will use it as *n
	*n = *n * *n * *n;

}


