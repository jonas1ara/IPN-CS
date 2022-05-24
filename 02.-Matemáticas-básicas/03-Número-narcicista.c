#include<stdio.h>
#include<math.h>
int ArmstrongNumber(int n)
{
    int originalno = n;
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    int sumofpower = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sumofpower += pow(digit,count);
        n /= 10;
    }
    return (sumofpower == originalno);
}

int main()
{
    int n1 = 153;
    if (ArmstrongNumber(n1))
    {
        printf("Yes, it is an Armstrong Number\n");
    }
    else
    {
        printf("No, it is not an Armstrong Number\n");
    }
    return 0;
}