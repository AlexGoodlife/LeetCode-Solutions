/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Runtime: 4ms | beats 89% of other submissions
Memory Usage: 6.4 MB | beats 89% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void tally_letters(char *s, int *a){
    for(int i = 0; s[i];i++){
        a[s[i]-'a']++;
    }
}

bool canConstruct(char * ransomNote, char * magazine){
    int tally_2[26] = {0};
    tally_letters(magazine,tally_2);
    for(int i = 0; ransomNote[i];i++)
        if(tally_2[ransomNote[i]-'a']-- <= 0)
            return false;
    return true;
}

int main(void){
    return 0;
}