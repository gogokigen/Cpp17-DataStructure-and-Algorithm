/*******************************************************************
* https://leetcode.com/problems/unique-paths-ii/
* Medium
* 
* Conception: 
*  1. 
*
* A robot is located at the top-left corner of a m x n grid
* (marked 'Start' in the diagram below).
*
* The robot can only move either down or right at any point in time.
* The robot is trying to reach the bottom-right corner of the grid
* (marked 'Finish' in the diagram below).
*
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
*
* Example:
*
* Key:
*  1. Notice "overflow"
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid.size() == 0||obstacleGrid[0][0] == 1) return 0;
        
        int l = obstacleGrid.size();
        int c = obstacleGrid[0].size();
            
        vector<vector<long>> visited(l , vector<long> (c, 0));

        visited[0][0] = 1;
        for(int j = 1; j < l; j++){
            if(obstacleGrid[j][0] == 0 && visited[j-1][0] == 1){
                visited[j][0] = 1;
            }else{
                visited[j][0] = 0;
            }
        }

        for(int i = 1; i < c; i++){
            if(obstacleGrid[0][i] == 0 && visited[0][i-1] == 1){
                visited[0][i] = 1;
            }else{
                visited[0][i] = 0;
            }
        }
        for(int j = 1; j < l; j++){
            for(int i = 1; i < c; i++){
                if(obstacleGrid[j][i] == 0){
                    visited[j][i] = visited[j-1][i]+visited[j][i-1];
                }else{
                    visited[j][i] = 0;
                }
            }
        }
        return visited[l-1][c-1];
    }
};