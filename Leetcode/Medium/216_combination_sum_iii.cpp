/*******************************************************************
* https://leetcode.com/problems/combination-sum-iii/
* Medium
* 
* Conception: 
*  1. 
*
* Find all possible combinations of k numbers that add up to a number n,
* given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
* Note:
*    The solution set must not contain duplicate combinations.
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
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n, {});
        
        return ans;
    }
    
    void dfs(int i, int k, int n, vector<int> arr) {
        if (k == 1 && n <= 9 && i <= n) {
            arr.push_back(n);
            ans.push_back(arr);
            return;
        }
        
        if (i > n) {
            return;
        }
        
        for (int j = i; j <= 9; ++j) {
            arr.push_back(j);
            dfs(j + 1, k - 1, n - j, arr);
            arr.pop_back();
        }
    }
};