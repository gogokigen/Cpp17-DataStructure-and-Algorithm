/*******************************************************************
* https://leetcode.com/problems/search-insert-position/
* Easy
* 
* Conception: 
*  1. 
*
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*
* You may assume no duplicates in the array.
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
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m = 0;

        while(l <= r){
            m =  l + ( r - l)/2;
            if(nums[m] == target){
                return m;
            } else if ( nums [m] > target) {
                r= m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] >= target){
                return i;
            }
        }
        return len;
    }
};
