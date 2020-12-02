/*******************************************************************
* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
* Hard
* 
* Conception: 
*  1. 
*
* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
* (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
*
* Find the minimum element.
* The array may contain duplicates.
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
        
        while( l < r){
            int m = l + ( r - l)/2;
            
            if(nums[l] == nums[m] && nums[m] == nums[r]){
                l++;
                r--;
            } else if(nums[m] <= nums[r]){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};