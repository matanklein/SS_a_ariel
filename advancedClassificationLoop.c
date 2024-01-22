#define true 1
#define false 0
#include "NumClass.h"

int isPalindrome(int num){
    int tmp = num;
    int reverseNum = 0;
    while(tmp > 0){
        reverseNum = (reverseNum * 10) + (tmp % 10);
        tmp = tmp / 10;
    }
    if(reverseNum == num){
        return true;
    }
    return false;
}

int isArmstrong(int num){
    int sum = 0;
    int tmp = num;
    int len = 0;
    while(tmp > 0){
        len++;
        tmp = tmp / 10;
    }
    tmp = num;
    while(tmp > 0){
        int digit = tmp % 10;
        tmp = tmp / 10;
        int pow = 1;
        for (int i = 1; i <= len; i++)
        {
            pow = pow * digit;
        }
        sum = sum + pow;
    }
    if(sum == num){
        return true;
    }
    return false;
}