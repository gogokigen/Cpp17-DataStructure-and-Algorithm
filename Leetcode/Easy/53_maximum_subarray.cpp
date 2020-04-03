/*******************************************************************
* https://leetcode.com/problems/maximum-subarray/
* Easy
* 
* Conception: 
*  1. 
*
* Given an integer array nums, 
* find the contiguous subarray (containing at least one number) 
* which has the largest sum and return its sum.
*
*
* Example:
*
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

    // Method 1: Brute
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
        int n = nums.size();
        int ret = INT_MIN;
        
        for(int j = 0; j < n ; j++){

            if(nums[j] > ret){
                ret = nums[j];
            }
            vector<int> dp(n,0);
            dp[j] = nums[j];
            for (int i = j + 1; i < n; i++) {
                dp[i] = dp[i-1] + nums[i];
                if(dp[i] > ret){
                    ret = dp[i];
                }
            }
        }
        
        return ret;
    }
    
    //Method 2: Greddy
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        int n = nums.size();
        int currSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < n; ++i) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
     }
};