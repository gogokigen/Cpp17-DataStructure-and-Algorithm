/*******************************************************************
* https://leetcode.com/problems/single-element-in-a-sorted-array/
* Medium
* 
* Conception: 
*  1. 
*
* You are given a sorted array consisting of only integers where every element appears exactly twice,
* except for one element which appears exactly once. Find this single element that appears only onc
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
private:
    void helper(vector<int>& nums, int & ret, int left, int right){
        if(left == right){
            ret = nums[left];
            return;
        }
        
        int mid = left + (right - left) /2;
        
        if(mid%2 == 0){//total is odd
            if(nums[mid + 1] == nums[mid]){
                helper(nums, ret, mid + 2, right);
            }else{
                helper(nums, ret, left, mid);
            }
        }else{
            if(nums[mid - 1] == nums[mid]){
                helper(nums, ret, mid + 1, right);
            }else{
                helper(nums, ret, left, mid);
            }
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = -1;
        helper(nums, ret, 0 , nums.size()-1);
        return ret;
    }
};