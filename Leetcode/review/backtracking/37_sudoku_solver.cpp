/*******************************************************************
* https://leetcode.com/problems/sudoku-solver/
* Hard
* 
* Conception: 
*  1. 
*
* Write a program to solve a Sudoku puzzle by filling the empty cells.
*
* A sudoku solution must satisfy all of the following rules:
*    Each of the digits 1-9 must occur exactly once in each row.
*    Each of the digits 1-9 must occur exactly once in each column.
*    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
*
* The '.' character indicates empty cells.
*
*
* Key:
*  1.
*
* Reference:
*  1. https://www.youtube.com/watch?v=ucugbKwjtRs
*
*******************************************************************/
class Solution {
public:
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    rows[i][ board[i][j] - '1' ] = true;
                    cols[j][ board[i][j] - '1' ] = true;
                    boxes[ (i/3)*3 + j/3 ][ board[i][j] - '1' ] = true;
                }
            }
        }
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col){
        while(board[row][col] != '.'){
            col++;
            if(col >= 9){
                col = 0;
                row++;
            }
            if(row >= 9){
                return true;
            }
        }
        for(int i = 0; i < 9; i++){
            if( rows[row][i] || cols[col][i] || boxes[ (row/3)*3 + col/3 ][i] ) continue;

            // i 這數字完全沒在 (rows[row][i], cols[col][i], boxes[ (row/3)*3 + col/3 ][i] ) 使用過
            board[row][col] = i + '1';

            //使用過要立為 true
            rows[row][i] = cols[col][i] = boxes[ (row/3)*3 + col/3 ][i] = true;

            if(backtrack(board, row, col)){
                return true;
            } else{
                board[row][col] = '.';
                rows[row][i] = cols[col][i] = boxes[ (row/3)*3 + col/3 ][i] = false;
            }
        }
        return false;
    }
};