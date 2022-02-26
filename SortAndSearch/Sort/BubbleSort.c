#include <stdio.h>

int main()
{
	int arr[8] = {5,4,8,7,6,1,2,3};
	int temp, i, j;

	printf("Disordered: \n");
	for (i = 0; i < 8; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	//Bubble Sort Algorithm
	for (i = 0; i < 8; i++)
	{
		for (j= 0; j < 8 -1 ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
 			}
		}
	}
	printf("Sorted by Bubble Sort: \n");
	for (i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}