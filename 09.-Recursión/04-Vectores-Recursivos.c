#include <stdio.h>

void vectorRec(int arr[], int n);
void vectorRec_inv(int arr[], int n);

int main()
{
	int arr[] = {1,2,3,4,5,6};	
	vectorRec_inv(arr, 5);
	printf("\n");

	vectorRec(arr,5);
	printf("\n");

	return 0;
}

void vectorRec(int arr[], int n)
{
	if(n > 0)
	{
		printf("%d",arr[n]);
		vectorRec(arr, n-1);
	}
}

void vectorRec_inv(int arr[], int n)
{
	if(n > 0)
	{
		vectorRec(arr, n-1);
		printf("%d",arr[n]);
	}
}
