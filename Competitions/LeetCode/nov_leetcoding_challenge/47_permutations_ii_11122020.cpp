/*******************************************************************
* https://leetcode.com/problems/permutations-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given a collection of numbers, nums, that might contain duplicates,
* return all possible unique permutations in any order.
*
*
* Example:
*
* Key:
*  1. Backtracking
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    void Solve(vector<vector<int>>&ans,vector<int>&nums,int start){
        if(start+1 == nums.size()){
            ans.push_back(nums);
            return ;
        }

        unordered_map<int,int>mp;
        for(int i=start;i<nums.size();i++){
            if(mp.count(nums[i])){
                continue;
            }

            mp[nums[i]]=1;
            swap(nums[start],nums[i]);
            Solve(ans,nums,start+1);
            swap(nums[start],nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        Solve(ans,nums,0);
        return ans;
    }
};