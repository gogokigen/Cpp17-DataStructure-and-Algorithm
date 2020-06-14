/*******************************************************************
* https://leetcode.com/problems/largest-divisible-subset/
* Medium
* 
* Conception: 
*  1. 
*
* Given a set of distinct positive integers,
* find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
*
* Si % Sj = 0 or Sj % Si = 0.
*
* If there are multiple solutions, return any subset is fine.
*
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/largest-divisible-subset/discuss/684783/C++-Crystal-Clear-Explanation
*
*******************************************************************/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return {};

        //saving the divisor's quantity
        vector<int> dp(len,1);
        // saving the last divisor's index
        vector<int> pre_index(len,-1);
        
        // saving max divised number
        int max_idx = 0;
        
        sort(nums.begin(), nums.end());

        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre_index[i] = j;
                }
            }
            if(dp[i] > dp[max_idx]){
                max_idx = i;
            }
        }
        
        // tracking back
        vector<int> ans;
        int t = max_idx;
        while(t >= 0){
            ans.push_back(nums[t]);
            t = pre_index[t];
        }
        return ans;
    }
};