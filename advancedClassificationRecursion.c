#define true 1
#define false 0
#include "NumClass.h"

int reverseNumber(int);
int isPalindromeHelper(int,int);
int isArmstrongHelper(int, int);
int countDigits(int);
int powNum(int, int);

int isPalindrome(int num){
    int reverseNum = reverseNumber(num);
    if(isPalindromeHelper(num, reverseNum)){return true;}
    return false;
}

int reverseNumber(int num){
    int ans = 0;
    while(num > 0){
        ans = ans * 10 + num % 10;
        num = num / 10;
    }
    return ans;
}

int isPalindromeHelper(int origin, int reverse){
    if(origin >= 0 && origin <= 9){
        return true;
    }
    if(origin % 10 != reverse % 10){
        return false;
    }
    return isPalindromeHelper(origin/10, reverse/10);
}

int isArmstrong(int num){
    int count = countDigits(num);
    if(num == isArmstrongHelper(num, count)){
        return true;
    }
    return false;
}

int isArmstrongHelper(int num, int count){
    if(num == 0){
        return num;
    }
    return isArmstrongHelper(num/10,count) + powNum(num % 10,count);
}

int countDigits(int num){
    int count = 0;
    while(num > 0){
        num = num / 10;
        count++;
    }
    return count;
}

int powNum(int num, int count){
    int ans = 1;
    for (int i = 1; i <= count; i++)
    {
        ans = ans * num;
    }
    return ans;
}