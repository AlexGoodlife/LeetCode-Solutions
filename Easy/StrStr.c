/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Runtime: 2ms | beats 49% of other submissions
Memory Usage 5.7 MB | beats 64 % of other submissions
*/
#include <stdio.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle){
    if(needle[0] == '\0')
        return 0;
     int i = 0;
    while(haystack[i] && strlen(haystack+i) >= strlen(needle)){
        if(strncmp(haystack+i, needle,strlen(needle)) == 0)
           return i;
        i++;
    }
    return -1;
}

int main(void){
    return 0;
}