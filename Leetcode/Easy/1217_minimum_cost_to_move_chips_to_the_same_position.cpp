/*******************************************************************
* https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
* Easy
* 
* Conception: 
*  1. 
*
* We have n chips, where the position of the ith chip is position[i].
* We need to move all the chips to the same position. In one step,
* we can change the position of the ith chip from position[i] to:
*    position[i] + 2 or position[i] - 2 with cost = 0.
*    position[i] + 1 or position[i] - 1 with cost = 1.
*
* Return the minimum cost needed to move all the chips to the same position.
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
    int minCostToMoveChips(vector<int>& position) {
        int count = 0;
        int size = position.size();
        for(int i=0;i<size;i++){
            if(position[i]%2!=0){
                count++;
            }
        }
        return min(count,size-count);
    }
};