#include <stdio.h>
#include "StrList.h"
#include <string.h>

#define maxLength 501

int main()
{
    int option;
    StrList *list = StrList_alloc();
    int index;
    //char *word;
    char str[maxLength];
    if (scanf("%d", &option) == EOF)
    {
        StrList_free(list);
        return 0;
    }
    while (option != 0)
    {
        

        switch (option)
        {
        case 1:

            int sizeOfWords = 0;
            scanf("%d", &sizeOfWords);

            int count = 0;
            while (count < sizeOfWords)
            {
                scanf("%s", str);
                char *word = (char*)malloc(strlen(str) + 1);
                if (word == NULL)
                {
                    return 0;
                }
                
                strcpy(word, str);
                StrList_insertLast(list, word);
                count++;
            }

            break;

        case 2:
            scanf("%d", &index);
            scanf("%s", str);
            char *word = (char *)malloc(strlen(str) + 1);
            if (word == NULL)
            {
                break;
            }
            strcpy(word, str);
            StrList_insertAt(list, word, index);
            break;

        case 3:
            StrList_print(list);
            break;

        case 4:
            printf("%ld\n", StrList_size(list));
            break;

        case 5:
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;

        case 6:
            printf("%d\n", StrList_printLen(list));
            break;

        case 7:
            scanf("%s", str);
            word = (char *)malloc(strlen(str) + 1);
            if (word == NULL)
            {
                break;
            }
            strcpy(word, str);
            printf("%d\n", StrList_count(list, word));
            free(word);

            break;

        case 8:
            scanf("%s", str);
            word = (char *)malloc(strlen(str) + 1);
            if (word == NULL)
            {
                break;
            }
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
            printf("%d\n", StrList_isSorted(list));
            break;
        }
        if (scanf("%d", &option) == EOF)
        {
            StrList_free(list);
            return 0;
        }
    }
    StrList_free(list);
    return 0;
}