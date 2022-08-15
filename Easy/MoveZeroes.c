/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Runtime: 104 ms : Faster than 75% | Memory: 15 MB: better than 98%
*/

void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for(int i= 0; i < numsSize;i++){
        if(nums[i] != 0){
            nums[j++] = nums[i];
        }
    }
    for(; j < numsSize;j++)
            nums[j] = 0;
}

int main(){
    return 0;
}