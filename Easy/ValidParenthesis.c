/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Runtime: 0 ms | beats 100% of other submissions
Memory Usage 5.6 MB | beats 80% of other submisions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char * s){
    int sp = 0;
    int i = 0;
    char* stack = (char*)malloc(sizeof(char)*strlen(s));
    while(s[i]){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[sp++] = s[i];
        else{
            if(sp == 0)
                return false;
            switch(s[i]){
                case ')':
                    if(stack[--sp] != '('){
                        return false;
                    }
                    break;
                case ']':
                    if(stack[--sp] != '[')
                        return false;
                    break;
                default:
                    if(stack[--sp] != '{')
                        return false;
                    break;
                }
        }
        i++;
    }
    free(stack);
    return sp == 0;
}



int main(void){
    return 0;
}