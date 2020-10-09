/*******************************************************************
* https://leetcode.com/problems/game-of-life/
* Medium
* 
* Conception: 
*  1. 
*
* According to the Wikipedia's article:
* "The Game of Life, also known simply as Life,
* is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
*
* Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
* Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
*
*    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
*    Any live cell with two or three live neighbors lives on to the next generation.
*    Any live cell with more than three live neighbors dies, as if by over-population..
*    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*
* Write a function to compute the next state (after one update) of the board given its current state.
* The next state is created by applying the above rules simultaneously to every cell in the current state,
* where births and deaths occur simultaneously.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    using Board = vector<vector<int>>;
    
    static int Rows(const Board &board) {
        return board.size();
    }
    
    static int Cols(const Board &board) {
        if (Rows(board) == 0) {
            return 0;
        }
        return board[0].size();
    }
    
    static int countNeighbors(const Board &board, int row, int col) {
        int rows = Rows(board);
        int cols = Cols(board);
        
        // the current state is stored in the first bit
        // exclude the starting cells count
        int count = -(board[row][col] & 1);
        for (int r = max(row - 1, 0); r <= min(row + 1, rows - 1); r++) {
            for (int c = max(col - 1, 0); c <= min(col + 1, cols - 1); c++) {                
                count += board[r][c] & 1;
            }
        }
        
        return count;
    }
    
    void gameOfLife(Board& board) {
        int rows = Rows(board);
        int cols = Cols(board);
        if (rows == 0 || cols == 0) {
            return;
        }
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int count = countNeighbors(board, row, col);
                bool alive = (board[row][col] & 1) == 1;
                
                if (alive && (count == 2 || count == 3) ||
                   (!alive && count == 3)) {
                    // store the next state in the second bit
                    board[row][col] |= 0b10;
                }
            }
        }
        
        // flip to the new state stored in the second bit
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                board[row][col] = (board[row][col] & 0b10) >> 1;
            }
        }
    }
};