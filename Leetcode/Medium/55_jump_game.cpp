/*******************************************************************
* https://leetcode.com/problems/jump-game/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of non-negative integers,
* you are initially positioned at the first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
* Determine if you are able to reach the last index.
*
*
* Example:
*
* Key:
*  1.
*
* Reference:
*  1. 
*
*******************************************************************/
​class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(i + nums[i]>= last){
                last = i;
            }
        }
        
        if(last != 0) return false;
        
        return true;
    }
};