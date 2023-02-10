#include <stdio.h>
int palindrome(int n){
    int n1=n,sum=0;
    while(n1!=0){
        int r=n1%10;
        sum=sum*10+r;
        n1/=10;
    }
    return n==sum;
}
int main() {
    int n=232;
    if(palindrome(n))
        printf("It is a palindrome number");
    else
        printf("It is not a plaindrome number");
    return 0;
}