/*******************************************************************
* https://leetcode.com/problems/increasing-triplet-subsequence/
* Medium
* 
* Conception: 
*  1. 
*
* Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
* 
* Formally the function should:
*    Return true if there exists i, j, k
*    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
*
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
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return false;

        int first_split = INT_MAX;
        int second_split = INT_MAX;

        for(int& i:nums){
            if(first_split >= i){
                first_split = i;
            } else if(second_split >= i){
                second_split = i;
            } else {
                return true;
            }
        }
        return false;
    }
};