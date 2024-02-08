#include <stdio.h>
#define WEIGHT 20
#define LENGTH 5
int knapSack(int[],int[],int[]);

int main(){
    char* items[LENGTH];
    int values[LENGTH];
    int weights[LENGTH];
    int answer[LENGTH];
    char* result[LENGTH];
    for (size_t i = 0; i < LENGTH; i++)
    {
        char String[21];
        scanf("%20s",String);
        items[i] = String;
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
    }

    int maxProfit = knapSack(weights,values,answer);
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d",answer[i]);
    }

 //   printf("Maximum profit: %d\n",maxProfit);
 //   printf("Selected items:");
    for (size_t i = 0; i < LENGTH; i++)
    {
        if(answer[i] == 1){
            result[i] = items[i];
            printf(" %s",items[i]);
        }
    }
}

int knapSack(int weights[],int values[], int selected_bool[]){
    int dynamicTable[LENGTH][WEIGHT] = {0};
    for (size_t i = 0; i < LENGTH; i++)
    {
        for (size_t j = 0; j < WEIGHT; j++)
        {    
            int withI;
            int withOuti;
            if(i == 0){
               if(weights[i] <= j){
                dynamicTable[i][j] = values[i];
               }
            }else{
             withOuti = dynamicTable[i - 1][j];
             if (j - weights[i] < 0)
             {
                 withI = 0;
             }else{
                withI = dynamicTable[i-1][j - weights[i]] + values[i];
            }
            if (withI < withOuti){
                dynamicTable[i][j] = withOuti;
            }else {
                dynamicTable[i][j] = withI;
            }
                }
            
    }
    }
    for (size_t i = LENGTH - 1; i >= 0; i--){
    int j = 20;
    if(i == 0 || dynamicTable[i][j] == 0){
        selected_bool[i] = 0;
        break;
    }else{
        selected_bool[i] = 1;
        break;
    }
        if(dynamicTable[i][j] == dynamicTable[i-1][j]){
            selected_bool[i] = 0;
        }else{
            j = j - weights[i];
            selected_bool[i] = 1;
        }
    
    }
    for (size_t i = 0; i < LENGTH; i++)
    {
        for (size_t j = 0; j < WEIGHT; j++)
        {
            printf("%d ",dynamicTable[i][j]);
        }
        printf("\n");
        
    }
    
    return dynamicTable[LENGTH][WEIGHT];
  }