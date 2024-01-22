#define true 1
#define false 0

int isStrong(int number){
    int sum = 0;
    int digit;
    int num = number;
    while(num > 0){
        int tmp = 1;
        digit = num % 10;
        while(digit > 0){
            tmp = tmp * digit;
            digit--;
        }
        sum = sum + tmp;
        num = num / 10;
    }
    if(sum == number){
        return true;
    }
    return false;
}

int isPrime(int number){
    if(number == 1){return true;}
    for (int i = 2; i*i <= number; i++)
    {
        if(number % i == 0 && i != number){
            return false;
        }
    }
    return true;
}