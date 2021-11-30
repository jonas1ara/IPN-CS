#include <stdio.h>

int main()
{
    int arr[8] = {5,4,8,7,6,1,2,3};
    int i, pos, temp;
    printf("Disordered: \n");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Insertion Sort Algorithm
    for (i = 0; i < 8; i++)
    {
        pos = i;
        temp = arr[i];
        while ((pos>0) && arr[pos-1]>temp)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = temp;
    }
    printf("Sorted by Insertion Sort: \n");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    

}