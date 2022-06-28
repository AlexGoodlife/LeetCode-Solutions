/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Runtime: Varied from 7ms to 10 ms | beats roughly 50% of other submissions
Memory Usage: 5.6 MB | beats 32% of other submissions
*/
#include <stdio.h>
#include <stdlib.h>


//newton's formula
int mySqrt(int x){
    long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}

int main(void){
    return 0;
}
