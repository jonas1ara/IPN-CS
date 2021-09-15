#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define NUMS_TO_GENERATE 1000
 
int main() {

	int numeros[NUMS_TO_GENERATE] = { 0 }, N ;
 
    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++){
        N = rand() % MAX;
 		
    	printf("%d.- %d\n",i, N);

	 }

    exit(EXIT_SUCCESS);
}
