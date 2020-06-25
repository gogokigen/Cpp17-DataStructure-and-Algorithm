/*******************************************************************
* https://leetcode.com/problems/find-the-duplicate-number/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
* prove that at least one duplicate number must exist.
* Assume that there is only one duplicate number, find the duplicate one.
*
* Example:
*
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
    int findDuplicate(vector<int>& nums) {
        set<int> cache;
        
        for(int& i:nums){
            if(cache.find(i) == cache.end()){
                cache.insert(i);
            }else{
                return i;
            }
        }
        return -1;
    }
};