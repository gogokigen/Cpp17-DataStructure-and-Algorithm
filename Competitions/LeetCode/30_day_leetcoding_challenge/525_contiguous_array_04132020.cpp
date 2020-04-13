/*******************************************************************
* https://leetcode.com/problems/contiguous-array/
* Medium
* 
* Conception: 
*  1. 
*
* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*
*
* Example:
*
*
* Key:
*  1. if tbl[i] == tbl[j], then the number of 0 is equal to the number of 1
*     [0 , 0, 0, 1, 0]
*      -1,-2,-3,-2,-3
*          ^     ^   -->> length = 3 - 1
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, sum = 0;
        unordered_map<int,int> tbl{{0,-1}};
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1:-1;
            if(tbl.count(sum)){
                ans = max(ans, i - tbl[sum]);
            }else{
                tbl[sum] = i;
            }
        }
        return ans;
    }
};