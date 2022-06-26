/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 5.7 MB | beats 32.55 % of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

#define CONTROL_HIGH 214748364
#define CONTROL_LOW -214748364

int reverse(int x){
    int result = 0;
    while(x != 0){
        if(result > CONTROL_HIGH || result < CONTROL_LOW)
            return 0;
        result = (result * 10) + (x % 10);
        x /= 10;
    }
    return result;
}

int main(void){
    return 0;
}