/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Runtime 0 ms | beats 100% of other submissions
Memory Usage 5.7 MB | beats 28% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double myPow(double x, int n){
    double result = 0;
    if(x < 0){
        result = n % 2 == 0 ? exp2(n * log2(-x)) : -(exp2(n*log2(-x)));
    }
    else
        result = exp2(n * log2(x));
    return result;
}


int main(void){
    return 0;
}