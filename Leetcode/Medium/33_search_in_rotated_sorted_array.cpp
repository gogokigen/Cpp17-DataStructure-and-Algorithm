/*******************************************************************
* https://leetcode.com/problems/search-in-rotated-sorted-array/
* Medium
* 
* Conception: 
*  1. lon n --> binary search
*
* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
*
* (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
*
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* You may assume no duplicate exists in the array.
* Your algorithm's runtime complexity must be in the order of O(log n).
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
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] >= nums[left]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }else{
                if (target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;

    }
};