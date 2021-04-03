/*
Making decisions if

Equality operators:                   	 |                 Relantionship operators:
	== X is equal to Y                                        	> X Is greater than Y
	!= X is different from  Y									< X Is less than Y
																>= X is greater than or equal to Y
																<= X is less than or equal to Y
*/

#include <stdio.h>

int main(void) {

	int age;
	
	printf("Tell me your age:\n");
	scanf("%d",&age);

	if(age >=18) {
		printf("You're of legal age\n");
	} else {
		printf("You're underage\n");
	}

	return 0;

}
