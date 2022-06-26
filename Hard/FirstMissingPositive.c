/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Runtime: 145ms | beats 98% of other submissions
Memory Usage: 33 MB | beats 6 % of other submissions
*/


#include <stdio.h>
#include <stdlib.h>


int firstMissingPositive(int* nums, int numsSize){
    int *tally = (int*)calloc(numsSize+2,sizeof(int));
    for(int i = 0; i < numsSize;i++){
        if(nums[i]> 0 && nums[i] <numsSize+1){
            tally[nums[i]]++;
        }
    }
    for(int i = 1; i <= numsSize+1;i++)
        if(tally[i] == 0)
            return i;
    return 1;
}


int main(void){
    return 0;
}