/*

Given a string s, find the length of the longest substring without repeating characters.

Runtime is terrible 285ms | beats 6% of other submissions
Memory usage: 6.1 mb | beats 20% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_unique(char *s, int n, char x){
    for(int i = 0; i < n;i++){
        if(s[i] == x)
            return false;
    }
    return true;
}


void print_string(char *s, int n){
    int i = 0;
    while(i<n){
        printf("%c ", s[i]);
        i++;
    }
    printf("\n");
}


int lengthOfLongestSubstring(char * s){
    char *check = (char*)malloc(sizeof(char)*strlen(s));
    //printf("I MADE IT");
    int max = 1;
    int count = 0;
    for(int i = 0; s[i];i++){
        for(int j = i; s[j];j++){
            if(!is_unique(check,count,s[j])){
                max = count > max ? count : max;
                count = 0;
                break;
            }
            check[count++] = s[j];
            //print_string(check, count);
        }
    }
    max = count > max ? count : max;
    return s[0] == '\0' ? 0 : max;
        
}

int main(void){
    return 0;
}