/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Runtime: 109 ms | beats 70% of other submissions
Memory Usage: 11.8 MB | beats 40 % of other submissions


*/


#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    return x >= y ? x : y;
}

int min(int x, int y){
    return x <= y ? x : y;
}


int maxArea(int* height, int heightSize){
    int *i = height;
    int h = 0;
    int *j = i+heightSize-1;
    int max_water = 0;
    while(i < j){
        h = min(*i, *j);
        max_water = max(max_water, ((j-i) * h));
        if(*i <= h)
            i++;
        if(*j <=h)
            j--;
    }
    return max_water;
    
}



int main(void){
    return 0;
}