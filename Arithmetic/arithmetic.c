#include <stdio.h>

int main() {
	
	int num1, num2, result;
	int a=2;
	int b=3;
	
	printf("Enter a number:\n");	
	scanf("%d",&num1);

	printf("Enter the second number:\n");
	scanf("%d",&num2);

	/*result = num1 / num2;*/ //Change operator to any of the arithmetic operators; addition, subtraction, division and multiplication. Recompile.
	
	result = a*(num1-num2) / b*(num1+num2);
	
	printf("The result of the operation is: %d\n", result);

	return 0;
}
