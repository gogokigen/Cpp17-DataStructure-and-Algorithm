/*******************************************************************
* https://leetcode.com/problems/squares-of-a-sorted-array/
* Easy
* 
* Conception: 
*  1. 
*
* Given an integer array nums sorted in non-decreasing order,
* return an array of the squares of each number sorted in non-decreasing order.
*
* Example:
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        // find the first positive number
        int len = nums.size();
        
        if (len == 1) return {nums[0] * nums[0]};
        int r = len;
        int l = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] > 0){
                r = i;
                break;
            }
        }
        l = r - 1;

        vector<int> ans;
        while (l >= 0 && r < len) {
            if (nums[l] * nums[l] < nums[r] * nums[r]) {
                ans.push_back(nums[l] * nums[l]);
                l--;
            } else {
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while (l >= 0) {
            ans.push_back(nums[l]* nums[l]);
            l--;
        }
        while (r < len) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }
        return ans;
    }
};
