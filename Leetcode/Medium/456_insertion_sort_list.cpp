/*******************************************************************
* https://leetcode.com/problems/insertion-sort-list/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of n integers nums,
* a 132 pattern is a subsequence of three integers
* nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
*
* Return true if there is a 132 pattern in nums, otherwise, return false.
*
* Follow up: The O(n^2) is trivial,
* could you come up with the O(n logn) or the O(n) solution?
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
    bool find132pattern(vector<int>& nums) {
        stack <int> stack;
        int second =  -2147483648;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums [i] < second)
                return true;

            while (stack.size() >0 && nums [i] > stack.top()){
                second = stack.top ();
                stack.pop();
            }
            stack.push (nums [i]);
        }
        return false;
    }
};