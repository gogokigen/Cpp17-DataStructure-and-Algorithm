/*******************************************************************
* https://leetcode.com/problems/3sum/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
* Find all unique triplets in the array which gives the sum of zero.
*
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/articles/3sum/
*
*******************************************************************/
class Solution {
private:
    void twoSum(vector<int>& nums, int i, vector<vector<int>> &res) {
        
        int left = i + 1;
        int len = nums.size();
        int right = len - 1;
        
        while(left < right){
            int sum = nums[i] + nums[right] + nums[left];
            if( sum < 0 || (left > i + 1 &&　nums[left] == nums[left - 1])){
                left++;
            }else if(sum > 0 || (right < len - 1 && nums[right] == nums[right + 1])){
                right--;
            }else{
                res.push_back({nums[i], nums[left++], nums[right--]});
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if( i == 0 || nums[i] != nums[i-1]){
                twoSum( nums, i, res);
            }
        }
        return res;
    }
};