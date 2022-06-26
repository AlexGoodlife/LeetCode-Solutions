/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Runtime: 101 ms | beats 71 % of other submissions
Memory Usage: 244.8 MB | beats 38 % of other submissions
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().


Used sorting for this one
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *original;
    char *sorted;
}StrStr;

StrStr* strstr_ref(char*original, char*sorted){
    StrStr x = {original, sorted};
    StrStr *result = (StrStr*)malloc(sizeof(StrStr));
    *result = x;
    return result;
}

int cmp_string(char *x, char *y){
    return *x - *y;
}

int cmp_void(const void *x, const void *y){
    return cmp_string((char*)x, (char*)y);
}

StrStr **make_map(char **a, int n, int *map_size){
    StrStr **result = (StrStr**)malloc(sizeof(StrStr*)*n);
    for(int i = 0; i < n;i++){
        char* sorted = (char*)malloc(sizeof(char)*strlen(a[i])+1);
        strcpy(sorted,a[i]);
        qsort(sorted,(size_t)strlen(a[i]),sizeof(char),cmp_void);
        result[(*map_size)++] = strstr_ref(a[i], sorted);
    }
    return result;
}

int cmp_strstr(StrStr *x, StrStr*y){
    return strcmp(x->sorted, y->sorted);
}

int cmp_str_void(const void *x, const void *y){
    return cmp_strstr(*(StrStr**)x, *(StrStr**)y);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int map_size = 0;
    int i = 0;
    int str_size = 0;
    StrStr **map = make_map(strs, strsSize, &map_size);
    qsort(map, (size_t)map_size, sizeof(StrStr*), cmp_str_void);
    char *** result= (char***)malloc(sizeof(char**)*strsSize);
    *returnColumnSizes = malloc(sizeof(int)*strsSize);
    *returnSize = 0;
    int j = i;
    while(i < map_size){
        j = i;
        result[*returnSize]= (char**)malloc(sizeof(char*)*strsSize);
        while(j<map_size && strcmp(map[i]->sorted, map[j]->sorted) == 0){
            result[*returnSize][str_size] = (char*)malloc(sizeof(char)*strlen(map[i]->original)+1);
            strcpy(result[*returnSize][str_size++], map[j] ->original);
            (*returnColumnSizes)[(*returnSize)] = str_size;
            j++;
        }
        (*returnSize)++;
        str_size = 0;
        i=+j;
    }
    free(map);
    result = realloc(result, sizeof(char**)*(*returnSize));
    
    return result;
}

int main(void){
    return 0;
}
