/*******************************************************************
* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
* Medium
* 
* Conception: 
*  1. 
*
* Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
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
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size() - 1;
        
        if (nums[r] > nums[0] || nums.size() == 1) {
          return nums[0];
        }
        while( l <= r){
            int m = l + ( r - l)/2;
            
            if(nums[m] > nums[m+1]){
                return nums[m+1];
            }
            
            if(nums[m-1] > nums[m]){
                return nums[m];
            }
            if(nums[m] > nums[0]){
                l = m + 1;
            }else {
                r = m - 1;
            }

        }
        return -1;
    }
};