int shortestPath(int arr[][10],int start, int end){
    int help[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(arr[i][j] == 0){
                help[i][j] = -1;
            }else{
                help[i][j] = arr[i][j];
            }
        }
        
    }
    
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {   
                if(help[i][k] != -1 && help[k][j] != -1){
                    if((help[i][j] > help[i][k] + help[k][j]) || help[i][j] == -1){
                        help[i][j] = help[i][k] + help[k][j];
                    }
                }
                
            }
            
        }
        
    }
    return help[start][end];
}