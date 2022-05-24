#include<stdio.h>

void invertir(char arr[], int i, int j)
{
	char temp;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}

}	

int main()
{
	char arr[] = "InstitutoPolitecnicoNacional";
	int n = 28;
	printf("Cadena original es \n");
	printf("%s\n",arr);
	invertir(arr, 0, n-1);
	printf("Cadena invertida es \n");
	printf("%s ",arr);
	return 0;
}