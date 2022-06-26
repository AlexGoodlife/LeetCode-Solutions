/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. 
Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.


Runtime: 3 ms | beats 72 % of other submissions
Memory Usage: 5.8 MB 
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define PRE_MAX  2147483647 / 10
#define PRE_MIN -2147483648 / 10


int not_space(char *s){
    int result = 0;
    while(s[result] == ' '){
        result++;
    }
    return result;
}


int myAtoi(char * s){
    int result = 0;
    int n = 0;
    bool neg = 0;
    int i = 0;
    int start = not_space(s);
    char *string = s + start;
    if(string[0] == '+' || string[0] == '-'){
        i++;
        if(string[0] == '-')
            neg = true;
    }
    while(string[i] >= 48 && string[i] <= 57){
        if ((PRE_MAX < result) || (PRE_MAX == result && (string[i] -'0') >7)){
            return INT_MAX;
        }
        if((PRE_MIN > result) || (PRE_MIN == result && (string[i] -'0') > 8))
            return INT_MIN;
        result*= 10;
        if(!neg)
            result += string[i] - '0';
        else
            result -= string[i] - '0';
        i++;
        
    }
    return result;
}



int main(void){
    return 0;
}