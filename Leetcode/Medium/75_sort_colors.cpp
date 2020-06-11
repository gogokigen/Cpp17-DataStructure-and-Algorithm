/*******************************************************************
* https://leetcode.com/problems/sort-colors/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array with n objects colored red, white or blue,
* sort them in-place so that objects of the same color are adjacent,
* with the colors in the order red, white and blue.
*
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
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
    void sortColors(vector<int>& nums) {
        int left = 0;
        int curr = 0;
        int right = nums.size() - 1;
        
        while( curr <= right){
            if(nums[curr] == 2){
                swap(nums[curr],nums[right]);
                right--;
            }else if(nums[curr] == 0) {
                swap(nums[curr],nums[left]);
                curr++;
                left++;
            }else{
                curr++;
            }
            
        }
    }
};