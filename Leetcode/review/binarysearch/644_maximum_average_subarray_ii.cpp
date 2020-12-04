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
*  1. https://leetcode.com/problems/maximum-average-subarray-ii/discuss/953784/C%2B%2B-Binary-Search-(modification-based-on-official-solution)
*
*******************************************************************/
class Solution {
private:
    bool check_bigger(vector<int>& nums, int k, double mid){
        //check [n_0 + ... + n_j]/j >= mid
        double sums = 0, pre_sums = 0;
        double min_pre_sums = 0; 
        for(int i = 0; i < k; i++){
            sums += nums[i] - mid;
        }

        if( sums >= 0) return true;

        for(int j = k; j < nums.size(); j++){
            sums += nums[j] - mid;
            pre_sums += nums[j - k] - mid;
            min_pre_sums = min(min_pre_sums, pre_sums);
            if(sums - min_pre_sums >= 0){
                return true;
            }
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        double min = *min_element(nums.begin(), nums.end());
        double max = *max_element(nums.begin(), nums.end());
        double error = INT_MAX, pre_mid = max;

        while(error > 0.000001){
            double mid = (max + min)/2;
            if(check_bigger(nums, k, mid)){
                min = mid;
            }else{
                max = mid;
            }
            error = abs(pre_mid - mid);
            pre_mid = mid;
        }
        return min;
    }
};