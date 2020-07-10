/*******************************************************************
* https://leetcode.com/problems/find-pivot-index/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of integers nums,
* write a method that returns the "pivot" index of this array.
*
* We define the pivot index as the index where the sum of all the numbers
* to the left of the index is equal to the sum of all the numbers to the right of the index.
*
* If no such index exists, we should return -1.
* If there are multiple pivot indexes, you should return the left-most pivot index.
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
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int& i:nums){
            sum += i;
        }

        int len = nums.size();
        int subsum = 0;
        for(int i = 0; i < len; i++){
            if(sum - nums[i] == subsum*2){
                return i;
            }
            subsum += nums[i];
        }
        return -1;
    }
};