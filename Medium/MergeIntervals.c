/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals.
return an array of the non-overlapping intervals that cover all the intervals in the input.

Runtime: 60 ms | beats 90% of other submissions
Memory Usage: 12.6 MB | beats 42% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    return x > y ? x : y;
}

int cmp(int* x, int* y){
    return x[0] - y[0];
}
int cmp_func(const void*a, const void*b){
    return cmp(*(int**)a, *(int**)b);
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **result = (int**)malloc(sizeof(int*)*intervalsSize);
    *returnColumnSizes = malloc(sizeof(int)*intervalsSize);
    *returnSize = 0;
    int i = 0;
    qsort(intervals, (size_t)intervalsSize, sizeof(int*), cmp_func);
    int *temp = intervals[i++];
    while(i < intervalsSize){        
        if(temp[1] >= intervals[i][0]){
            temp[1] = max(temp[1], intervals[i][1]);
        }
        else{
            result[*returnSize] = (int*)malloc(sizeof(int)*2);
            (*returnColumnSizes)[*returnSize] = 2;
            memcpy(result[(*returnSize)++],temp,sizeof(int)*2);
            temp = intervals[i];
        }
        i++;
    }
    result[*returnSize] = (int*)malloc(sizeof(int)*2);
    (*returnColumnSizes)[*returnSize] = 2;
    memcpy(result[(*returnSize)++],temp,sizeof(int)*2);
    free(temp);
    //result = realloc(result, sizeof(int*)*(*returnSize));
    return result;
     
}


int main(void){
    return 0;
}