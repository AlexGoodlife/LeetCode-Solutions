/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Runtime: 0ms | beats 100% of submissions
Memory Usage: 6.3 MB | beats 8.83% of submissions
*/


#include <stdio.h>
#include <stdlib.h>

char *buttons[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combinations(char*digits, char*r, int i,int size,char**result, int *returnSize){
    if(size == strlen(digits)){
        r[size] = '\0';
        result[*returnSize] = (char*)malloc(sizeof(char)*strlen(digits)+1);
        strcpy(result[(*returnSize)++], r);
        return;
    }
    int index = (digits[i] - '0') -2;
    for(int j = 0; buttons[index][j] != '\0';j++){
        r[size] = buttons[index][j];
        combinations(digits, r,i+1,size+1,result,returnSize);
    }
}


char ** letterCombinations(char * digits, int* returnSize){
    int i = 0;
    int size = 0;
    int len = strlen(digits);
    *returnSize = size;
    int alloc = pow(4,len);
    char **result = (char**)malloc(sizeof(char*)*alloc);
    char* append = (char*)malloc(sizeof(char)*len+1);
    if(strlen(digits) > 0)
        combinations(digits, append, 0,size,result,returnSize);
    free(append);
    result = realloc(result, sizeof(char*)*(*returnSize));
    return result;
    
}


int main(void){
    return 0;
}