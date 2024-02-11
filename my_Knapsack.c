#include <stdio.h>
#define WEIGHT 20
#define LENGTH 5
int knapSack(int[],int[],int[]);

int main(){
    char items[LENGTH][21];
    int values[LENGTH];
    int weights[LENGTH];
    int answer[LENGTH];
    char* result[LENGTH];
    int maxProfit = 0;
    for (size_t i = 0; i < LENGTH; i++)
    {
        scanf("%20s",items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d " ,values[i]);
    }
    printf("\n");
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d " ,weights[i]);
    }
    printf("\n");
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%s " ,items[i]);
    }
    printf("\n");
    
    maxProfit = knapSack(weights,values,answer);
    printf("answers are: ");
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d",answer[i]);
    }

    printf("\nMaximum profit: %d \n",maxProfit);
 //   printf("Selected items:");
    for (size_t i = 0; i < LENGTH; i++)
    {
        if(answer[i] == 1){
            result[i] = items[i];
            printf(" %s",result[i]);
        }
    }
}

int knapSack(int weights[],int values[], int selected_bool[]){
    int dynamicTable[LENGTH][WEIGHT+1] = {0};
    
    //creating the dynamic table
    for (size_t i = 0; i < LENGTH; i++)
    {
        for (size_t j = 0; j <= WEIGHT; j++)
        {   
            int withI = 0;
            int withOuti = 0;
            int withIHelp;
            if(i == 0){
               if(weights[i] <= j){
                dynamicTable[i][j] = values[i];
               }
               continue;
            }
            withOuti = dynamicTable[i - 1][j];
            withIHelp = j - weights[i];

            if (withIHelp < 0){
                withI = 0;
            }else{
                withI = dynamicTable[i-1][withIHelp] + values[i];
            }
            if (withI < withOuti){
                dynamicTable[i][j] = withOuti;
            }else {
                dynamicTable[i][j] = withI;
            }  
        }
    }
    for (size_t i = 0; i < LENGTH; i++)
    {
        for (size_t j = 0; j <= WEIGHT; j++)
        {
            printf("%d ",dynamicTable[i][j]);
        }
        printf("\n");
        
    }

    //tracking down the path to know which items were taken
    int currWeight = 20;
    int index = 4;
    while(index >= 0){
        int withOuti = 0;
        if(index == 0){
            if(dynamicTable[index][currWeight] == values[index]){
                selected_bool[index] = 1;
                break;
            }else{
                selected_bool[index] = 0;
                break;
            }
        }
        withOuti = dynamicTable[index-1][currWeight];
        if(dynamicTable[index][currWeight] == withOuti){
            selected_bool[index] = 0;
        }else {
            selected_bool[index] = 1;
            currWeight = currWeight - weights[index];
        }
        index--;
    }
    
    return dynamicTable[LENGTH-1][WEIGHT];
  }