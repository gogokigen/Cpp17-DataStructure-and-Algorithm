/*******************************************************************
* https://leetcode.com/problems/binary-search/
* Easy
* 
* Conception: 
*  1. 
*
* Given a sorted (in ascending order) integer array nums of n elements 
* and a target value, write a function to search target in nums.
* If target exists, then return its index, otherwise return -1.
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
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }
            if (target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};