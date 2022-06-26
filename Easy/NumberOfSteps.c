/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.


Runtime: 0ms | beats 100% of other submissions
Memory Usage: 5.6 MB| beats 40% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

int numberOfSteps(int num){
    int count = 0;
    while(num > 0){
        if(num % 2 == 0)
            num = num / 2;
        else
            num--;
        count++;
    }
    return count;
}

int main(void){
    return 0;
}