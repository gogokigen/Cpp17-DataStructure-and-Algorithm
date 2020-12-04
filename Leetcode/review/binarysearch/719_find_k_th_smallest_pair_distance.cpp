/*******************************************************************
* https://leetcode.com/problems/find-k-th-smallest-pair-distance/
* Hard
* 
* Conception: 
*  1. 
*
* Given an integer array, return the k-th smallest distance among all the pairs.
* The distance of a pair (A, B) is defined as the absolute difference between A and B. 
*
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi){
                    left++;
                }
                count += right - left;
            }

            //count = number of pairs with distance <= mi
            if (count >= k){
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
