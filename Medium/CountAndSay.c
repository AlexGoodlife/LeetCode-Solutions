/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 6.4 MB | beats 60 % of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

int count_while(char*s, char target){
    int result = 0;
    while(s[result] != '\0' && s[result] == target)
        result++;
    return result;
}

char* count(char*s){
    int size = 0;
    int allocate = 11;
    char* result = (char*)malloc(sizeof(char)*allocate+1);
    int i = 0;
    while(i < strlen(s)){
        int z = count_while(s+i,s[i]);
        result[size++] = z+'0';
        result[size++] = s[i];
        if(size >= allocate){
            allocate *= 2;
            result = realloc(result, sizeof(char)*allocate+1);
        }
        i+=z;
    }
    free(s);
    result[size] = '\0';
    result = realloc(result, sizeof(char)*size+1);
    return result;
    
}


char * countAndSay(int n){
    int i = 0;
    char*result = malloc(sizeof(char)*2);
    result[0] = '1';
    result[1] = '\0';
    while(n > 1){
        result = count(result);
        n--;
    }
    return result;
}



int main(void){
    return 0;
}