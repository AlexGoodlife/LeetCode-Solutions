/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Runtime 7ms | beats 98% of other submissions
Memory Usage 7.1 MB | beats 71% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int factorial(int x){
    return x <= 1 ? 1 : x * factorial(x-1);
}

void make_permute(int *nums, int numsSize, int*returnSize,int **result, int *append, int appendSize, int **returnColumnSize, bool*used){
    if(appendSize == numsSize){
        result[*returnSize] = (int*)malloc(sizeof(int)*(numsSize));
        memcpy(result[(*returnSize)], append, (numsSize)*sizeof(int));
        (*returnColumnSize)[(*returnSize)++] = numsSize;
        return;
    }
        for(int i = 0; i < numsSize;i++){
            if(!used[i]){
                used[i] = true;
                append[appendSize] = nums[i];
                make_permute(nums, numsSize, returnSize,result,append,appendSize+1, returnColumnSize,used);
                used[i] = false;
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    long long int alloc = factorial(numsSize);
    int **result = (int**)(malloc(sizeof(int*)*alloc));
    int *append = (int*)malloc(sizeof(int)*(numsSize));
    *returnColumnSizes = malloc(alloc*sizeof(int));
    bool *used = calloc(numsSize, sizeof(bool));
    make_permute(nums, numsSize, returnSize,result,append, 0,returnColumnSizes,used);
    free(append);
    free(used);
    result = (int**)realloc(result, sizeof(int*)*(*returnSize));
    return result;
}



int main(void){
    return 0;
}