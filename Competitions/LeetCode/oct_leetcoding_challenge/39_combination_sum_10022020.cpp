/*******************************************************************
* https://leetcode.com/problems/combination-sum/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of distinct integers candidates and a target integer target,
* return a list of all unique combinations of candidates where the chosen numbers sum to target.
* You may return the combinations in any order.
*
* The same number may be chosen from candidates an unlimited number of times.
* Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*
* It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> current;
        backtrack(candidates, target, 0, current, combinations);
        return combinations;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) return;
        current.push_back(candidates[index]);
        backtrack(candidates, target - current.back(), index, current, combinations);
        current.pop_back();
        backtrack(candidates, target, index + 1, current, combinations);
    }
};