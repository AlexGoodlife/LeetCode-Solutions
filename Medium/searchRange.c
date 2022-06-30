/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Runtime 8ms | beats 88% of other submissions
Memory Usage: 7.6  MB 
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarysearch(int *nums, int n, int target, bool go_right)
{
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high){
        int mid = (low + high)/2;
        if (target == nums[mid]){
            result = mid;
            if(go_right)
                low = mid+1;
            else
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

int* searchRange(int* nums, int n, int target, int* returnSize){
    int low = 0, high = n-1;
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    int first = binarysearch(nums, n, target, false);
    result[0] = first;
    int second = binarysearch(nums,n,target,true);
    result[1] = second;
    return result;
}


int main(void){
    return 0;
}