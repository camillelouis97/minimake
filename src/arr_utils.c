#include "arr_utils.h"

char* my_strncpy(char* str, int len)
{
    char* res = malloc(len);
    if (!res)
        return NULL;
    strncpy(res, str, len);
    res[len] = '\0';
    return res;
}

void my_strcat(char* str1, char* str2)
{
    str1 = realloc(str1, strlen(str1) + strlen(str2));
    if (!str1)
        return;
    strcat(str1, str2);
}

char** arr_add(char* str, char** arr)
{
    if (!str)
        return NULL;
    if (arr == NULL)
    {
        arr = malloc(strlen(str) + sizeof(NULL));
        arr[0] = str;
        arr[1] = NULL;
    }
    else
    {
        int len = 0;
        int i = 0;
        for (; arr[i] != NULL; i++)
            len += strlen(arr[i]);
        arr = realloc(arr, len + strlen(str) + 1);
        arr[i] = str;
        arr[i + 1] = NULL;
    }
    return arr;
}

char** arr_add_index(char* str, char** arr, int index)
{
    if (!str)
        return NULL;
    if (arr == NULL)
    {
        arr = malloc(strlen(str) + sizeof(NULL));
        arr[0] = str;
        arr[1] = NULL;
    }
    else
    {
        int len = 0;
        int i = 0;
        for (; arr[i] != NULL; i++)
            len += strlen(arr[i]);
        for (int j = i; j < index; j++)
          len += 1;
        arr = realloc(arr, len + strlen(str) + 1);
        if (arr[index] == NULL)
          arr[index] = str;
        else
          my_strcat(arr[index], str);
        arr[index + 1] = NULL;
        for (; i < index; i++)
          arr[i][0] = '\0';
    }
    return arr;
}
