/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Runtime: 0ms | beats 100% of other submissions
Memory Usage: 6.4 MB | beats 27% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>

void swap(int*p, int*q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}


void rotate(int** matrix, int r, int*c){
    int temp = 0;
    for(int i = 0; i < r/2;i++){
        for(int j = i; j < *c-i-1;j++){
            temp = matrix[i][j];
            swap(&temp, &matrix[j][*c-i-1]);
            swap(&temp, &matrix[*c-i-1][*c-j-1]);
            swap(&temp, &matrix[*c-j-1][i]);
            swap(&temp, &matrix[i][j]);
        }
    }
}


int main(void){
    return 0;
}