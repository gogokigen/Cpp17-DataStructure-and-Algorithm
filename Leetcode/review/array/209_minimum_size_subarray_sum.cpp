/*******************************************************************
* https://leetcode.com/problems/minimum-size-subarray-sum/
* Medium
* 
* Conception: 
*  1. 
*
* YGiven an array of n positive integers and a positive integer s,
* find the minimal length of a contiguous subarray of which the sum ≥ s.
* If there isn't one, return 0 instead.
*
*
* Example:
*
* Key:
*  1. window slicing
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int targetSum = 0, start = 0;
        int len = nums.size();
        
        int winSize = INT_MAX;
        for(int end = 0; end < len; end++){
            targetSum += nums[end];
            
            while(targetSum >= s){
                winSize = min(winSize, end - start + 1);
                targetSum -= nums[start];
                start++;
            }
        }
        return winSize == INT_MAX ? 0 : winSize;
    }
};
