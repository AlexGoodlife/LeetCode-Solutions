/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Runtime: 17ms | beats 83% of other submissions
Memory Usage 6.7 MB| beats 68% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>


int findLastOccurrence(int *nums, int n, int target)
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
            low = mid + 1;
        }
         else if (target > nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
     return result;
}


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

typedef struct {
    int index;
    int value;
}Pair;

int pair_cmp(Pair x, Pair y){
    int result = x.value - y.value;
    if(result == 0)
        result = x.index - y.index;
    return result;
}

int pair_cmp_ref(Pair *x, Pair *y){
    return pair_cmp(*x, *y);
}

int pair_cmp_v(const void *x, const void *y)
{
  return pair_cmp_ref((Pair *)x, (Pair *)y);
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    *returnSize = k;
    int *result = (int*)malloc(sizeof(int)*k);
    Pair tally[matSize];
    for(int i = 0; i < matSize;i++){
        int find = findLastOccurrence(mat[i], *matColSize, 1);
        if(find != -1)
            tally[i].value = find+1;
        else
            tally[i].value = 0;
        tally[i].index = i;
    }
    qsort(tally, (size_t)matSize,sizeof(Pair),pair_cmp_v);
    for(int i = 0; i < k;i++){
        result[i] = tally[i].index;
    }
    
    return result;
    
}


int main(void){
    return 0;
}