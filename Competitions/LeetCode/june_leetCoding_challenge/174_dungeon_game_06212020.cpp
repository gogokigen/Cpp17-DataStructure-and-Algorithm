/*******************************************************************
* https://leetcode.com/problems/dungeon-game/
* Hard
* 
* Conception: 
*  1. 
*
* The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
* The dungeon consists of M x N rooms laid out in a 2D grid.
* Our valiant knight (K) was initially positioned in the top-left room
* and must fight his way through the dungeon to rescue the princess.
*
* The knight has an initial health point represented by a positive integer.
* If at any point his health point drops to 0 or below, he dies immediately.
*
* Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
* other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
*
* In order to reach the princess as quickly as possible,
* the knight decides to move only rightward or downward in each step.
*
*
* Example:
*
* Key:
*  1.
*
* References:
*  1. https://leetcode.com/problems/permutation-sequence/discuss/696595/C++-or-Very-Easy-and-Detailed-Explanation-(Idea-+-code)
*
*******************************************************************/
class Solution {
private:
    int inf = INT_MAX;
    int rows = 0;
    int cols = 0;
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        this->rows = row;
        this->cols = col;
        vector<vector<int>> dp(row, vector<int> (col, inf));
        int currCell = 0, rightHealth = 0, downHealth = 0, nextHealth = 0, minHealth = 0;
        
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                currCell = dungeon[i][j];
                rightHealth = getMinHealth(dp, currCell, i, j + 1);
                downHealth = getMinHealth(dp, currCell, i + 1, j);
                nextHealth = min( rightHealth, downHealth);
                if(nextHealth != inf){
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }
                dp[i][j] = minHealth;
            }
        }
        return dp[0][0];
    }
    
    int getMinHealth(vector<vector<int>>& dp, int currCell, int nextRow, int nextCol){
        if (nextRow >= rows || nextCol >= cols){
            return inf;
        }
        int nextCell = dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return max(1, nextCell - currCell);
    }
};