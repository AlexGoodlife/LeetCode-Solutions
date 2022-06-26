/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 5.9 MB | beats 61.84% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
    return x <= y ? x : y;
}


char * longestCommonPrefix(char ** a, int n){
    if(n== 1)
        return a[0];
    if(n== 0)
        return "";
    int size = 0;
    int count = 0;
    for(int i = 0; i <strlen(a[0]);i++){
        char c = a[0][i];
        for(int j = 0; j < n;j++){
            if(a[j][i] == c)
                count++;
            else{
                break;
            }  
        }
        if(count == n)
            size++;
        else
            break;
        count = 0;
    }

    char*result=(char*)malloc(sizeof(char)*(size+1));
    strncpy(result,a[0], size);
    result[size] = '\0';
    return result;
    
}



int main(void){
    return 0;
}