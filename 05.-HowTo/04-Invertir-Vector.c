#include<stdio.h>

void invertirArray(int arr[], int start, int end);

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("El vector es: \n");
	for(int i=0;i<n;i++)
	{
	    printf("%d ",arr[i]);
	}
	printf("\n");

	
	invertirArray(arr, 0, n-1); 
	printf("El array invertido es: \n");
	for(int i=0;i<n;i++)
	{
	    printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}

void invertirArray(int arr[], int start, int end)
{
	int temp;
	while (start < end) 
	{
		temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
}	
