/*******************************************************************
* https://leetcode.com/problems/next-permutation/
* Medium
* 
* Conception: 
*  1. 
*
* Implement next permutation,
* which rearranges numbers into the lexicographically next greater permutation of numbers.
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
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        //find the first decend number nums[i] < nums[i + 1]
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        
        
        // j = i, j++, find nums[j] > nums[i] << key
        if( i >= 0){
            int j =  nums.size() - 1;
            while( j >= 0 && nums[j] <= nums[i]){
                j--;
            }
            // swap nums[i] nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        // reverse(nums.begin() + i, nums.begin() + j)
        reverse(nums.begin() + i + 1, nums.end());
    }
};