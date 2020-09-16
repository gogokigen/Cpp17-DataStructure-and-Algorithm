/*******************************************************************
* https://leetcode.com/problems/maximum-product-subarray/
* Medium
* 
* Conception: 
*  1. 
*
* Given an integer array nums, find the contiguous subarray within an array
* (containing at least one number) which has the largest product.
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
    int maxProduct(vector<int>& nums) {
		// empty array case
		if (nums.size() == 0)
			return 0;
			
	    // maxSub and minSub will hold the products till nums[i]
        int maxSub = nums[0];   
        int minSub = nums[0];
        int maxProductSub = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++){
            // element is negative so we swap max and min
            // because when multiplying negative with a negative, number becomes positive so minimum negative number will become the maximum number
            if (nums[i] < 0){
                swap(minSub, maxSub);
            }
      
            // update all the sub values
			maxSub = max(maxSub * nums[i], nums[i]); 
            minSub = min(minSub * nums[i], nums[i]); 
            // choose max product to be the max between the maxProduct till now and maxSub
			maxProductSub = max(maxProductSub, maxSub); 
        }
		
        return maxProductSub;
    }
   
};