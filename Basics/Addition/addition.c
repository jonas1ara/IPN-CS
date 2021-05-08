#include <stdio.h>

int main() {

	int num1; //Int to define integer variables.
	int num2;
	int result;

	printf("Enter a number integer:\n");
	scanf("%d",&num1); //Scanf to read, store the user-given value, %d: decimal integer, and address operator indicates where to store.
	
	printf("Enter other number integer:\n");
	scanf("%d",&num2);

	result= num1 + num2; //Add operation to be stored in the result variable
	
	printf("The result of the sum is: %d\n",result); //%d to print us an integer and , the result variable of operation.

	return 0;	

}
