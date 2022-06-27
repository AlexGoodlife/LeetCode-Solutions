/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Runtime: 0 ms | beats 100% of other submissions
Memory Usage: 5.7 MB | beats 93.8% of other submissions
*/

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int size = 0;
    *returnSize = (matrixSize * (*matrixColSize));
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    int stop_r = *matrixColSize;
    int stop_l = 0;
    int stop_u = 1;
    int stop_d = matrixSize;
    int i = 0;
    int j = 0;
    while(size < *returnSize){
        // MOVE RIGHT
        while(size < *returnSize && j < stop_r){
            result[size++] = matrix[i][j];
            j++;
        }
        j--;
        i++;
        stop_r--;
        // MOVE DOWN
        while(size < *returnSize && i < stop_d){
            result[size++] = matrix[i][j];
            i++;
        }
        i--;
        j--;
        stop_d--;
        // MOVE LEFT
        while(size < *returnSize && j >= stop_l){
            result[size++] = matrix[i][j];
            j--;
        }
        j++;
        i--;
        stop_l++;
        //MOVE UP
        while(size < *returnSize && i >= stop_u){
            result[size++] = matrix[i][j];
            i--;
        }
        i++;
        j++;
        stop_u++;
    }
    return result;
}

int main(void){
    return 0;
}
