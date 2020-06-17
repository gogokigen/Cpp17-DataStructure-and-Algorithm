/*******************************************************************
* https://leetcode.com/problems/surrounded-regions/
* Medium
* 
* Conception: 
*  1. 
*
* Given a 2D board containing 'X' and 'O' (the letter O),
* capture all regions surrounded by 'X'.
*
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
*
*
* Example:
*
*
* Key:
*  1.
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
private:
    int rows = 0;
    int cols = 0;
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;

        rows = board.size();
        cols = board[0].size();
        
        vector<pair<int,int>> borders;
        for(int i = 0; i < rows; i++){
            borders.push_back(make_pair(i,0));
            borders.push_back(make_pair(i,cols - 1));
        }
        for(int j = 0; j < cols; j++){
            borders.push_back(make_pair(0,j));
            borders.push_back(make_pair(rows - 1, j));
        }
        
        for(auto b:borders){
            DFS(board, b.first, b.second);
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j){
        if(i < 0|| i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] != 'O') return;
        
        board[i][j] = 'E';

        if(j < cols + 1){
            DFS(board, i, j + 1);
        }
        if(i < rows - 1){
            DFS(board, i + 1, j);
        }
        if( j > 0){
            DFS(board, i, j - 1);
        }
        if( i > 0){
            DFS(board, i - 1, j);
        }
    }
    
};