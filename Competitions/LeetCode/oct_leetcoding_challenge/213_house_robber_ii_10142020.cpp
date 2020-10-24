/*******************************************************************
* https://leetcode.com/problems/house-robber-ii/
* Medium
* 
* Conception: 
*  1. 
*
* You are a professional robber planning to rob houses along a street.
* Each house has a certain amount of money stashed.
* All houses at this place are arranged in a circle.
* That means the first house is the neighbor of the last one.
* Meanwhile, adjacent houses have security system connected and it will automatically contact the police
* if two adjacent houses were broken into on the same night.
*
* Given a list of non-negative integers representing the amount of money of each house,
* determine the maximum amount of money you can rob tonight without alerting the police.
*
*
* Example:
*
*
* Key:
*  1. Since House[1] and House[n] are adjacent, they cannot be robbed together.
*     Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
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
        int curr_1 = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int tmp = curr_1;
            curr_1 = max(prev + nums[i], curr_1);
            prev = tmp;
        }

        prev = 0;
        int curr_2 = 0;
        for(int i = 1; i < nums.size(); i++){
            int tmp = curr_2;
            curr_2 = max(prev + nums[i], curr_2);
            prev = tmp;
        }
        
        return max(curr_1 , curr_2);

    }
};