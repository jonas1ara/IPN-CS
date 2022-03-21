#include <stdio.h>

int main()
{
    int arr[8] = {5,4,8,7,6,1,2,3};
    int i, j, minimo, temp;

    printf("Disordered: \n");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Selection Sort Algorithm
    for (i = 0; i < 8; i++)
    {
        minimo = i;
        for (j = i+1; j < 8; j++)
        {
            if (arr[minimo] > arr[j])
            {
                minimo = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp;
    }
    printf("Sorted by Selection Sort: \n");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}