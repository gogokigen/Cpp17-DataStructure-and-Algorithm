/*******************************************************************
* https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
* Hard
* 
* Conception: 
*  1.
*
* Given an integer matrix, find the length of the longest increasing path.
* From each cell, you can either move to four directions: left, right, up or down.
* You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
*
*
* Example:
* 
*
* Key:
*  1. DFS + DP
*
* References:
*  1. https://www.youtube.com/watch?v=yKr4iyQnBpY
*
*******************************************************************/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        row = matrix.size();
        col = matrix[0].size();
        int ret = 0;
        dp = vector<vector<int>>(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ret = max(ret, dfs(matrix, j, i));
            }
        }
        return ret;
    }
private:
    vector<vector<int>> dp;
    int row;
    int col;
    int dfs(vector<vector<int>>& matrix, int x , int y){
        if(dp[y][x] != -1) return dp[y][x];

        const int dir[] = { 0, -1, 0, 1, 0};
        dp[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int next_x = x + dir[i];
            int next_y = y + dir[i + 1];
            if( 0 <= next_x && 0 <= next_y && next_x < col && next_y < row && matrix[next_y][next_x] > matrix[y][x]){
                dp[y][x] = max( dp[y][x],  1 + dfs(matrix, next_x, next_y));
            }
        }
        return dp[y][x];
    }
};