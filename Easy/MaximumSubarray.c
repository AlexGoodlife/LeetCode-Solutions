/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Runtime: Best was 112 ms | beats 98% of submissions, times varied wildly for the same code| worse was 246 ms beats 5% of submissions
Memory Usage 12.2 MB
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int x, int y){
  return x > y ? x : y;  
}

int maxSubArray(int* nums, int numsSize){
    int best = INT_MIN;
    int sum = 0;
    for(int i = 0; i < numsSize;i++){
        sum = max(sum+nums[i],nums[i]);
        best = max(best, sum);
    }
    return best;
}

int main(void){
    return 0;
}
