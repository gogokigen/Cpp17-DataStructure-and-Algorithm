/*******************************************************************
* https://leetcode.com/problems/n-queens/
* Hard
* 
* Conception: 
*  1. 
*
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard
* such that no two queens attack each other.
*
* Given an integer n, return all distinct solutions to the n-queens puzzle.
*
* Each solution contains a distinct board configuration of the n-queens' placement,
* where 'Q' and '.' both indicate a queen and an empty space respectively.
*
*
* Example:
*
* Key:
*  1. backtracking
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe( vector<vector<char>>&board, int row, int col, int n){
        for(int i = 0; i < n; i++){
            if(board[row][i] == 'Q')
                return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row, j = col; i < n && j >= 0; i++, j--){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    bool NQueensUtil(vector<vector<char>>&board, int n, int col){
        if(col == n){
            vector<string> v;
            for(int i = 0; i < n; i++){
                string str = "";
                for(int j = 0; j < col; j++){
                    str += board[i][j];
                }
                v.push_back(str);
            }
            ans.push_back(v);
            return true;
        }
        bool res = false;
        for(int i = 0; i < n; i++){
            if(isSafe( board, i, col, n)){
                board[i][col] = 'Q';
                res = ( NQueensUtil( board, n, col + 1) || res);
                board[i][col] = '.';
            }
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<vector<char>>board(n, vector<char>(n,'.'));

        NQueensUtil(board, n, 0);
        return ans;
    }
};