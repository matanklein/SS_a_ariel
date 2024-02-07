#include <stdio.h>
#include "my_mat.h"
int main(){
    int mat[10][10];
    char input;
    scanf("%c", &input);
    while(input != 'D'){
        if(input == 'A'){
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
    }
    if(input == 'B'){
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        int ans = shortestPath(mat, i, j);
        if(ans > 0 && i != j){
            printf("True\n");
        }else{
            printf("False\n");
        }
    }
    if(input == 'C'){
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        int ans = shortestPath(mat, i, j);
        if(i != j && ans > 0){
            printf("%d\n", ans);
        }else{
            printf("-1\n");
        }
    }
    scanf("%c", &input);
    }
    
    
    return 0;
}