/*******************************************************************
* https://leetcode.com/problems/minimum-path-sum/
* Medium
* 
* Conception: 
*  1. 
*
* Given a m x n grid filled with non-negative numbers,
* find a path from top left to bottom right
* which minimizes the sum of all numbers along its path.
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        
        int l = grid.size();
        int c = grid[0].size();
            
        vector<vector<long>> visited(l , vector<long> (c, 0));
        visited[0][0] = grid[0][0];
        
        for(int j = 1; j < l; j++){
            visited[j][0] = visited[j-1][0] + grid[j][0];
        }

        for(int i = 1; i < c; i++){
            visited[0][i] = visited[0][i-1] + grid[0][i];
        }

        for(int j = 1; j < l; j++){
            for(int i = 1; i < c; i++){
                visited[j][i] = grid[j][i]+ min(visited[j][i-1], visited[j-1][i]);
            }
        }
        return visited[l-1][c-1];
    }
};