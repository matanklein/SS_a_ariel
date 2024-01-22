#include "NumClass.h"
#include <stdio.h>
#define true 1

int main()
{
    int start, end;
    scanf("%d" ,&start);
    scanf("%d" ,&end);
    printf("The Armstrong numbers are:");
    for (int i = start; i <= end; i++)
    {
        int ans = isArmstrong(i);
        if(ans == true){
            printf(" %d" ,i);
        }
    }
    printf("\n");
    printf("The Palindromes are:");
    for (int i = start; i <= end; i++)
    {
        int ans = isPalindrome(i);
        if(ans == true){
            printf(" %d" ,i);
        }
    }
    printf("\n");
    printf("The Prime numbers are:");
    for (int i = start; i <= end; i++)
    {
        int ans = isPrime(i);
        if(ans == true){
            printf(" %d" ,i);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");
    for (int i = start; i <= end; i++)
    {
        int ans = isStrong(i);
        if(ans == true){
            printf(" %d" ,i);
        }
    }
    printf("\n");
    return 0;
}
