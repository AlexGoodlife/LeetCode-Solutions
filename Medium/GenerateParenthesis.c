/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Runtime: 0 ms | Beats 100% of other submissions
Memory Usage 6.6 MB | 73.3 % of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

void parenthesis(int n, int*returnSize, char**result, char*stack, int size, int opencount, int closedcount){
    if(closedcount ==n){
        stack[size] = '\0';
        char *append = malloc(sizeof(char) * 2*n+1);
        strcpy(append,stack);
        result[(*returnSize)++] = append;
        return;
    }
    if(opencount < n){
        stack[size] = '(';
        parenthesis(n,returnSize,result,stack,size+1,opencount+1,closedcount);
    }
    if(closedcount < opencount && closedcount < n){
        stack[size] = ')';
        parenthesis(n, returnSize, result, stack, size+1,opencount,closedcount+1);
    }
    
}



char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    int alloc = 2000;
    char **result = (char**)malloc(sizeof(char*)*(alloc));
    char* stack = (char*)malloc(sizeof(char)*((n*2)+1));
    int size = 0;
    parenthesis(n, returnSize, result,stack,size,0,0);
    free(stack);
    result = realloc(result, sizeof(char*)*(*returnSize));
    return result;
}



int main(void){
    return 0;
}