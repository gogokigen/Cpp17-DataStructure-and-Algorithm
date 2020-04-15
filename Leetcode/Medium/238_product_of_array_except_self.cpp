/*******************************************************************
* https://leetcode.com/problems/product-of-array-except-self/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array nums of n integers where n > 1,
* return an array output such that output[i] is equal to
* the product of all the elements of nums except nums[i].
*
* Please solve it without division and in O(n).
*
*
* Explanation:
* nums = [      1 ,      2,    3,     4,       5]
* temp = [      1 ,      1,  1x2, 1x2x3, 1x2x3x4]
* anws = [      1 ,      1,  1x2, 1x2x3, 1x2x3x4
*         x5x4x3x2, x5x4x3, x5x4,    x5,        ]
*
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> cache(len,1);
        int pre = nums[0];
        for(int i = 1; i < len; i++){ 
            cache[i] = pre;
            pre = pre * nums[i];
        }
        
        int back = nums[len-1];
        for(int i = len - 2; i >= 0; i--){
            cache[i] = cache[i] * back;
            back = back * nums[i];
        }
        return cache;
    }
};