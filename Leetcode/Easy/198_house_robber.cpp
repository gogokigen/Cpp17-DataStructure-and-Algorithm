/*******************************************************************
* https://leetcode.com/problems/house-robber/
* Easy
* 
* Conception: 
*  1. 
*
* You are a professional robber planning to rob houses along a street.
* Each house has a certain amount of money stashed,
* the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
* it will automatically contact the police if two adjacent houses were broken into on the same night.
*
* Given a list of non-negative integers representing the amount of money of each house,
* determine the maximum amount of money you can rob tonight without alerting the police.
*
*
* Example:
*
*
* Key:
*  1. f(k) = Largest amount that you can rob from the first k houses.
*     Ai = Amount of money at the ith house.
*
*     f(k) = max(f(k – 2) + Ak, f(k – 1))
*
* Advanced:
*  1. 
*
*******************************************************************/
#include<algorithm> 
using namespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[0]:nums[1];

        int prev = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            int tmp = curr;
            curr = std::max(prev + nums[i], curr);
            prev = tmp;
        }
        return curr;
    }
};