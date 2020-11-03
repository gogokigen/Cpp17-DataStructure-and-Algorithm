/*******************************************************************
* https://leetcode.com/problems/subsets/
* Medium
* 
* Conception: 
*  1. backtracking
*
* Given a set of distinct integers, nums,
* return all possible subsets (the power set).
*
* Note: The solution set must not contain duplicate subsets.
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<int>& selected, int pos, int len, int itr){
        result.push_back(selected);
        
        if( pos == len){
            return;
        }
        
        for(int i = itr; i < len; i++){
            int val = nums[i];
            if(find(selected.begin(), selected.end(), val) != selected.end()){
                continue;
            }
            selected.push_back(val);
            helper(nums, selected, pos + 1, len, i);
            selected.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> selected;
        helper(nums, selected, 0, len, 0);
        return result;
    }
};
