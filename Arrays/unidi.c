#include <stdio.h>

int main() {
		
	int SizeA;
	printf("Fix size: \n");
	scanf("%i", &SizeA);
	int age[SizeA];
	
	for (int i = 0; i < SizeA; i++){
		printf("Enter the value %i:\n", i+1);
		scanf("%i", &age[i]);
	}
	printf("The values of the arrangement are: \n");
	for(int i = 0; i < SizeA; i++) {
		printf("%i-", age[i]);
	}
	printf("\n");
	return 0;
}
