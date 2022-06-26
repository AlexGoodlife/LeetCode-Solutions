/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

Runtime: 7ms | beats 85% of other submissions
Memory Usage: 6.9 MB | beats 89% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>

char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** result = malloc(sizeof(char*) * n);
    char convert[128];
    int j = 0;
    for(int i = 1; i <= n;i++){
        if(i % 15== 0){
            result[j] = strdup("FizzBuzz");
        }
        else if(i % 3 == 0){
            result[j] = strdup("Fizz");
        }
        else if(i % 5 == 0){
            result[j] = strdup("Buzz");
        }
        else{
            sprintf(convert, "%d", i);
            result[j]= strdup(convert);
        }
        j++;
            
    }
    return result;
}


int main(void){
    return 0;
}