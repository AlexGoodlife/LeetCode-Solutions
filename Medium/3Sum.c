/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

Runtime: 319ms | beats 20.0% of other submissions
Memory Usage: 20.7 MB | beats 70% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>

int binary_search(int *nums, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (target == nums[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (target < nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int cmpfunc(const void * a, const void * b){
   int val1 = *(int*)a;
   int val2 = *(int*)b;
   return ( val1 - val2 ); 
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,(size_t)numsSize,sizeof(int),cmpfunc);
    int alloc = numsSize;
    int **result = (int**)malloc(sizeof(int*) *alloc);
    *returnColumnSizes = malloc(alloc*sizeof(int));
    *returnSize = 0;
    if(numsSize < 3){
        result = (int**)realloc(result, sizeof(int*)*1);
        return result;
    }
    for(int i = 0; i < numsSize;i++){
        for(int j = i+1; j < numsSize;j++){
            int find = binary_search(nums+(j+1), numsSize-(j+1), (-(nums[i]+nums[j])));
            if(find != -1){
                result[(*returnSize)] = malloc(sizeof(int) *3);
                result[(*returnSize)][0] = nums[i];
                result[(*returnSize)][1] = nums[j];
                result[(*returnSize)][2] = (nums+j+1)[find];
                (*returnColumnSizes)[(*returnSize)++] = 3;
            }
            if(*returnSize == alloc){
                alloc = alloc * 2;
                result = (int**)realloc(result, sizeof(int*) * alloc);
                *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*alloc);
            }
            while(j+1 < numsSize && nums[j] == nums[j+1])
                j++;
        }
        while(i+1 < numsSize && nums[i] == nums[i+1])
            i++;
        
    }
    result = (int**)realloc(result, sizeof(int*)*(*returnSize));
    *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
    free(nums);
    return result;
    

}

int main(void){
    return 0;
}