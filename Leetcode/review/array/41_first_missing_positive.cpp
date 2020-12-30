/*******************************************************************
* https://leetcode.com/problems/first-missing-positive/
* Hard
* 
* Conception: 
*  1. 
*
* Given an unsorted integer array, find the smallest missing positive integer.
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
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            if(l + 1 == nums[l]){
                l++;
            }else if(r + 1 == nums[r] || nums[r] <= 0 || nums[r] >= nums.size() || nums[nums[r] - 1] == nums[r]){
                r--;
            } else { 
                swap(nums[r], nums[nums[r] - 1]);
            }
        }
        while(l < nums.size() && l + 1 == nums[l]){
            l++;
        }
        return l + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited( n+1, false);

        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0 && nums[i] <= n){
                visited[nums[i]] = true;
            }
        }
        
        for(int i=1; i <= n; i++){
            if(visited[i] == false){
                return i;
            }
        }
        return n+1;
    }
};
