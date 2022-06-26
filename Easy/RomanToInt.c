/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Given a roman numeral, convert it to an integer.

Runtime: 19 ms | beats 18 % of other submissions
Memory Usage: 5.7 MB | beats 99.9 % of other submissions    Not fast but mem efficient
*/

#include <stdio.h>
#include <stdlib.h>

int convert(char * s, int *a){
    int result = 0;
    for(int i = 0; s[i];i++)
    {
        switch(s[i]){
            case 'I':
                a[result++] = 1;
                break;
            case 'V':
                a[result++] = 5;
                break;
            case 'X':
                a[result++] = 10;
                break;
            case 'L':
                a[result++] = 50;
                break;
            case 'C':
                a[result++] = 100;
                break;
            case 'D':
                a[result++] = 500;
                break;
            case 'M':
                a[result++] = 1000;
                break;
        }
    }
    return result;
}

int romanToInt(char *s){
    int a[20];
    int n = convert(s, a);
    int result = 0;
    for(int i = 0; i < n; i++){
        if(i != 0 && a[i] > a[i-1]){
            result -= (2*a[i-1]);
            result += a[i];
        }
        else
            result += a[i];
    }
    return result;
}




int main(void){
    return 0;
}