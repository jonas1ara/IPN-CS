#include<stdio.h>

int main()
{
    char str[1000]= "TUF";
    int i=0;
    int count=0;
    while(str[i]!='\0')
    {
        count++;
        i++;
    }
    printf("The length of the string %d",count);
}