/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Runtime: 10ms | beats 90% of other submissions
Memory Usage 5.8 MB | beats 71% of other submissions
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    bool row = check_row(board,i,j,board[i][j],boardColsize);
    if(!row)
        return false;
    bool col = check_collum(board,j,i,board[i][j],boardSize);
    if(!col)
        return false;
    bool box = check_box(board, i, j, board[i][j], boardSize, boardColsize);
    if(!box)
        return false;
    return true;
}


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for(int i = 0; i < boardSize;i++)
        for(int j = 0; j < *boardColSize;j++)
            if(board[i][j] != '.' && !is_valid(board, boardSize, boardColSize, i, j, board[i][j]))
                return false;
    return true;
}


int main(void){
    return 0;
}