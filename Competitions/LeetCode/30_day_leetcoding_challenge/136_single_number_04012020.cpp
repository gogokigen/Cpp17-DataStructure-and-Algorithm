/*******************************************************************
* https://leetcode.com/problems/single-number/
* Easy
* 
* Conception: 
*  1. XOR
*
* Given a non-empty array of integers,
* every element appears twice except for one. Find that single one.
*
*
* Example:
* Input: [4,1,2,1,2]
* Output: 4
* Explanation:

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
    int singleNumber(vector<int>& nums) {
        int ans;
        for(int i = 0; i < nums.size(); i++){
           ans ^=nums[i];
        }
        return ans;
    }
};