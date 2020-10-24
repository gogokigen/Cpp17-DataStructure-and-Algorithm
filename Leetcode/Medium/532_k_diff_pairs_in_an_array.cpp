/*******************************************************************
* https://leetcode.com/problems/k-diff-pairs-in-an-array/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
*
* A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
*    0 <= i, j < nums.length
*    i != j
*    |nums[i] - nums[j]| == k
*
* Notice that |val| denotes the absolute value of val.
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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x] += 1;
        int ans = 0;
        for (auto pair : cnt) {
            int b = pair.first;
            if ((k > 0 && cnt.count(b - k)) || (k == 0 && cnt[b] >= 2))
                ans += 1;
        }
        return ans;
    }
};