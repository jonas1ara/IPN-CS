/*
	Structures on C
*/

#include<stdio.h>

struct dog {
	char name[30];
	int age;
	float weight;
}
dog1={"Pikachu", 10, 3.50}, dog2={"Arduino",4,2.30};

int main() {
	printf("The weight of %s is: %.2f Kg and it´s %i months old\n ", dog2.name,dog2.weight,dog2.age);
	
	return 0;	

}

