//La misma mierda pero con strings y char

#include<stdio.h>

void invertir(char arr[], int start, int end);


int main()
{
	char arr[] = "InstitutoPolitecnicoNacional";
	int n = 28;
	printf("Cadena original es: \n");
	printf("%s\n",arr);
	
	invertir(arr, 0, n-1);

	printf("Cadena invertida es: \n");
	printf("%s ",arr);
	printf("\n");
	
	return 0;
}

void invertir(char arr[], int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; 
		end--; 
	}
}	