#include <stdio.h>

int main()
{
    int arr[8] = {5,4,8,7,6,1,2,3};
    int i, dato = 7;
    char band = 'F';

    //Sequential search algorithm 
    i = 0;
    while ((band == 'F') && (i<5))
    {
        if (arr[i] == dato)
        {
            band = 'V';
        }
        i++;
    }
    
    if (band == 'F')
    {
        printf("The number search does not exist\n");
    } 
    else if(band == 'V')
    {
        printf("The number search exist in position: %d\n", i-1);
    }
    

    return 0;
}