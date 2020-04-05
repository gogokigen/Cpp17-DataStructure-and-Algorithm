/*******************************************************************
* https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
* Easy
* 
* Conception: 
*  1. sort
*  2. 
*
* Given the array nums, obtain a subsequence of the array
* whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 
*
* If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions,
* return the subsequence with the maximum total sum of all its elements.
* A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 
*
* Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.
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
class Solution {
public:
    int total_nums = 0;
    int total_subseq = 0;

    vector<int> minSubsequence(vector<int>& nums) {
        for(auto i:nums){
            total_nums+=i;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            total_subseq += nums[i];
            total_nums -= nums[i];
            ret.push_back(nums[i]);
            if(total_subseq > total_nums){
               return ret;
            }
        }

        return ret;
    }
};