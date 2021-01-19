/*******************************************************************
* https://leetcode.com/problems/remove-duplicates-from-sorted-array/
* Easy
* 
* Conception: 
*  1. 
*
* Given a sorted array nums, remove the duplicates in-place
* such that each element appear only once and return the new length.
*
* Do not allocate extra space for another array,
* you must do this by modifying the input array in-place with O(1) extra memory.
*
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                //save to nums[i+1]
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};