#include <stdio.h>

int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    int inf, sup, mitad, dato = 7;
    char band = 'F';

    
    //Binary search algorithm

    inf = 0;
    sup = 8;

   
    while (inf!=sup)
    {

        if((arr[mitad]==sup)&&(arr[mitad]<dato)){
            break;
        }
        mitad = (inf+sup)/2;
        if (arr[mitad] == dato)
        {
            band = 'V';
            break;
        }
        if(arr[mitad] > dato)
        {
            sup = mitad;
            mitad = (inf+sup)/2;
        }
        if(arr[mitad] < dato)
        {
            inf = mitad;
            mitad = (inf+sup)/2;
        }
    
    }
    if (band == 'V')
        {
            printf("The number exist in the position: %d\n", mitad);

        }
        else
        {
            printf("The number does not exist\n");
        }
    

    return 0;

}
