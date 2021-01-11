/*******************************************************************
* https://leetcode.com/problems/longest-increasing-subsequence/
* Medium
* 
* Conception: 
*  1. 
*
* Given an integer array nums,
* return the length of the longest strictly increasing subsequence.
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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;

        vector<int> dp(nums.size(), 0);

        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < dp.size(); i++){
            int maxVal = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] = maxVal + 1;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
