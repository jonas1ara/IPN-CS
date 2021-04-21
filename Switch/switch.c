#include<stdio.h>

int main() {

	int cases;

	printf("Enter a number:\n");
	scanf("%i",&cases);
	
	switch(cases){
		case 1:
			printf("You chose the case #1\n");
			break;
		
		case 2:	
			printf("You chose the case #2\n");
			break;
		
		case 3:
			printf("You chose the case #3\n");
			break;
			
		case 4:	
			printf("You chose the case #4\n");
			break;
	
		case 5:	
			printf("You chose the case #5\n");
			break;

		default:
			printf("We didn't find your case... :/\n");
			break;
	
	}

	return 0;

}

