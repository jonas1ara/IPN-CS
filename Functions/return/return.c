#include <stdio.h> //directive include

int sum(); //sum function
int num3 = 5; //global variable; integer type
int main() { //main function

	int num1, num2;
	
	printf("Enter the firts value: \n");
	scanf("%i", &num1);

	printf("Enter the second value:\n");
	scanf("%i", &num2);
	
	printf("El resultado es: %i\n", sum(num1,num2)); // Print sum function	

	return 0;

}

int sum (int num1, int num2) {
	
	int sum = num1 + num2 + num3; //Add global variable

	return sum;

}
