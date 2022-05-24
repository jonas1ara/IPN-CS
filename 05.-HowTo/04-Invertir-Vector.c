#include <stdio.h>

void printArr(int arr[], int length);

int main()
{
	int arr[] = {10 ,4, 3, 5, 5}, arr2[5];
	
	int arr_length = sizeof(arr) / sizeof(int), arr2_length = sizeof(arr2) / sizeof(int);
	
	printArr(arr, arr_length);
	
	int i, j;
	
	for(i = arr_length-1, j = 0; i >= 0 && j < arr2_length; i--, j++)
	{
		arr2[j] = arr[i];
		printf("%d ", arr2[j]);
	}
	printf("\n");
	return 0;
}

void printArr(int arr[], int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n \n");
}
