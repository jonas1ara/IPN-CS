/*	Recursive functions

Recursive functions have the property of calling themselves

	Example of the factorial of a number

	5! = 5 * 4 * 3 * 2 * 1 o  5*4! = 120
	4! = 4 * 3 * 2 * 1 * o 4*3! = 24
	3! = 3 * 2 * 1 o 3*2! = 6
	2! = 2 * 1 o 2*1! = 2
	1! = 1
	0! = 1
*/

#include <stdio.h>

long factorial(long number); //function prototype, defined as type long with parameter number
int main() {
	
	int number;
	printf("Enter a number: \n");
	scanf("%i",&number);
	
	for (int i = 0;  i <= number; i++) {
		printf("%ld\n", factorial(i));
	}
	
	return 0;
}
long factorial(long number) { //factorail function, type date long with parameter number

	if (number <= 1) {
		return 1;
	} else {
		return(number * factorial(number - 1)); 
	}
}
