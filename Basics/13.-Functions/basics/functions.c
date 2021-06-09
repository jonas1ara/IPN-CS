/*Functions are used to make a particular operation*/

#include <stdio.h> //directive include

void greeting() { //reserved word void; declares a function that does not return any value
	
	printf("hello world\n");

}
int main() {

	greeting();
	
	return 0;
}

/*
int sum(); //Function sum
int main() { //Function main; from here you can send for other functions
	
	printf("%i\n", sum());

	return 0;

}
int sum() {
	int num1 = 12;
	int num2 = 4;
	int sum = num1 + num2;

	return sum;	//Return the value of a function

}*/
