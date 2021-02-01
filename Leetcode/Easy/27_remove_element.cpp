/*******************************************************************
* https://leetcode.com/problems/remove-element/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array nums and a value val,
* remove all instances of that value in-place and return the new length.
*
* Key:
*  1.
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int j = 0;

        for(int i = 0; i < len; i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
