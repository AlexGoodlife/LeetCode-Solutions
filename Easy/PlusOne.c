/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Runtime: Varied from 0 ms to 7 ms | from beats 100% to 14 % who knows
Memory Usage: Varied from 5.8 to 6.2 MB | from beats 97% to 31%, again who knows
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    bool carry = false;
    int add = 0;
    *returnSize = digitsSize;
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    add = digits[digitsSize-1] + 1;
    if(add >= 10){
        carry = true;
        result[(*returnSize)-1] = 0;
        int i = digitsSize -2;
        while(i >= 0 && carry == true){
            add = digits[i]+1;
            if(add >= 10){
                 result[i] = 0;
                    i--;
            }
            else{
                result[i] = add;
                carry = false;
            }
        }
        if(carry == true){
            (*returnSize)++;
            result = realloc(result,sizeof(int)*(*returnSize));
            result[0] = 1;
            for(int i = 1; i < (*returnSize);i++)
                result[i] = 0;
        }
        else{
            memcpy(result,digits,sizeof(int)*i);
        }
            
    }
    else{
        result[(*returnSize)-1] = add;
        memcpy(result, digits, sizeof(int)*((*returnSize)-1));
    }
    free(digits);
    return result;
   
}


int main(void){
    return 0;
}
