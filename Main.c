#include <stdio.h>
#include "StrList.h"
#include <string.h>
#define maxLength 501

int main(){
    int option;
    StrList* list = StrList_alloc();
    char str[maxLength];
    char* word;
    int index;
    if(scanf("%d", &option) == EOF){
        StrList_free(list);
        return 0;
    }
    while(option != 0){
        switch (option)
        {
        case 1: 
            int sizeOfWords = 0;
            scanf("%d", &sizeOfWords);

            for (size_t i = 0; i < sizeOfWords; i++)
            {
                scanf("%s", str);
                word = (char*)malloc(strlen(str) + 1);
                if(word == NULL){break;}
                strcpy(word, str);
                StrList_insertLast(list, word);
            }
            
            break;

        case 2:
            scanf("%d", &index);
            scanf("%s", str);
            word = (char*)malloc(strlen(str) + 1);
            if(word == NULL){break;}
            strcpy(word, str);
            StrList_insertAt(list, word, index);
            break;

        case 3:
            StrList_print(list);
            break;

        case 4:
            printf("%ld", StrList_size(list));
            break;

        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;

        case 6:
            printf("%d", StrList_printLen(list));
            break;

        case 7:
            scanf("%s", str);
            word = (char*)malloc(strlen(str) + 1);
            if(word == NULL){break;}
            strcpy(word, str);
            printf("%d", StrList_count(list, word));
            free(word);

            break;

        case 8:
            scanf("%s", str);
            word = (char*)malloc(strlen(str) + 1);
            if(word == NULL){break;}
            strcpy(word, str);
            StrList_remove(list, word);
            free(word);
            break;

        case 9:
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;

        case 10:
            StrList_reverse(list);
            break;

        case 11:
            StrList_free(list);
            break;

        case 12:
            StrList_sort(list);
            break;

        case 13:
            printf("%d", StrList_isSorted(list));
            break;

        }
    }
    StrList_free(list);
    return 0;
}