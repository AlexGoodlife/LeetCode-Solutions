/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Runtime 81 ms | beats 73% of other submissions
Memory Usage 8.3 MB | beats 60% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
    int pos = numsSize-1;
    int i = pos;
    for(int i = pos-1;i >= 0;i--)
        if(i+nums[i] >=pos)
            pos = i;
    return pos == 0;;
    
}



int main(void){
    return 0;
}