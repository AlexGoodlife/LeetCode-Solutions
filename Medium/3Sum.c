/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

Runtime: 343ms | beats 16.12% of other submissions
Memory Usage: 20.7 MB | beats 70% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>

int ints_rank(const int *a, int n, int x)
{
  int result = 0;
  while (n > 0)
  {
    int m = n / 2;
    if (x <= a[m])
      n = m;
    else
    {
      result += m+1;
      a += m+1;
      n -= m+1;
    }
  }
  return result;
}

int ints_bfind(const int *a, int n, int x)
{
  int r = ints_rank(a, n, x);
  return r < n && a[r] == x ? r : -1;
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
    int size = 0;
    *returnSize = 0;
    if(numsSize < 3){
        result = (int**)realloc(result, sizeof(int*)*1);
        return result;
    }
    for(int i = 0; i < numsSize;i++){
        for(int j = i+1; j < numsSize;j++){
            int find = ints_bfind(nums+(j+1), numsSize-(j+1), (-(nums[i]+nums[j])));
            if(find != -1){
                result[size] = malloc(sizeof(int) *3);
                result[size][0] = nums[i];
                result[size][1] = nums[j];
                result[size++][2] = (nums+j+1)[find];
            }
            if(size == alloc){
                alloc = alloc * 2;
                result = (int**)realloc(result, sizeof(int*) * alloc);
            }
            while(j+1 < numsSize && nums[j] == nums[j+1])
                j++;
        }
        while(i+1 < numsSize && nums[i] == nums[i+1])
            i++;
        
    }
    *returnSize = size;
    result = (int**)realloc(result, sizeof(int*)*size);
    *returnColumnSizes = malloc(size*sizeof(int));
    for(int i = 0; i < size;i++)
        (*returnColumnSizes)[i] = 3;
    return result;
}

int main(void){
    return 0;
}