/*¨
	Break y Continue; nos permiten controlar el flujo de nuestro programa.

*/

#include <stdio.h>

int main(){
	
	int num = 0;

	while(num<=7)
	{	
		num++;//Uso de continue
		if (num == 3)
		{
			continue; //Nos permite seguir ejecutando pero salta un paso.
			//break; //Termina un ciclo
		}
		printf("%i\n", num);
		//num++; //Uso de break
	}

	return 0;

}
