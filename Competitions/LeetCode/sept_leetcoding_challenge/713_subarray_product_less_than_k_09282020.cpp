/*******************************************************************
* https://leetcode.com/problems/subarray-product-less-than-k/
* Medium
* 
* Conception: 
*  1. 
*
* Your are given an array of positive integers nums.
* Count and print the number of (contiguous) subarrays
* where the product of all the elements in the subarray is less than k.
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int start=0;
        int end=0;
        int p=1;
        int count=0;
        while(end<nums.size()){
            p*=nums[end];
            while(start<nums.size() and p>=k){
                p=p/nums[start];
                start++;
            }
            if(p<k)
            count+=end-start+1;
            end++;
        }
        return count;
    }
};