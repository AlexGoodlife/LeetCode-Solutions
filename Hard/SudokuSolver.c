/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Runtime: 18 ms | beats 55% of other submissions
Memory Usage: 5.7 MB | beats 85% of other submissions
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find_empty(char**board, int boardSize, int* boardColSize, int *row, int*col){
    for(int i = 0; i < boardSize;i++){
        for(int j = 0; j < (*boardColSize);j++)
            if(board[i][j] == '.'){
                *row = i;
                *col = j;
                return true;
            }
    }
    return false;
}

bool check_row(char **board,int row,int idx,char target,int*boardColSize){
    for(int j=0; j < *boardColSize;j++){
        if(j != idx && board[row][j] == target)
            return false;
    }
    return true;
}

bool check_collum(char**board, int col, int idx, char target, int boardSize){
    for(int i = 0; i < boardSize;i++){
        if(i != idx && board[i][col] == target)
            return false;
    }
    return true;
}

bool check_box(char **board, int idx, int jdx, char target, int boardSize, int*boardColSize){
    int box_x = idx / 3;
    int box_y = jdx / 3;
    for(int i = box_x*3; i < box_x*3+3;i++){
        for(int j = box_y*3; j < box_y*3+3;j++)
            if(i != idx && j != jdx && board[i][j] == target)
                return false;
    }
    return true;
}

bool is_valid(char**board, int boardSize, int* boardColsize, int i, int j, char target){
    bool row = check_row(board,i,j,target,boardColsize);
    if(!row)
        return false;
    bool col = check_collum(board,j,i,target,boardSize);
    if(!col)
        return false;
    bool box = check_box(board, i, j, target, boardSize, boardColsize);
    if(!box)
        return false;
    return true;
}


bool solveSudoku(char** board, int boardSize, int* boardColSize){
    int row;
    int col;
    if(!find_empty(board, boardSize, boardColSize, &row, &col))
        return true;
    for(int i = 1; i < 10;i++){
        if(is_valid(board, boardSize, boardColSize,row, col,(i+'0'))){
            board[row][col] = i+'0';
            if(solveSudoku(board, boardSize,boardColSize))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}



int main(void){
    return 0;
}