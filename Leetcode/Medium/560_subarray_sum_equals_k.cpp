/*******************************************************************
* https://leetcode.com/problems/subarray-sum-equals-k/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of integers and an integer k,
* you need to find the total number of continuous subarrays whose sum equals to k.
*
* Example:
*
* Key:
*  1. continuous is not necessary
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:

//Method 1: O(n^2)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int ret = 0;
        vector<int> tbl(n, 0);
        tbl[1] = nums[0];
        if(tbl[0] == k) ret++;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                tbl[j] = tbl[j] + nums[i];
                //cout << tbl[j] << endl;
                if(tbl[j] == k){
                    ret++;
                }
            }
        }
        return ret;
    }


//Method 2: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int sum_times = 0;
        int sum = 0;
        map<int,int> tbl; //sum, sum times
        tbl[0] = 1;

        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            if(tbl.find(sum - k) != tbl.end()){
                sum_times = sum_times + tbl.at(sum - k);
            }

            tbl[sum] = tbl[sum] + 1;
        }
        return sum_times;
    }
};