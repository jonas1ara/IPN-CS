/*
	Nested Structures
*/

#include <stdio.h>
#define length 2
struct owner {
	char name[20];
	char direction[30];
};
struct dog {
	char name[20];
	int age;
	struct owner ownerDog;
}dogs[length];

int main() {
	for(int i = 0; i < length; i++) {
		printf("Name of the dog\n");
		scanf("%s",dogs[i].name);
		printf("Age of the dog in months\n");
		scanf("%i",&dogs[i].age); 
		printf("Owner´s name \n");
		scanf("%s",dogs[i].ownerDog.name); 
		printf("Owner´s direction \n");
		scanf("%s",dogs[i].ownerDog.direction);
		printf("\n"); 
	}
	for(int i = 0; i < length; i++) {
			printf("Name of the dog is:  %s\n",dogs[i].name);	
			printf("Age of the dog in months is: %i\n",dogs[i].age);
			printf("Owner´s name is: %s\n",dogs[i].ownerDog.name);	
			printf("Owner´s direction is: %s\n", dogs[i].ownerDog.direction);
			printf("\n");
		}
	return 0;
}
