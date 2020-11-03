/*******************************************************************
* https://leetcode.com/problems/permutations/
* Medium
* 
* Conception: 
*  1. backtracking
*
* Given a collection of distinct integers,
* return all possible permutations.
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
    void helper(vector<int>& nums, vector<int>& selected, int pos, int len){
        
        if( pos == len){
            result.push_back(selected);
            return;
        }
        
        for(int i = 0; i < len; i++){
            int val = nums[i];
            if(find(selected.begin(), selected.end(), val) != selected.end()){
                continue;
            }
            selected.push_back(val);
            helper(nums, selected, pos + 1, len);
            selected.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> selected;
        helper(nums, selected, 0, len);
        return result;
    }
};
