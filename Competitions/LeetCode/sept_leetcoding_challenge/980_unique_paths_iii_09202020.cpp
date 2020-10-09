/*******************************************************************
* https://leetcode.com/problems/unique-paths-iii/
* Hard
* 
* Conception: 
*  1. 
*
* On a 2-dimensional grid, there are 4 types of squares:
*
*    1 represents the starting square.  There is exactly one starting square.
*    2 represents the ending square.  There is exactly one ending square.
*    0 represents empty squares we can walk over.
*    -1 represents obstacles that we cannot walk over.
*
* Return the number of 4-directional walks from the starting square to the ending square,
* that walk over every non-obstacle square exactly once.
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
    int sol = 0;
    void dfs(int x,int y,vector<vector<int>>& grid, int count,int total){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1){
            return;
        }
        if(grid[x][y] == 2 && total == count){
            sol++;
            return;
        }
        if(grid[x][y] == 2 && total != count)
            return;
        if(total >= count)
            return;
        grid[x][y]=-1;
        dfs( x+1, y, grid, count, total+1);
        dfs( x-1, y, grid, count, total+1);
        dfs( x, y+1, grid, count, total+1);
        dfs( x, y-1, grid, count, total+1);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=0;
        int x,y;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(grid[i][j] == 0)
                    count++;
            }
        }
        dfs(x,y,grid,count+1,0);
        return sol;
    }
};