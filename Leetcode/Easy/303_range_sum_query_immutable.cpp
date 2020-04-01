/*******************************************************************
* https://leetcode.com/problems/range-sum-query-immutable/
* Easy
* 
* Conception: 
*  1. DP
*
* Given an integer array nums,
* find the sum of the elements between indices i and j (i ≤ j), inclusive.
*
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




// Method 1
class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for(auto x: nums){
            sum += x;
            dp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? dp[j] : dp[j] - dp[i - 1];
    }
    
private:
    vector<int>dp;
};


// Method 2
class NumArray {
public:
    vector<int> data = {0};
    
    NumArray(vector<int>& nums) {
        data = nums;
    }
    
    int sumRange(int i, int j) {
        int ret = 0;
        for(int k = i; k <= j ; k++){
            ret = ret+ data[k];
        }
        return ret;
    }
};