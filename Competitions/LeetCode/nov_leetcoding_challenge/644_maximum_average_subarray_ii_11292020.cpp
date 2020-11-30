/*******************************************************************
* https://leetcode.com/problems/maximum-average-subarray-ii/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an integer array nums consisting of n elements, and an integer k.
* Find a contiguous subarray whose length is greater than or equal to k 
* that has the maximum average value and return this value.
* Any answer with a calculation error less than 10-5 will be accepted.
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
    double findMaxAverage(vector<int>& nums, int k) {
        double res= -10000;
        int k2=k*2-1;
        vector<int> lsum (nums.size());
        lsum[0]=nums[0];
        for (int i=1;i<nums.size();++i){
            lsum [i] = lsum[i-1] +nums[i];
        }
        for(int i=0;i<nums.size();++i){
            for(int d=k; i+d<=nums.size()&&d <=k2; ++d){
                auto s = lsum[i+d-1];
                if (i>0) s -= lsum[i-1];
                if (res*d<=s) res = s*1.0/d;
            }
        }
        
        return res;
        
    }
};
