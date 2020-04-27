/*******************************************************************
* https://leetcode.com/problems/contains-duplicate/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of integers, find if the array contains any duplicates.
* Your function should return true if any value appears at least twice in the array,
* and it should return false if every element is distinct.
*
*
* Example:
*
* Key:
*  1. property of set
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return false;
        set<int> cache;

        for(int i = 0; i < nums.size(); i++){
            if(cache.find(nums[i]) != cache.end()){//exist
                return true;
            }else{
                cache.insert(nums[i]);
            }
        }
        return false;
    }
};