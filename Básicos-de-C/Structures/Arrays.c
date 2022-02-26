/*
	Structures arrays
*/

#include<stdio.h>

struct dog {
	char name[30];
	int age;
	float weight;
}
dogs[2];
int main() {
	for(int i = 0; i < 2; i++) {
		printf("Enter name of the dog %i:\n", i+1);
		scanf("%s",dogs[i].name);	
		printf("Enter the age in months of the dog %i:\n", i+1);
		scanf("%i",&dogs[i].age);	
		printf("Enter the weight of the dog %i: \n", i+1);
		scanf("%f",&dogs[i].weight);
		printf("\n");	
	} for(int i = 0; i < 2; i++) {	
		printf("The name of the dog %i is: %s\n", i+1,dogs[i].name);
		printf("The age in months of the dog %i is: %i\n", i+1,dogs[i].age);
		printf("The weight of the dog %i is: %.2f\n", i+1,dogs[i].weight);
		printf("\n");
		}
	return 0;
}
