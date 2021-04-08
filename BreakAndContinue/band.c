#include <stdio.h>

int main(){
	
	int num = 0;

	while(num<=7){	
		num++;
		if (num == 3){
			continue;
			//break; //Ends the cycle 
		}
		printf("%i\n", num);
		//num++; //Use of break
	}

	return 0;
}
